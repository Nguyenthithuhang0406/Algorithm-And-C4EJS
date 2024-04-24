#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200005], dp[200005], parent[200005];
vector<long long> adj[200005];
bool visited[200005];

void dfs(long long u, long long p){
	visited[u] = true;
	for(long long v : adj[u]){
		if(!visited[v]) {
			parent[v] = u;
			dfs(v, u);
		}
	}
	dp[p] += dp[u];
} 

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		long long x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = a[i];
	}
	memset(visited, false, sizeof(visited));
	
	dfs(1,0);
	for(int i = 1; i <= n; i++){
		if(!visited[i]) dfs(i, parent[i]);
	}
	long long m = -INT_MAX;
	for(int i = 1; i <= n; i++){
		m = max(m, dp[i]);
	}
	cout << m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
