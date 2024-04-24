//bt1
function sum(){
    let arr=[1,4,8,0,5,8,31];
    let sum = 0;
    for(let i = 0; i < arr.length; i++)
        sum += arr[i];
    return sum;
  }
  this.document.write("tổng của mảng là: " + sum());


  //bt2
function dao(){
    let s = "hangnguyen";
    let str = s.split('').reverse().join('');
 return str ;
}
 document.write("<br><br> Chuỗi đảo ngược là: " + dao());

 //bt3
function max(){
    let arr = [2, -1, 5, 98, 23,-89, 45, 7, 6, 2];
    let m = arr[0];
    for(let i = 1; i < arr.length; i++){
      if(arr[i] > m){
        m = arr[i];
      }
    }
    return m;
  }
  document.write("<br><br> Giá trị lớn nhất trong mảng là: " + max());

  //bt4
function sum1(){
    let arr = [2, -1, 5, 98, 23,-89, 45, 7, 6, 2];
    let s = 0;
    for(let i = 0; i < arr.length; i++){
      if(arr[i] > 0){
        s += arr[i];
      }
    }
    return s;
  }
  document.write("<br><br> Tổng các số dương là: " + sum1());

  //bt5
function loc(){
    let arr = [2, -1, 5, 98, 23,-89, 45, 7, 6, 2];
    let marr = [];
    let j = 0;
    for(let i = 0; i < arr.length; i++){
      if(arr[i] % 2 === 0){
        marr[j] = arr[i];
        j++;
      }
    }
    return marr;
  }
  document.write("<br><br> Mảng toàn số chẵn trong mảng là: " + loc());

  //bt6
const inf = {
    Ten: "Nguyễn Thị Thu Hằng",
    Tuoi: 19,
    Chuc_vu: "sinh viên"
  }
  document.write("<br><br> Thông tin nhân viên là: ");
  document.write("<br>" + inf.Ten);
  document.write("<br>" + inf.Tuoi);
  document.write("<br>" + inf.Chuc_vu);

  //bt7
const hcn = {
    dai: 57,
    rong: 40
  }
  let d = hcn.dai;
  let r = hcn.rong;
  function dt(d, r){
    return d * r;
  }
  function cv(d, r){
    return (d+r) * 2;
  }
  document.write("<br><br> Diện tích hình chữ nhật là:  " + dt(d, r));
  document.write("<br> Chu vi hình chữ nhật là:  " + cv(d, r));