$(document).ready(function () {
  // Gan cac su kien cho cac element
  initEvent();
  // Lay du lieu
  loadData();
});

var act = null;
var employeeSelected = null;

/**
 * Lay du lieu tu API
 * Author: Nguyen Van Thinh
 */
// Tải dữ liệu
function loadData() {
  // Lay pageSize
  
    
  debugger;
  // Goi API filter
  try {
    $.ajax({
      type: "GET",
      async: false,
      url: "http://localhost:9074/api/v1/Employees/",
      success: function (employees) {
        console.log("Loading...");

        // Xu ly du lieu
        let cols = $(".table-header div");
        for (const employee of employees) {
          let rowOfTable = $('<div class="row"></div>');
          for (const col of cols) {
            // Lay ra propValue tương ứng với các cột:
            const propValue = $(col).attr("propValue");
            // Lay ra format tương ứng với các cột
            const format = $(col).attr("format");
            // Lay thong tin
            let value = employee[propValue];
            // Dinh dang (Ngay sinh, Gioi tinh, Muc luong co ban)
            if (value) {
              switch (format) {
                // Chuyen doi tu so ve chuoi cho gender va workStatus
                case "gender": {
                  value = value.toString();
                  const options = $("#gender option");
                  for (const opt of options) {
                    const optValue = $(opt).attr("value");
                    if (optValue == value) {
                      value = $(opt).attr("label");
                      break;
                    }
                  }
                  break;
                }
                case "workStatus": {
                  value = value.toString();
                  const options = $("#workStatus option");
                  for (const opt of options) {
                    const optValue = $(opt).attr("value");
                    if (optValue == value) {
                      value = $(opt).attr("label");
                      break;
                    }
                  }
                  break;
                }
                case "date":
                  value = formatDate(value);
                  break;
                case "money":
                  value = Math.round(value);
                  value = formatMoney(value);
                  break;
                default:
                  break;
              }
            }
            // Tạo rowHTML:
            const thHTML = `<div class='${propValue}'>${value || ""}</div>`;
            rowOfTable.append(thHTML);
          }
          $(rowOfTable).data("entity", employee); // init data() of row
          $(".table-info").append(rowOfTable);
        }
      },
    });
  } catch (error) {
    errorMessage("Có lỗi xảy ra", error);
  }
}

/**
 * Tao cac su kien
 * Author: Nguyen Van Thinh
 * Form luôn mặc định focus vào ô nhập liệu Mã nhân viên
 */

