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

function loadData() {
  // Goi API
  $.ajax({
    type: "GET",
    url: "https://cukcuk.manhnv.net/api/v1/Employees",
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
          // Dinh dang (Ngay sinh, muc luong co ban)
          switch (format) {
            case "date":
              value = formatDate(value);
              break;
            case "money":
              if (!value)
                value = Math.round(Math.random(100) * Math.pow(10, 8));
              value = formatMoney(value);
              break;
            default:
              break;
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
}

/**
 * Dinh dang hien thi ngay/thang/nam
 * @param {Date} date
 * @returns
 * Author: Nguyen Van Thinh
 */
function formatDate(date) {
  try {
    if (date) {
      date = new Date(date);
      // Lay ngay
      let day = date.getDate();
      day = day <= 9 ? `0${day}` : day;
      // Lay thang
      let month = date.getMonth() + 1;
      month = month <= 9 ? `0${month}` : month;
      // Lay nam
      const year = date.getFullYear();
      return `${day}/${month}/${year}`;
    }
  } catch (error) {
    console.log("formatDate\n", error);
  }
}

// Thông tin mức lương khi nhập cần được định dạng hiển thị tiền tệ: VD 2.000.000
function formatMoney(salary) {
  try {
    money = new Intl.NumberFormat("de-DE").format(salary);
    return money;
  } catch (error) {
    console.log("formatMoney\n", error);
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

    // Ngày sinh/ Ngày cấp/ Ngày gia nhập công ty không được phép lớn hơn ngày hiện tại và phải định dạng hiển thị là ngày/tháng/năm
    $("input[date]").attr("max", limitDate());

    // Xoa du lieu neu co
    const inputs = $("#newEmployee select, #newEmployee input");
    for (const input of inputs) {
      input.value = "";
    }

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

  // click vao 1 dong trong bang
  $(document).on("click", ".table-info .row", function () {
    $(this).siblings().removeClass("row-selected");
    $(this).addClass("row-selected");
    employeeSelected = $(this).data().entity;
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
    let txt = `Bạn có chắc chắn muốn xóa nhân viên <b>${employeeSelected.EmployeeCode}</b> không?`;
    $("#warning .dialog_text").append(txt);
  });

  // click vao nut Co
  $("#btnOK").click(deleteData);

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
  $(".icon-x").click(function () {
    $(this).parents(".pop-up__backgroud").hide(); // parents > siblings > find
  });

  // click nut luu
  $(".icon-save").click(saveData);

  // click nut cancel
  $(".button-cancel").click(function () {
    $(this).parents(".pop-up__backgroud").hide();
  });

  // Luu nhan vien vao database
  function saveData() {
    // Thu thap du lieu
    let employee = {};
    const inputs = $("#newEmployee select, #newEmployee input");
    for (const input of inputs) {
      let val = input.value;
      if (val) {
        const propValue = $(input).attr("propValue");
        employee[propValue] = val;
      }
    }
    employee = JSON.stringify(employee);
    // Goi API
    if (act == "create") {
      $.ajax({
        type: "POST",
        url: "https://cukcuk.manhnv.net/api/v1/Employees",
        data: employee,
        dataType: "json",
        contentType: "application/json",
        success: function (response) {
          console.log("Them moi thanh cong!");
        },
      });
    } else {
      $.ajax({
        type: "PUT",
        url: "https://cukcuk.manhnv.net/api/v1/Employees/" + employeeSelected.EmployeeId,
        data: employee,
        dataType: "json",
        contentType: "application/json",
        success: function (response) {
          console.log("Chinh sua thanh cong!");
        },
      });
    }
    $(this).parents(".pop-up__backgroud").hide();
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
    $.ajax({
      type: "DELETE",
      url:
        "https:/cukcuk.manhnv.net/api/v1/Employees/" +
        employeeSelected.EmployeeId,
      success: function (response) {
        console.log("Xoa thanh cong!");
        loadData();
      },
    });
    // An pop-up
    $("#warning").hide();
  }

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

// for (const val of data) {
//   const employeeCode = val.EmployeeCode;
//   const fullName = val.FullName;
//   const gender = val.Gender;
//   // Lay thong tin ngay sinh va dinh dang theo ngay/thang/nam
//   let dateOfBirth = val.DateOfBirth;
//   dateOfBirth = formatDate(dateOfBirth);
//   // Thon tin con lai
//   const phoneNumber = val.PhoneNumber;
//   const email = val.Email;
//   const positionName = val.PositionName;
//   const departmentName = val.DepartmentName;
//   // all of salary info are empty
//   let salary = Math.round(Math.random(100) * Math.pow(10, 8));
//   salary = formatMoney(salary)

//   const workStatus = val.WorkStatus;
//   // Build thanh cac dong html tuong ung
//   const rowHTML = `
//   <div class="row">
//       <div class="employee-code">${employeeCode}</div>
//       <div class="fullname">${fullName}</div>
//       <div class="gender">${gender || ""}</div>
//       <div class="dateofbirth">${dateOfBirth || ""}</div>
//       <div class="phonenumber">${phoneNumber || ""}</div>
//       <div class="email">${email || ""}</div>
//       <div class="position">${positionName || ""}</div>
//       <div class="department">${departmentName || ""}</div>
//       <div class="salary">${salary || ""}</div>
//       <div class="status">${workStatus || ""}</div>
//   </div>`;
//   // Them row vào class table-info
//   $(".table-info").append(rowHTML);
// }

// fetch(api_url)
//     .then((response) => response.json())
//     .then((employees) => {})
