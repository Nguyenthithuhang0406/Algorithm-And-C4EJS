#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long sum = 0;
		for(int i = 1; i <= n; i ++){
			long long a; cin >> a;
			sum += a;
		}
		long long k = sqrt(sum);
		if(k * k == sum) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
