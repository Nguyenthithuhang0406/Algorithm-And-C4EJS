#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	
	vector<int> left(n), right(n);
	left[0] = -1;
	for(int i = 0; i < n; i++){
		if(i>0) left[i] = left[i-1];
		if(s[i] == '0') left[i] = i;
	}
	right[n-1] = n;
	for(int i = n-1; i >= 0; i--){
		if(i<n-1) right[i] = right[i+1];
		if(s[i] == '1') right[i] = i;
	}
	
	set<pair<int,int>> p;
	for(int i = 1; i <= m; i++){
		int l, r; cin >> l >> r;
		int ll = right[l-1];
		int rr = left[r-1];
		if(ll > rr){
			p.insert({-1,-1});
		}else{
			p.insert({ll,rr});
		}
	}
	cout << p.size() << "\n";
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
