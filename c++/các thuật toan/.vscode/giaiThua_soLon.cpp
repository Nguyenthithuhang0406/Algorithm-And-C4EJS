// Dev ơi mình đi đâu thế?

//Cách 1: Tính giai thừa sử dụng đệ quy.
//chỉ áp dụng với số nhỏ, tốn bộ nhớ
// #include<bits/stdc++.h>
// using namespace std;

// unsigned long long GiaiThua(int n){
//     if(n == 0 || n == 1) return 1;
//     return n * GiaiThua(n-1);
// }

// int main(){
//     int n;
//     cout << "nhap so nguyen: ";
//     cin >> n;
//     cout << GiaiThua(n);
//     return 0;
// }

//Cách 2: Tính giai thừa sử dụng vòng lặp
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n; 
//     cout << "nhap so nguyen: ";
//     cin >> n;
//     unsigned long long GiaiThua = 1;
//     if(n > 1){
//         for(int i = 2; i <= n; i++) 
//             GiaiThua *= i;
//     }
//     cout << GiaiThua;
//     return 0;
// }

//cách 3: tính giai thừa cho số lớn
//sử dụng vector để lưu trữ giá trị giai thừa
#include<bits/stdc++.h>
using namespace std;

//nhân từng chữ số của number cho một số nguyên dương
vector<int> multiply(vector<int> number, int x){
    vector<int> result;
    int carry = 0; //giá trị nhớ trong phép nhân
    for(int i = 0; i < number.size(); i++){
        int prod = number[i] * x + carry;
        result.push_back(prod % 10);
        carry = prod / 10;
    }

    while(carry){
        result.push_back( carry % 10);
        carry /= 10;
    }
    return result;
}

//tính giai thừa
vector<int> factorial(int n){
    vector<int> result;
    result.push_back(1); //giai thừa của 0 là 1;
    for(int i = 2; i <= n; i++){
        result = multiply(result, i);
    }
    reverse(result.begin(), result.end());
    return result;
}

//in output
void output(vector<int> number){
    for(int i = 0; i < number.size(); i ++){
        cout << number[i];
    }
    cout << "\n";
}

int main(){
    int n;
    cout << "nhap so nguyen: ";
    cin >> n;
    vector<int> result = factorial(n);
    output(result);
    return 0;
}