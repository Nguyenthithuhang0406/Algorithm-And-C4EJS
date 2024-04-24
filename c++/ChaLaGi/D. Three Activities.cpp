#include<bits/stdc++.h>
using namespace std;

vector<pair<long long, int>> a, b, c;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			a.push_back({x, i});
		}
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			b.push_back({x, i});
		}
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			c.push_back({x, i});
		}
		
		//sap giam dan
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		sort(c.rbegin(), c.rend());
		
		long long res = 0;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					int x = a[i].second, y = b[j].second, z = c[k].second;
					if( x != y && y != z && x != z) res = max(res, (a[i].first + b[j].first + c[k].first));
				}
			}
		}
		a.clear(), b.clear(), c.clear();
		cout << res << "\n";
	}
	return 0;
}
