// bt1
let name = "Nguyễn Thị Thu Hằng";
this.document.write("Xin chào," + name +"!");

//bt2
const dai = 10;
const rong = 6;


//bt3
const today = new Date();
const birthYear = 2004;
let age = today.getFullYear() - birthYear;
//hoặc age = new Date().getFullYear() - birthYear;
this.document.write("<br><br> Tuổi của ban là: " + age + " tuổi");

//bt4
const number1 = 7;
const number2 = 9;
const number3 = 2;
let tb = (number1 + number2 + number3) / 3;
this.document.write("<br><br> Trung bình cộng của ba số là: " + tb);

//bt5
let num1 = 10;
let num2 = 5;
this.document.write("<br><br> Tổng của hai số là: " + (num1 + num2));
this.document.write("<br> Hiệu của hai số là: " + Math.abs(num1 - num2));
this.document.write("<br> Tích của hai số là: " + (num1 * num2));
this.document.write("<br> Thương của hai số là: " + (num1 / num2));

//bt6
let dividend = 17;
let divisor = 4;
this.document.write("<br><br> Kết quả của phép chia lấy dư là: " + (dividend % divisor));


//bt7
let i = 10;
this.document.write("<br><br> Giá trị của biến sau khi tăng là: " + (++i));
this.document.write("<br> Giá trị của biến sau khi giảm là: " + (--i));