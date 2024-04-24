#include<bits/stdc++.h>
using namespace std;

long long a[105][105];
long long dp[105][105];

int main(){
	long long n, m;
	cin >> n >> m;
	for(long long i = 1; i<= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	
	for(long long i = 0; i <= m; i++){
		dp[0][i] =  dp[n+1][i] = INT_MAX;
	}
	
	for(long long i = 1; i <= n; i++){
		dp[i][1] = a[i][1];
	}
	
	for(long long j = 2; j <= m ;j ++){
		for(long long i = 1; i <= n; i++){
			dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1]}) + a[i][j];
		}
	}
	
	long long result = dp[1][m];
	for(long long i =1; i <= n; i++){
		result = min(result, dp[i][m]);
	}
	cout << result;
	cout <<"duong di: \n ";
	long long x, y;
	list<pair<long long, long long>> dd;
	for(long long i = 1; i<= n; i++){
		if(dp[i][m] == result){
			x = i;
			y = m;
		}
	}
	for(long long j = m -1;  j >= 1; j--){
		if(dp[x-1][y-1] <= dp[x][y-1] && dp[x-1][y-1]  <= dp[x+1][y-1]){
			x = x- 1; y = y -1;
		}else{
			if(dp[x][y-1] <= dp[x-1][y-1] && dp[x][y-1] <= dp[x+1][y-1]){
				x = x; y = y -1;
			}
			else{
				x = x+ 1; y = y - 1;
			}
		}
		dd.push_front({x,y});
	}
	for(auto x : dd){
		cout << x.first << " " << x.second <<'\n';
	}
	return 0;
}
