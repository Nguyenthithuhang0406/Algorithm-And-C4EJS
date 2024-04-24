//bt1
let age = parseInt(prompt("Hãy nhập tuổi của bạn:"));;
if(age >= 18){
   this.document.write("Bạn có đủ tuổi để lái xe");
}else{
   this.document.write("Bạn có chưa đủ tuổi để lái xe");
}

//bt2
let num = parseInt(prompt("Hãy nhập 1 số: "));
if(num < 0){
  this.document.write("<br><br> Đây là số âm");
}else{
  if(num == 0){
    this.document.write("<br><br> Đây là số Không");
  }else{
    this.document.write("<br><br> Đây là số dương");
  }
}

//bt3
let num2 = parseInt(prompt("Hãy nhập 1 số"));
if(num2 % 3 == 0 && num2 % 5 == 0){
this.document.write("<br><br> số này chia hết cho 3 và 5");
}else{
  if(num2 % 3 == 0 && num2 % 5 != 0){
    this.document.write("<br><br> Số này chia hết cho 3 nhưng không chia hết cho 5");
    }else{
     if(num2 % 3 != 0 && num2 % 5 == 0){
       this.document.write("<br><br> Số này chia hết cho 5 nhưng không chia hết cho 3"); 
    }else{   
        this.document.write("<br><br> Số này không chia hết cho cả 3 và 5"); 
     }
  }
}


//bt4
let date = parseInt(prompt("hãy nhập 1 số từ 1-7: "));
switch(date){
  case 1:
    this.document.write("<br><br> Thứ Hai");
    break;
  case 2:
    this.document.write("<br><br> Thứ Ba");
    break;
  case 3:
    this.document.write("<br><br> Thứ Tư");
    break;
  case 5:
    this.document.write("<br><br> Thứ sáu");
    break;
  case 6:
    this.document.write("<br><br> Thứ Bảy");
    break;
  case 7:
    this.document.write("<br><br> Chủ nhật");
    break;
  default:
    this.document.write("<br><br> Số không hợp lệ");
}

//bt5
let n = parseInt(prompt("Hãy nhập số n: "));
let sum = 0;
for(let i = 1; i <= n; i++){
  sum += i;
}
this.document.write("<br><br> Tổng là: " + sum);

//bt6
this.document.write("<br><br> ");
for(let i = 1; i <= 10; i++){
  if(i == 5){
    continue;
  }else{
    this.document.write(i + "  ");
  }
}

//bt7
for(let i = 1; i < 20; i++){
  if(i % 3 == 0){
    this.document.write("<br><br> số đầu tiên chia hết cho 3 là: " + i);
    break;
  }
}

//bt8
this.document.write("<br><br> câu lệnh đó lặp 100 lần từ i = 0 đến i = 99");


//bt9
this.document.write("<br><br> do-while và while khác nhau là:<br> do-while là thực hiện câu lệnh xong mới kiểm tra điều kiện, <br>còn while là kiểm tra điều kiện xem thoả mãn không r mới thực hiện câu lệnh ");