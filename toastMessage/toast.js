$ = document.querySelector.bind(document);

const btn = $(".btn");
const toastList = $("#toast");

btn.onclick = () => {
  const messages = [
    {
      title: "Cách làm Toast Message",
      message:
        "Tham gia nhóm Học lập trình tại F8 trên Facebook để cùng nhau trao đổi trong quá trình học tập",
      type: "success",
      duration: 3000,
    },
    {
      title: "Code",
      message:
        "Code trong video: https://codepen.io/ng-ngc-sn-the-bashful/pen/Exgmxqp",
      type: "success",
      duration: 1000,
    },
    {
      title: "Thiết kế",
      message:
        "Ảnh thiết kế Toast Message: https://dribbble.com/shots/4580930-Toast-Messages",
      type: "success",
      duration: 5000,
    },
  ];
  const randomIndex = Math.floor(Math.random() * messages.length);
  showToast(messages[randomIndex]);
};

const showToast = ({ title, message, type = "success", duration = 3000 }) => {
  const toast = document.createElement("div");
  toast.classList.add("toast-item");
  /*
   * fadeOut
   * - delay: 3s
   * - duration: 1s
   */
  const delay = duration / 1000;
  const animationDuration = 1;
  toast.style.animation = `slideFromRight ease 0.5s, fadeOut linear ${animationDuration}s ${delay}s forwards`;

  const icons = {
    success: "fa-solid fa-circle-check",
  };
  toast.innerHTML = `
  <div class="toast__icon">
    <i class="${icons[type]}"></i>
  </div>
  <div class="toast__body">
    <h3 class="toast__title">${title}</h3>
    <p class="toast__msg">${message}</p>
  </div>
  <div class="toast__close">
    <i class="fa-solid fa-xmark"></i>
  </div>`;

  toastList.appendChild(toast);

  const timeOutId = setTimeout(() => {
    if (toast.nodeType === 1) {
      toastList.removeChild(toast);
    }
  }, duration + animationDuration * 1000);

  toast.onclick = (e) => {
    if (e.target.closest(".toast__close")) {
      clearTimeout(timeOutId);
      toastList.removeChild(toast);
    }
  };
};
