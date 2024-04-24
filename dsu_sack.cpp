
#include<bits/stdc++.h>
using namespace std;

int n, c[100005], ans[100005];
vector<int> a[100005];//ds ke
set<int> s[100005];

void dfs(int u, int p = 0){
	s[u].insert(c[u]);
	for(int v : a[u]) 
		if (v != p){
			dfs(v, u);
			if(s[u].size() < s[v].size()) swap(s[u], s[v]);
			for(int x : s[v]) s[u].insert(x);
		}
		ans[u] = s[u].size();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i < n ; ++i){
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) cin >> c[i];
	dfs(1);
	for(int i = 1; i <= n; i++){
		cout << ans[i] << "\n";
	}
	return 0;
}
