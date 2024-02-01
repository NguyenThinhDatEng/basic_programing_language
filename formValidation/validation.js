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
    message: "Required information field",
  },
  isEmail: {
    name: "isEmail",
    message: "Email invalidate",
  },
  minLength: {
    name: "minLength",
    message: `The information field must have at least {0} characters`,
  },
  equalTo: {
    name: "equalTo",
    message: "The information field do not match",
  },
};

const inputTypes = {
  radio: "radio",
  checkbox: "checkbox",
  file: "file",
};

// Kiểm tra tính hợp lệ
const checkValidity = (elements, rules) => {
  let errorMessage = [];
  if (Array.isArray(rules) && elements.length > 0) {
    errorMessage = rules.map((rule) => {
      // Lấy ra message cảnh báo theo dữ liệu custom
      const errorMessageCustom = rule.message;
      // Lấy ra tên rule xác thực
      const ruleName = Object.keys(rule).find((key) =>
        Object.keys(validationRules).includes(key)
      );
      // Lấy ra giá trị của rule
      const ruleValue = rule[ruleName];
      // value of input
      const value = elements[0].value;

      switch (ruleName) {
        case validationRules.required.name:
          return validateRequired(elements, errorMessageCustom);
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

/**
 * @description Xử lý validate với rule yều cầu nhập
 * @param {Object} elements node in html
 * @param {String} errorMessageCustom
 * @returns {String} errorMessage
 */
const validateRequired = (elements, errorMessageCustom) => {
  // type of input
  const type = elements[0].type;
  // value of input
  const value = elements[0].value;
  switch (type) {
    case inputTypes.radio:
    case inputTypes.checkbox:
      return Array.from(elements).some((x) => x.checked)
        ? ""
        : errorMessageCustom ?? validationRules.required.message;
    default:
      return !value?.trim()
        ? errorMessageCustom ?? validationRules.required.message
        : "";
  }
};

// Validate các controls
const validateElement = (form, validation, configs) => {
  let isValid = true;
  const elements = form.querySelectorAll(validation.selector);
  if (elements?.length > 0) {
    // get configs
    const { formGroupSelector, errorClassName, errorMessageSelector } = configs;
    // check
    const errorMessage = checkValidity(elements, validation.rules);
    if (errorMessage) {
      // update valid variable
      isValid = false;
      // update element
      Array.from(elements).forEach((x) => {
        x.classList.add(errorClassName);
      });
      // error message element
      const errorMessageElement = elements[0]
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

/**
 * Khởi tạo các sự kiện cho form và controls in from
 * @param {Object} configs Cấu hình validation
 */
const validator = (configs) => {
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
        const elements = form.querySelectorAll(x.selector);
        if (elements.length > 0) {
          const errorMessageElement = elements[0]
            .closest(formGroupSelector)
            ?.querySelector(errorMessageSelector);

          if (elements.length == 1) {
            elements[0].onblur = () => {
              validateElement(form, x, configs);
            };
          }

          // input event
          Array.from(elements).forEach((element) => {
            element.oninput = () => {
              element.classList.remove(errorClassName);
              if (errorMessageElement) {
                errorMessageElement.classList.remove(errorClassName);
                errorMessageElement.textContent = "";
              }
            };
          });
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
          const result = validateElement(form, x, configs);
          if (!result) {
            isValid = false;
          } else {
            if (x.field) {
              data[x.field] = getFormGroupValue(form, x.selector);
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

// Lấy ra giá trị của form group
const getFormGroupValue = (form, selector) => {
  const elements = form.querySelectorAll(selector);
  if (elements.length > 0) {
    const type = elements[0].type;
    switch (type) {
      case inputTypes.radio:
        return Array.from(elements).find((x) => x.checked)?.value;
      case inputTypes.checkbox:
        return Array.from(elements)
          .map((x) => (x.checked ? x.value : ""))
          .filter((x) => x);
      case inputTypes.file:
        return elements[0].files;
      default:
        return elements[0].value;
    }
  }
};

validator({
  formSelector: "#register",
  formGroupSelector: ".form-group",
  errorMessageSelector: ".error-message",
  errorClassName: "error",
  validation: [
    {
      selector: "#full-name",
      field: "fullName",
      rules: [
        { required: true, message: "Please enter full first and last name" },
      ],
    },
    {
      selector: "#email",
      field: "email",
      rules: [{ required: true }, { isEmail: true }],
    },
    {
      selector: "[name=gender]",
      field: "gender",
      rules: [{ required: true }],
    },
    {
      selector: "#orientation",
      field: "orientation",
      rules: [{ required: true }],
    },
    {
      selector: "[name=language]",
      field: "languages",
      rules: [{ required: true }],
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
