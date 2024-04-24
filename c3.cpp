#include<bits/stdc++.h>
using namespace std;

long long n, sy, sx, dy, dx;
int a[5005][5005];
vector<long long > adj[5005];
bool visited[5005];

void inp(){
	cin >> n >> sy >> sx >> dy >> dx;
	adj[sy].push_back(sx);
	adj[sx].push_back(sy);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 0){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
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
	if(a[sy][sx] == 0 || a[dy][dx] == 1 || visited[dy] == false) cout << "NO";
	else cout << "YES";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
