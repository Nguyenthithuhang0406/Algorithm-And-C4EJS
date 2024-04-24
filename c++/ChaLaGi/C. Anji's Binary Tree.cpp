#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;	cin >> n;
	string s; cin >> s;
	string xau[n] ;
	vector<int> la;
	xau[1] = "";
	for(int i = 1; i <= n; i++){
		int a,b;
		cin >> a >> b;
		if(a != 0) xau[a] = xau[i] + "L";
		if(b != 0) xau[b] = xau[i] + "R";
		if(a == 0 && b == 0) la.push_back(i);
	}
	cout << n;
	for(int i = 1; i <= n; i ++) cout << xau[i] << " ";
	cout << "\n";
	for(int i : la){
		cout << i << " ";
	}
//	int m = n;
//	for(int i = 0; i <= la.size(); i++){
//		int cnt = 0;
//		string k = xau[la[i]];
//		for(int i = 0; i <= min(s.size(), k.size()); i++){
//			if(s[i] != k[i]) cnt ++;
//		}
//		m = min(m, cnt);
//	}
//	cout << m << "\n";
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
