#include<bits/stdc++.h>
using namespace std;

bool dp[100005];
long long n;
long long a[105];
//set<long long> result;
//quay lui,de quy
/*void backtrack(long long i, long long sum){
	if(i == n){
		result.insert(sum);
		return;
	}
	backtrack(i+1, sum);
	backtrack(i+1, sum + a[i]);
}*/

int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	
	//dequy
/*	backtrack(1,0);
	for(auto x : result){
		cout <<x << " ";
	}*/
	
	//qhd
	dp[0] = 1;
	long long sum = 0;
	for(long long i = 1; i <= n; sum += a[i], i++);
	
	for(long long i = 1; i <= n; i++){
		for(long long j = sum ; j >= a[i]; j--){
			if(dp[j-a[i]] == 1){
				dp[j] = 1;
			}
		}
	}
	for(long long i = 1; i <= sum ; i++){
		if(dp[i] == 1){
			cout << i << " " ;
		}
	}
}
