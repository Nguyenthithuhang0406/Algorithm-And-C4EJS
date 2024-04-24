#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	char s[n];
	int cnt = 0, k = 0;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		if(s[i] == '.') cnt ++;
		if(i >= 3 && s[i] == '.' && s[i-1] == '.'  && s[i-2] == '.')
				k = 2;
	}
	if(k == 2) cout << "2" << "\n";
	else cout << cnt << "\n";
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
