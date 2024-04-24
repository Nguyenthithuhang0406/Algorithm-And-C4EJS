#include<bits/stdc++.h>
using namespace std;

//Hàm tính ước chung lớn nhất (GCD) sử dụng thuật toán Euclid
int gcd(int a, int b){
    while (b != 0){  //vòng lặp tính GCD theo thuật toán Euclid cho đến khi bằng 0.
        int temp = b; // lưu giữ giá trị của a vào biến tạm thời temp.
        b = a % b;   // gán giá trị a % b vào b.
        a = temp;    //Gán giá trị ban đầu của b vào a.
    }
    return a;
}
 
 int main(){
    int a, b;
    cout << "nhập hai số nguyên dương: ";
    cin >> a >> b;

    int UCLN = gcd(a,b);

    cout << "Ước chung lớn nhất của " << a << " và " << b << " là: "<< UCLN;

    return 0;
 }



 //tính UCLN bằng phương pháp Brute Force
 #include<iostream>
using namespace std;

int gcd(int a, int b){
    int result = min(a, b);   //gán result là số nhỏ nhất trong hai số a,b
    while(result > 0){
        if(a % result == 0 && b % result == 0){ //nếu a và b cùng chia hết cho result thì dừng lại
            break;
        }
        result--;                               //nếu không sẽ giảm result cho đến khi cả a và b đều chia hết cho result
    }
    return result;
}

int main(){
    int a, b;
    cout << "Nhập hai số nguyên a và b: ";
    cin >> a >> b;
    cout << "Ước chung lớn nhất của " << a << " và " << b << " là: " << gcd(a, b);
    
    return 0;
}