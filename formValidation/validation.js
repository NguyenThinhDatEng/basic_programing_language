$ = document.querySelector.bind(document);

String.prototype.format = function () {
  var args = arguments;
  return this.replace(/\{(\d+)\}/g, function (match, index) {
    return typeof args[index] !== "undefined" ? args[index] : match;
  });
};

// Config các rules mặc định
const validationRules = {
  required: {
    name: "required",
    message: "Trường thông tin bắt buộc nhập",
  },
  isEmail: {
    name: "isEmail",
    message: "Email không đúng định dạng",
  },
  minLength: {
    name: "minLength",
    message: `Trường thông tin phải có ít nhất {0} ký tự`,
  },
  equalTo: {
    name: "equalTo",
    message: "Trường thông tin không khớp",
  },
};

// Kiểm tra tính hợp lệ
const checkValidity = (value, rules) => {
  let errorMessage = [];
  if (Array.isArray(rules)) {
    errorMessage = rules.map((rule) => {
      // Lấy ra message cảnh báo theo dữ liệu custom
      const errorMessageCustom = rule.message;
      // Lấy ra tên rule xác thực
      const ruleName = Object.keys(rule).find((key) =>
        Object.keys(validationRules).includes(key)
      );
      // Lấy ra giá trị của rule
      const ruleValue = rule[ruleName];

      switch (ruleName) {
        case validationRules.required.name:
          return !value?.trim()
            ? errorMessageCustom ?? validationRules.required.message
            : "";
        case validationRules.isEmail.name:
          const isValid =
            /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(
              value
            );
          return !isValid
            ? errorMessageCustom ?? validationRules.isEmail.message
            : "";
        case validationRules.minLength.name:
          return value?.trim().length < ruleValue
            ? errorMessageCustom ??
                validationRules.minLength.message.format(ruleValue)
            : "";
        case validationRules.equalTo.name:
          const comparableSelector = $(ruleValue);
          if (comparableSelector) {
            const comparableValue = comparableSelector.value;
            return value?.trim() !== comparableValue
              ? errorMessageCustom ?? validationRules.equalTo.message
              : "";
          }
        default:
          console.error("Rule is not valid");
      }
    });
  }
  return errorMessage.find((x) => x);
};

// Validate các controls
const validateElement = (validation, configs) => {
  let isValid = true;
  const element = $(validation.selector);
  if (element) {
    // get configs
    const { formGroupSelector, errorClassName, errorMessageSelector } = configs;
    // check
    const errorMessage = checkValidity(element.value, validation.rules);
    if (errorMessage) {
      // update valid variable
      isValid = false;
      // update element
      element.classList.add(errorClassName);
      // error message element
      const errorMessageElement = element
        .closest(formGroupSelector)
        ?.querySelector(errorMessageSelector);
      if (errorMessageElement) {
        errorMessageElement.classList.add(errorClassName);
        errorMessageElement.textContent = errorMessage;
      }
    }
  }
  return isValid;
};

const validate = (configs) => {
  const {
    formSelector,
    formGroupSelector,
    errorMessageSelector,
    errorClassName,
    validation,
  } = configs;
  const form = $(formSelector);
  if (form) {
    // Validate controls
    if (Array.isArray(validation)) {
      Array.from(validation).forEach((x) => {
        const element = $(x.selector);
        if (element) {
          const errorMessageElement = element
            .closest(formGroupSelector)
            ?.querySelector(errorMessageSelector);

          element.onblur = () => {
            validateElement(x, configs);
          };

          element.oninput = () => {
            element.classList.remove(errorClassName);
            if (errorMessageElement) {
              errorMessageElement.classList.remove(errorClassName);
              errorMessageElement.textContent = "";
            }
          };
        }
      });
    }
    // submit
    form.onsubmit = (e) => {
      e.preventDefault();
      let isValid = true;
      const data = {};
      if (Array.isArray(validation)) {
        Array.from(validation).forEach((x) => {
          const result = validateElement(x, configs);
          if (!result) {
            isValid = false;
          } else {
            const element = $(x.selector);
            if (x.field) {
              data[x.field] = element.value;
            }
          }
        });
      }
      // If is valid => submit form
      if (isValid) {
        console.log(data);
        // form.submit();
      }
    };
  }
};

validate({
  formSelector: "#register",
  formGroupSelector: ".form-group",
  errorMessageSelector: ".error-message",
  errorClassName: "error",
  validation: [
    {
      selector: "#full-name",
      field: "fullName",
      rules: [{ required: true, message: "Vui lòng nhập đẩy đủ họ và tên" }],
    },
    {
      selector: "#email",
      field: "email",
      rules: [{ required: true }, { isEmail: true }],
    },
    {
      selector: "#password",
      field: "password",
      rules: [{ required: true }, { minLength: 6 }],
    },
    {
      selector: "#passwordConfirmation",
      rules: [{ required: true }, { equalTo: "#password" }],
    },
  ],
});
