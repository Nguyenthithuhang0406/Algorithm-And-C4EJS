
// Cho phép đóng/mở menu thả xuống khi nhấp chuột
document.addEventListener("click", function(event) {
  var dropdowns = document.getElementsByClassName("dropdown-content");
  var i;
  for (i = 0; i < dropdowns.length; i++) {
    var openDropdown = dropdowns[i];
    if (openDropdown.style.display === "block" && !event.target.classList.contains('dropbtn')) {
      openDropdown.style.display = "none";
    }
  }
});

