const $ = document.querySelector.bind(document);
const $$ = document.querySelectorAll.bind(document);

const contents = $$(".content-item");

const buildLine = (left, width) => {
  const element = $(".line");
  element.style.left = left + "px";
  element.style.width = width + "px";
};

buildLine(0, $(".tab-item").offsetWidth);

$$(".tab-item").forEach((tab, index) => {
  tab.onclick = (e) => {
    buildLine(e.target.offsetLeft, e.target.offsetWidth);

    $(".tab-item.active").classList.remove("active");
    $(".content-item.active").classList.remove("active");

    e.target.classList.add("active");
    contents[index].classList.add("active");
  };
});
