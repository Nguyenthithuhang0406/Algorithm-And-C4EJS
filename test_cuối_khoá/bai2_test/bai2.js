const colorInput = document.getElementById('color-input');

colorInput.addEventListener('change', function() {
  const selectedColor = colorInput.value;
  document.body.style.backgroundColor = selectedColor;
});

