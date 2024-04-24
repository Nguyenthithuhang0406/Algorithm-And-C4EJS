//Dev ơi mình đi đâu thế?
//Code Mely

//Quy hoạch động 2 chiều trên lưới
// Bài toán ví dụ: Cho một lưới A gồm n hàng, m cột là các số nguyên dương
//Có q truy vấn: cho 4 số y1, x1, y2, x2; yêu cầu tính tổng các số trong khoảng từ ô [y1, x1] đên ô [y2,x2];


#include<bits/stdc++.h>
using namespace std;

int n, m, q;
long long A[1001][1001];  //lưới A
long long dp[1001][1001];  //dp[i][j] lưu trữ tổng các số từ ô [1][1] đến ô [i][j]

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> q; //nhập số hàng, số cột và số truy vấn
    //nhập giá trị lưới A
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j++) 
            cin >> A[i][j];
    }

    for(int i = 0; i <= n; i ++ ) dp[i][0] = 0; //khởi tạo cột 0 của lưới dp bằng 0
    for(int i = 0; i <= m; i++)  dp[0][i] = 0; //khởi tạo hàng 0 của lưới dp bằng 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + A[i][j];

    while(q--){
        int y1, x1, y2, x2;  cin >> y1 >> x1 >> y2 >> x2;
        int sum = dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1];
        cout << sum << "\n";
    }
    return 0;
}