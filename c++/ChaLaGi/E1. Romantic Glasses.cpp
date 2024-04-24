#include<bits/stdc++.h>
using namespace std;

long long a[200005], hieu[100005];
void solve(){
	int n; cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
		}
		
		vector<long long> chan(n+1, 0), le(n+1, 0);
		for(int i = 1; i <= n; i++){
			if(i%2){
				le[i] = le[i-1] + a[i];
				chan[i] = chan[i-1];
			}else{
				chan[i] = chan[i-1] + a[i];
				le[i] = le[i-1];
			}
		}
		
		for(int i = 1; i <= n; i++) hieu[i] = chan[i] - le[i];
		
		map<long long, int> mp; 
		mp[0] = 1;
		for(int i = 1; i <= n; i++){
			//neu ton tai gia tri hieu[i] ma no da ton tai hieu[j] = hieu[i] => tong chan va le trong doan [i,j] = nhau
			if(mp[hieu[i]]) {
				cout << "YES" << "\n";
				return ;
			}
			mp[hieu[i]] ++;
		}
		cout << "NO" << "\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
