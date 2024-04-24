#include<bits/stdc++.h>
using namespace std;

long long a[105][105];
long long dp[105][105];

int main(){
    long long n, m;
    cin >> n >> m;
    //đọc ma trận cỡ mxn 
    for(long long i = 1; i <= n; i++){
        for(long long j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

//gán giá trị cột 0 và cột n+1 bằng một giá trị rất lớn
    for(long long i = 0; i <= m; i++){
        dp[0][i] = dp[n+1][i] = INT_MAX;    
    }
    
    // chi phí đi đến các ô ở cột 1 chính là giá trị của ô đó
    for(long long i = 1; i <= n; i++){
        dp[i][1] = a[i][1]; 
    }

//chi phí đi đến ô ở cột hiện tại = chi phí nhỏ nhất đi đến cột trước đó + giá trị ô đó
    for(long long j = 2; j <= m; j++){
        for(long long i = 1; i <= n; i++){
            dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]) + a[i][j];
        }
    }

//chi phí đi đến cột cuối cùng chính là từng giá trị dp của cột cuối
    long long result = dp[1][m];
    for(long long i = 1; i <= n; i++){
        result = min(result, dp[i][m]);
    }
    cout << result;
    cout <<"duong di: \n";

//tìm đường đi
    long long x, y;
    list<pair<long long, long long>> dd;
    for(long long i = 1; i <= n; i++){
        if(dp[i][j] == result){ // tìm vị trí có chi phí thấp nhất
            x = i;
            y = m;
        }
    }
    //for ngược lại cột đầu để tìm từng vị trí để có chi phí thấp nhất
    for(long long j = m -1; j >= 1; j--){
        if(dp[x-1][y-1] <= dp[x][y-1] && dp[x-1][y-1] <= dp[x+1][y-1]){
            x = x - 1;
            y = y - 1;
        }else{
            if(dp[x][y-1] <= dp[x-1][y-1] && dp[x][y-1] <= dp[x+1][y-1]){
                x = x;
                y = y -1;
            }else{
                x = x + 1;
                y = y - 1;
            }
        }
        dd.push_front({x,y}); //với mỗi cặp giá trị tìm được sẽ thêm vào đầu list
    }
    //duyệt list để ghi ra đường đi
    for(auto x : dd){
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}