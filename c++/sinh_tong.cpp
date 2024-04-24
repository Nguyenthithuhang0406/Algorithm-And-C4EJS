//Code Mely
//Dev ơi mình đi đâu thế

//sinh tổng của các phần tử trong dãy bằng quy hoạch động
/*vd
n = 4
1 2 5 7
=> in ra 1 2 3 5 6 7 8 9 10 12 13 14 15
*/
#include<bits/stdc++.h>
using namespace std;

long long n;
bool dp[100005];
long long a[105];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    dp[0] = 1;
    long long sum  = 0;
    for(int i = 1; i <= n; sum += a[i], i++);

    for(long long i = 1; i <= n; i++){
        for(long long j = sum; j >= a[i]; j--){
            if(dp[j - a[i]] == 1){
                dp[j] = 1;
            }
        }
    }

    for(long long i = 1; i <= sum; i++){
        if(dp[i] == 1){
            cout << i << " ";
        }
    }
    return 0
}