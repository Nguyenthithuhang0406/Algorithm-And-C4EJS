#include<bits/stdc++.h>
using namsepace std;

//kiểm tra số đối xứng c++
//vd 1331, 121,....

int tachso(int n){
    int res = 0;
    int m = 0;
    while(n>0){                //121   12   1
        res = n % 10;         // 1     2    1
        m = (m * 10) + res;   //1      12   121
        n = n / 10            //12     1    0
    }
    return m;
}

bool kiemtrasodoixung(int &n){
    if(n == tachso(n)){
        return true;
    }
    return false;
}

int main(){
    int n;
    cout << "nhap vao so muon kiem tra: ";
    cin >> n;
    if(kiemtradoixung(n) == true){
        cout << "yes";
    }else{
        cout << "no";
    }
    return 0;




//kiểm tra ma trận đối xứng qua đường chéo chính c++
// #include<bits/stdc++.h>
// using namespace std;

//ma tran doi xung qua duong cheo chinh la ma tran vuong va a[i][j] = a[j][i]
//1  4  3
//4  5  6
//3  6  9

// bool kiemtra(int a[100][100], int n){
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             if(a[i][j] != a[j][i]){
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// int main(){

//     return 0;
// }