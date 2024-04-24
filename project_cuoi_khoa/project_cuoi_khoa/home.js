

var menu = document.querySelector('.menu-theloai');
menu.addEventListener('mouseover', function() {
  menu.classList.add('menu-hover');
});
menu.addEventListener('mouseout', function() {
  menu.classList.remove('menu-hover');
});

