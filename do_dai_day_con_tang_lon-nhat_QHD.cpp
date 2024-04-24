#include<bits/stdc++.h>
using namespace std;

long long a[105];
long long dp[105];
int main(){
	long long n;	
	cin >> n;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		dp[i] = 1;
	}
	for(long long i = 1; i <= n; i++){
		for(long long j = 1; j < i; j++){
			if(a[j] < a[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	long long result = 0;
	for(long long i =1; i <= n; i++){
		result = max(result, dp[i]);
	}
	cout << result;
}
