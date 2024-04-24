#include<bits/stdc++.h>
using namespace std;

long long n, sy, sx, dy, dx;
int a[50005][50005];
vector<long long> adj[50005];
bool visited[50005];
	
void inp(){
	cin >> n >> sy >> sx >> dy >> dx;
	adj[sy].push_back(sx);
	adj[sx].push_back(sy);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] = 0)
				if((i > 1 && a[i-1][j] == 0) || (i < n && a[i+1][j] == 0) || (j > 1 && a[i][j-1] == 0) || (j < n && a[i][j+1] == 0)){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
				else a[i][j] = 1;
	memset(visited, false, sizeof(visited));
}

void dfs(long long u){
	visited[u] = true;
	for(long long v : adj[u]){
		if(!visited[v]) dfs(v);
	}
}

void solve(){
	inp();
	dfs(sy);
	if(!visited[dy] || a[dy][dx] == 1) cout << "NO";
	cout << "NO";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
