console.log("Hello JS flow control !");

// scope
// common variable, functions
let x = 2;
document.write(x + 100);
let like = 0;
function a() {
    console.log("abcd 1");
}

function a() {
    console.log("Function A()")
}

a();

// For ads
{
    // block variable
    let y = 1000; // ads number
    document.write("<br> Products number: " + y);
    // setInterval(() => {
    //     y++;
    //     console.log(new Date());
    //     console.log(y);
    //     console.log(x++);
    //     console.log(like++);

    // }, 2000)

    a();

    function dislike() {
        like--;
    }
}


dislike();
// global variable
let y = 0;
y - 100;
document.write("<br> Products number: " + y);

if ("mindx" != "mindx") {
    document.write("<br> Day la trung tam gia mao !")
} else {
    document.write("<br> Ban da chon duoc dung trung tam !")
}

function outer() {
    console.log("Outer");
}

if (1 == 1 && "mindx" == "mindx" && y > 18) {
    outer();
    // print product list
    console.log("true 1");
}
else if (2 != 2) {
    console.log("true 2");
}
else if (3 != 3) {
    console.log("true 3");
}
else {
    console.log("false");
}
console.log(like);
like = 0;
switch (like) {
    case 0:case -1:
        document.write("Khong co cai thich !")
        break;
    case 1:
        document.write("Chuc mung ban da co nhung luot thich dau tien !")
        break;
    default:
        document.write("Chuc mung ban da co nhieu luot thich !")
        break;
}

let sum = 0
let m = 10;
for (let i = 0;i<10; i+=m) {
    if(i ==0 ){
        continue
    }
	sum += i
    console.log(sum);
    if(m < 100){
        m = 10;
    }else{
        m = 100;
    }

}

let i = 0;
while (i < 99) {
	sum += i;
	i++;
}
console.log(sum);

// input: list integer
// [1,2,3,4,5,6,7,8,9,10]
let iArr = [1,2,3,4,5,6,7,8,9,10]
let fArr = [1,1.2323, 43.14, 5.6789]
let sArr = ["hello", "hi", "how", "you","I am"]
let mArr = [2022, "happy new year", 5.343434, true];
let eArr = [];

// Array properties
console.log(iArr.length);
console.log(eArr.length);

// Array index
let ai = 0; // lastIndex = "length - 1"
console.log(iArr[ai]);
console.log(fArr[ai]);
console.log(sArr[sArr.length]);

// Insert data
iArr.push(11)
console.log(iArr);

// Update data
iArr[0] = 100;
console.log(iArr);

// delete data
iArr.splice(0,5);
console.log(iArr);
iArr.splice(iArr.length-1,2)
console.log(iArr);

// find one
console.log(iArr.find(item => item <= 6));

// find all / find any
let u6Arr = iArr.filter(item => item  > 6);
console.log(u6Arr.length);

// Matrix
let mExam = [
    [2,4,6,8],
    [1,3,5,7],
    [10,12,14,16],
    [9,11,13,15]
]

console.log(mExam[0][2]);

// Matrix
let mExam3 = [
    [
        [1,0,1,1,1,0],
        [1,1,1,1,1,1]
    ],
    [
        [0,0,0,1,1],
        [1,1,1,1,1]
    ]
]

console.log(mExam3[0][0][1]);

let total = 0 ;
// For loop
for(let i = 0; i < iArr.length ; i++){
    iArr[i]+= 100
    total += iArr[i]
    document.write(iArr[i] + '<br>');
}

mArr.forEach(item => {
    if(typeof(item) == "number") {
        document.write("<h1>Trong mang co it nhat mot so</h1>")
    }
    if(typeof(item) != "string") {
        document.write("<h1>Mang khong hop le</h1>")
    }
    document.write(typeof(item) + "<br>")
})


//đưa 1 mảng về toàn chuổi + value
let customArray = mArr.map(item => {
    return "value: " + item;
})

console.log(customArray);

//đưa trở về ban đầu nhưng vẫn là string
let originalArr = customArray.map(item => {
    console.log(item);
    return item.split(":")[1].trim();//tách ở chỗ : làm 2 phần, lấy phần thứ hai, index = 1; trim() xoá 2 đầu cì có dấu cách
})

console.log(originalArr);

const car = {
	brand: "Toyota",
	year: 2022,
	color: "green"
}

car.brand = "Huyndai"

car.color = "yellow"; // reference data, primitive data

console.log(car);
let carStr = '<div style="background-color:' + car.color +
';width:200px;height:200px">Day la xe cua ban: ' + car.brand +'</div>'
document.write(carStr)

let listOrder = [
    {
        productName: "Ommo",
        price: 120000,
        pickTime: new Date()
    },
    {
        productName: "Sunlight",
        price: 120000,
        pickTime: new Date()
    },    {
        productName: "Lifeboy",
        price: 120000,
        pickTime: new Date()
    },
]

listOrder.forEach(item => {
    document.write('<div style="background-color:yellow;width:400px;height:80px;border-radius:30px; text-align: center; padding-top:20px; margin:10px">Ten san pham: ' + item.productName + ' Gia: ' + item.price +'</div>')
})

function checkPhoneNumber(phoneNumber) {
    console.log(typeof(phoneNumber));
    if(typeof(phoneNumber) != "string" && typeof(phoneNumber) != "number"){
        return "Khong phai sdt";
    }

    let realPhoneNumber = "+84" + phoneNumber;
    return realPhoneNumber;
}

console.log(checkPhoneNumber("2323232332")
);