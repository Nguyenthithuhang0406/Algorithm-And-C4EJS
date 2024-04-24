#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		map<int, int> mp;
		int n; cin >> n;
		string s; cin >> s;
		 for(int i = 0; i < s.size(); i++){
		 	mp[s[i] - 'A' + 1] ++;
		 }
		 int cnt = 0;
		 for(int i = 1; i <= 26; i++) 
		 	if(mp[i] >= i) cnt ++;
		 cout << cnt << "\n";
	}
return 0;
}
