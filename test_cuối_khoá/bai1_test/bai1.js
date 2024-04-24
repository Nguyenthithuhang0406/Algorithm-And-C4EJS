
function findPerfectSquares() {
    var a = parseInt(document.getElementById("a").value);
    var b = parseInt(document.getElementById("b").value);
    var result = document.getElementById("result");

    result.innerHTML = ""; 
    if (a > b) {
        result.innerHTML = "Lỗi: Số a phải nhỏ hơn hoặc bằng số b.";
        return;
    }

    for (var i = a+1; i < b; i++) {
        if (Math.sqrt(i) % 1 === 0) {
            result.innerHTML += i + " ";
        }
    }
}