function initEvent() {
  // click nut them moi nhan vien
  $(".icon-add").click(function () {
    act = "create";
    // Hien thi pop-up
    $("#newEmployee").show();

    // Lam sach cac o inputs
    const inputs = $("#newEmployee select, #newEmployee input");
    for (const input of inputs) {
      input.value = "";
    }

    // Ngày sinh/ Ngày cấp/ Ngày gia nhập công ty nho hon hoang bang ngày hiện tại
    $("input[date]").attr("max", limitDate());

    // Mã nhân viên tự động có và tự tăng theo tiêu chí: “NV” + mã số nhân viên lớn nhất trong hệ thống + 1
    $.ajax({
      type: "GET",
      url: "https://cukcuk.manhnv.net/api/v1/Employees/NewEmployeeCode",
      success: function (response) {
        $("#employeeCode").val(response);
      },
    });

    // Focus vào ô nhập liệu Mã nhân viên
    $("#newEmployee input")[0].focus();

    // thay doi mau khung khi o thong tin can nhap bi bo qua
    $("input[mandatory]").blur(function () {
      let value = this.value;
      if (!value) {
        $(this).addClass("input-err");
        $(this).attr("title", "Thông tin bắt buộc");
      } else {
        $(this).removeClass("input-err");
        $(this).removeAttr("title");
      }
    });

    // Email phải đúng định dạng (VD: example@domain.com)
    $("input[email]").blur(function () {
      let email = this.value;
      if (!checkEmailFormat(email)) {
        $(this).addClass("input-err");
        $(this).attr("title", "Sai định dạng");
      } else {
        $(this).removeClass("input-err");
        $(this).removeAttr("title");
      }
    });
  });

  // click vao nut lam moi
  $("#btnRefresh").click(function () {
    loadData();
  });

  // click vao nut nhan ban
  $(".icon-duplicate").click(duplicateData);

  // click vao nut xoa
  $(".icon-remove").click(function () {
    if (!employeeSelected) return;
    $("#warning").show();
    $("#warning .dialog_text").empty();
    let txt = `Bạn có chắc chắn muốn xóa nhân viên <b>${employeeSelected.employeeCode}</b> không?`;
    $("#warning .dialog_text").append(txt);
  });

  // click vao nut "Co"
  $("#btnOK").click(deleteData);

  // click vao 1 dong trong bang
  $(document).on("click", ".table-info .row", function () {
    $(this).siblings().removeClass("row-selected");
    $(this).addClass("row-selected");
    employeeSelected = $(this).data().entity;
  });

  // double click vao 1 dong trong bang
  $(document).on("dblclick", ".table-info .row", function () {
    act = "modify";
    $("#newEmployee").show();
    $("#employeeCode").focus();
    // Dữ liệu nhân viên cần sửa sẽ tự động được điền vào các ô dữ liệu tương ứng.
    const employee = $(this).data().entity;
    const inputs = $("#newEmployee select, #newEmployee input");
    for (const input of inputs) {
      const propValue = $(input).attr("propValue");
      if (
        propValue == "IdentityDate" ||
        propValue == "JoinDate" ||
        propValue == "DateOfBirth"
      )
        input.value = "2022-09-08";
      else input.value = employee[propValue];
    }
  });

  // click nut x
  $(".pop-up__background .icon-x").click(function () {
    $(this).parents(".pop-up__background").hide();
  });

  $(".toast .icon-x").click(function () {
    $(this).parents(".toast").hide();
  });

  // click nut luu
  $(".icon-save").click(saveData);

  // click nut cancel
  $(".button-cancel").click(function () {
    $(this).parents(".pop-up__background").hide();
  });

  // click vao so trang
  $(".page-number button").click(function () {
    $(this).siblings().removeClass("page-number--selected");
    $(this).addClass("page-number--selected");
    employeeSelected = $(this).data().entity;
  });

  // Validate
  function checkEmailFormat(email) {
    const re =
      /^(([^<>()[\]\.,;:\s@\"]+(\.[^<>()[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i;
    return email.match(re);
  }

  // Gioi han ngay nhap
  function limitDate() {
    let today = new Date();
    let dd = today.getDate();
    let mm = today.getMonth() + 1; //January is 0!
    let yyyy = today.getFullYear();

    if (dd < 10) {
      dd = "0" + dd;
    }

    if (mm < 10) {
      mm = "0" + mm;
    }

    today = yyyy + "-" + mm + "-" + dd;
    return today;
  }
}

/**
 * Hàm thực thi
 * Comment: Thực hiện tính năng
 */
// Luu nhan vien vao database
function saveData() {
  // Thu thap du lieu
  let employee = {};
  const inputs = $("#newEmployee select, #newEmployee input");
  for (const input of inputs) {
    let val = input.value;
    const propValue = $(input).attr("propValue");
    employee[propValue] = val ? val : "";
  }

  employee["createdBy"] = "";
  employee["modifiedBy"] = "";
  if (employee.dateOfBirth == "") delete employee.dateOfBirth;
  if (employee.identityIssuedDate == "") delete employee.identityIssuedDate;
  if (employee.gender == "") delete employee.gender;
  if (employee.workStatus == "") delete employee.workStatus;
  if (employee.salary == "") delete employee.salary;

  employee = JSON.stringify(employee);
  // Kiem tra tinh dung dan cua du lieu
  if (
    !employee.employeeCode ||
    !employee.fullName ||
    !employee.identityNumber ||
    !employee.email ||
    !employee.phoneNumber
  ) {
    errorMessage("Điền thiếu thông tin bắt buộc");
    const inputs = $("input[mandatory]");
    for (const input of inputs) {
      const value = input.value;
      if (!value) {
        $(input).addClass("input-err");
        $(input).attr("title", "Thông tin bắt buộc");
      } else {
        $(input).removeClass("input-err");
        $(input).removeAttr("title");
      }
    }
    return;
  }
  // Goi API
  if (act == "create") {
    try {
      $.ajax({
        type: "POST",
        url: "http://localhost:9074/api/v1/Employees/",
        data: employee,
        dataType: "json",
        contentType: "application/json",
        success: function (response) {
          successMessage(`Thêm mới thành công`);
        },
      });
    } catch (error) {
      errorMessage("Có lỗi xảy ra", error);
    }
  } else {
    try {
      $.ajax({
        type: "PUT",
        url:
          "http://localhost:9074/api/v1/Employees/" +
          employeeSelected.employeeID,
        data: employee,
        dataType: "json",
        contentType: "application/json",
        success: function (response) {
          successMessage(`Chỉnh sửa thành công`);
        },
      });
    } catch (error) {
      errorMessage("Có lỗi xảy ra", error);
    }
  }
  $(this).parents(".pop-up__background").hide();
  loadData();
}

// Tính năng Nhân bản
function duplicateData() {
  act = "create";
  if (!employeeSelected) return;
  // Hien thi pop-up
  $("#newEmployee").show();
  // Thu thap thong tin
  const inputs = $("#newEmployee select, #newEmployee input");
  for (const input of inputs) {
    const propValue = $(input).attr("propValue");
    input.value = employeeSelected[propValue];
  }
  deleteData();
}

// Xoa nhan vien khoi database
function deleteData() {
  // Goi API DELETE
  try {
    $.ajax({
      type: "DELETE",
      url:
        "http://localhost:9074/api/v1/Employees/" + employeeSelected.employeeID,
      success: function (response) {
        successMessage("Xóa thành công");
      },
    });
  } catch (error) {
    errorMessage("Có lỗi xảy ra", error);
  }

  // An pop-up
  $("#warning").hide();
}

/**
 * Hàm định dạng dữ liệu
 */

// Dinh dang hien thi ngay/thang/nam
function formatDate(date) {
  try {
    if (date) {
      date = new Date(date);
      // Lay ngay
      const year = date.getFullYear();
      if (year == 1) return null;
      let day = date.getDate();
      day = day <= 9 ? `0${day}` : day;
      // Lay thang
      let month = date.getMonth() + 1;
      month = month <= 9 ? `0${month}` : month;
      // Lay nam
      return `${day}/${month}/${year}`;
    }
  } catch (error) {
    errorMessage("Có lỗi xảy ra");
    console.log("formatDate\n", error);
  }
}

// Thông tin mức lương khi nhập cần được định dạng hiển thị tiền tệ: VD 2.000.000
function formatMoney(salary) {
  try {
    money = new Intl.NumberFormat("de-DE").format(salary);
    return money;
  } catch (error) {
    errorMessage("Có lỗi xảy ra");
    console.log("formatMoney\n", error);
  }
}

/**
 * Hàm thông báo toast
 */

function successMessage(content) {
  // tien xu ly
  const element = $("#toastOK");
  element.show();
  element.find(".toast__content").empty();
  // Them noi dung
  element.find(".toast__content").append(content);
  // in ra console
  console.log(content + "!");
}

function errorMessage(content, error) {
  // tien xu ly
  const element = $("#toastERR");
  element.show();
  element.find(".toast__content").empty();
  // Them noi dung
  element.find(".toast__content").append(content);
  // in ra console
  if (error) console.log(error);
}
