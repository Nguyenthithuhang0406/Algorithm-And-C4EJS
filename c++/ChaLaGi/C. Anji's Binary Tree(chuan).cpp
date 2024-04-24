#include<bits/stdc++.h>
using namespace std;

#define int long long
pair<int, int> dinh[300005];
string s;

int dfs(int i = 1){
	if(!dinh[i].first && !dinh[i].second) return 0;
	
	int res1 = INT_MAX;
	if(dinh[i].first) res1 = dfs(dinh[i].first);
	if(s[i-1] != 'L') res1++;
	
	int res2 = INT_MAX;
	if(dinh[i].second) res2 = dfs(dinh[i].second);
	if(s[i-1] != 'R') res2++;
	
	return min(res1, res2);   //tinhs gias tri toi thieu can thay doi tai dinh i
}

void solve(){
	int n; cin >> n;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> dinh[i].first >> dinh[i].second;
	}
	cout << dfs(1) << "\n";
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
