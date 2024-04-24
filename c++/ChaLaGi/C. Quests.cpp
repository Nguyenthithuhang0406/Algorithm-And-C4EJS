#include<bits/stdc++.h>
using namespace std;

long long n , k;
long long a[200005], b[200005];
long long pref[200005];

void solve(){
	cin >> n >> k;
	pref[0] = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
	}
	long long res = 0, ma = 0;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		ma = max(ma, b[i]);  //max cua b
		if(i <= k){
			res = max(res, pref[i] + ma * (k-i));
		}
	}
	cout << res << "\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
