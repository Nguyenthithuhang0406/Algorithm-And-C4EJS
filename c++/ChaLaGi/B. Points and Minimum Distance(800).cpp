#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	long long sum = 0;
	int a[2005];
	cin >> n;
	for(int i = 1; i <= 2*n; i++){
		cin >> a[i];
	}
	sort(a+1, a+ 2*n+1);
	for(int i = 2; i <= n; i ++ ){
		sum += abs(a[i] - a[i-1]);
		sum += abs(a[2*n - i + 1] - a[2*n - i + 2]);
	}
	cout << sum << "\n";
	for(int i = 1; i <= n; i++){
		cout << a[i] << " " << a[2*n-i+1] << "\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
