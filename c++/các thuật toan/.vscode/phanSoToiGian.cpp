#include<bits/stdc++.h>
using namespace std;

//Hàm tìm ước chung lớn nhất (GCD)
int GCD(int a, int b){
    while (b != 0)
    {
       int temp = b;
       b = a % b;
       a = temp;
    }
    return a;
}

//hàm rút gọn phân số
void solve(int t, int m){
    //tìm ước chung lớn nhất của tử và mẫu
    int gcd = GCD(t, m);

    //rút gọn phân số bằng cách chia tử và mẫu cho ước chung lớn nhất
    t /= gcd;
    m /= gcd;
    cout << "Phan so sau khi rut gon la: " << t << "/" << m;

}
int main(){
    int t, m;
    //nhập tử và mẫu
    cout << "moi ban nhap tu so: \n";
    cin >> t;
    cout << "moi ban nhap mau so, mau so phai khac khong: \n";
    cin >> m;
    solve(t, m);
    return 0;
}