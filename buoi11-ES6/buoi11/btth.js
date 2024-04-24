//bt1
const arr = [1,7,3,9,5,3];
const sum = arr.reduce((total, current) => 
total + current, 0);
this.document.write("Tổng các số trong mảng là: " + sum);

//bt2
 const   name = "Nguyễn Thị Thu Hằng";
const  age = 19;
const city =  "Bắc Giang";

const inf = `Name: ${name};Age: ${age};City: ${city}`;
this.document.write("<br><br>Thông tin là : " + inf);

//bt3
const isprime = (number) => {
    if(number <= 1){
        return false;
    }
    for(let i = 2; i * i <= number; i++){
        if(number % i === 0){
                return false;
        }
    }
    return true;
}

const numbers = [8,0,1,5,6,3,8];
const firstIsprime = numbers.find((item) =>
isprime(item));
this.document.write("<br><br>Số nguyên tố đầu tiên trong mảng là: " + firstIsprime);

//bt4
const arrs = [-2,8,5,-6,-9,-3,6,4];
const sum2 = arrs.filter(number => number > 0).reduce((total,current) => total + current, 0);
this.document.write("<br><br>Tổng các số dương là: " + sum2);

//bt5
const products = [
    {
        id: 1,
        name: "Áo thun",
        price: 100000
    },
    {
        id: 2,
        name: "Quần jeans",
        price: 200000
    },
    {
        id: 3,
        name: "Giày sneaker",
        price: 5000000
    }
]
const list = products.map(item =>
    `${item.name} - ${item.price}`);

this.document.write("<br><br>Danh sách sản phẩm:<br>" + list.join("<br>"));

//bt6
const person = { name: "Hằng", age: 19 };

const updatePerSon = { ...person, age: 31 };
console.log(updatePerSon);

//   this.document.write("<br><br>Thông tin sau khi cập nhật là: <br>" + updatePerSon);

//bt7
let a = 7;
let b = 10;
[a,b] = [b,a];
this.document.write("<br><br>Giá trị của a và b sau khi đổi là: a = " + a +", b = " + b);




