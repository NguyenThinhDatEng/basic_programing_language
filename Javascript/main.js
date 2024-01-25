let ulElement = document.querySelector("ul");
ulElement.onmousedown = (e) => {
  console.log(e);
  e.preventDefault();
};
