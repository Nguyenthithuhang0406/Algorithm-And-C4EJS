//Dev ơi mình đi đâu thế?
//Tìm xâu con chung lớn nhất

//cách 1: QHD thông thường
// #include<bits/stdc++.h>
// using namespace std;


// int F[1001][1001];  //F[i][j]: lưu xâu con chung dài nhất trong đoạn [i, j]
// int main(){
//     string x, y;
//     cin >> x >> y;
//     int n = x.size(), m = y.size();
//     for(int i = 0; i <= n; i++)
//         for(int j = 0; j <= m; j++){
//             if(i == 0 || j == 0)  F[i][j] = 0;
//             else 
//                 if(x[i-1] == y[i-1])  F[i][j] = F[i-1][j-1] + 1;
//                 else F[i][j] = max(F[i-1][j], F[i][j-1]);

//         }
//     cout << F[n][m];
// }


//Cách 2: tối ưu hoá_ đổi biến 
#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005];  //dp[i][j]: vị trí k nhỏ nhất sao cho j là vị trí có kí tự giống nhau của a[1,i] và b[1,k]
string a, b;
int nextPos[1000006][26]; //nextPos[i][c] = j là vị trí nhỏ nhất mà a[j] = c   (j > i)
int m, n;

//hàm cập nhật giá trị của dp
void minimize(int &a, int b){
    if(a == -1 || a > b) a = b;
}

void solve(){
    cin >> a   >> b ; 
    m = a.size(); n = b.size();

//cập nhật nextPos
    for(int c = 0; c < 26; c++)
        for(int i = m - 1; i >= 0; i--)
            if(a[i+1] - 'a' == c) nextPos[i][c] = i;
            else nextPos[i][c] = nextPos[i+1][c];

    int maxLength = min(m, n);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

//cập nhật giá trị dp
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++)
            if(dp[i][j] >= 0){
                minimize(dp[i+1][j], dp[i][j]);
                //vị trí xuất hiện tiếp theo của b[i+1] trong xâu a, từ vị trí dp[i][j]
                int k = nextPos[dp[i][j]][b[i+1] - 'a']; 
                if(k > 0)
                    minimize(dp[i+1][j+1], k);
            }
    }

    int ans = 0;
    //kết quả chính là j lớn nhất mà dp[i][j] != -1
    for(int j = maxLength; j > 0; j--){
        for(int i = j; i <= n; i++)
            if(dp[i][j] >= 0) ans = j;
        if( ans != 0) break;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}