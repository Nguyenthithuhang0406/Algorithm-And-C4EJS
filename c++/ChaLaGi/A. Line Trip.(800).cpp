#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, x;
	int a[52];
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[0] = 0;
	a[n+1] = x;
	int m = 0;
	for(int i = 1; i <= n; i++){
		m = max(m, a[i] - a[i-1]);
	} 
	m = max(m, (a[n+1] - a[n]) * 2);
	cout << m << "\n";
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
