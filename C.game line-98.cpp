#include<bits/stdc++.h>
using namespace std;

long long n, sy, sx, dy, dx;
int a[50005][50005];
vector<pair<long long, long long>> adj[50005];
bool visited[50005][50005];

void inp(){
	cin >> n >> sy >> sx >> dy >> dx;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n ; i++)
		for(int j = 1; j <= n; j++)
			if(a[i][j] == 0){
				if(i > 1 && a[i-1][j] == 0){
					adj[{i,j}].push_back({i-1, j});
					adj[{i-1, j}].push_back({i,j});
				}
				if(i < n && a[i+1][j] == 0){
					adj[{i, j}].push_back({i+1,j});
					adj[{i+1, j}].push_back({i,j});
				}
				if(j > 1 && a[i][j-1] == 0){
					adj[{i,j}].push_back({i, j-1});
					adj[{i, j-1}].push_back({i,j});
				}
				if(j < n && a[i][j + 1] == 0){
					adj[{i,j}].push_back({i, j+1});
					adj[{i, j+1}].push_back(i,j);
				}
			}
	memset(visited, false, sizeof(visited));
}

void dfs(long long a, long long b){
	visited[a][b] = true;
	for(pair x : adj[{a,b}]){
		if(!visited[x.first][x.second]) dfs(x.first, x.second);
	}
}

void solve(){
	inp();
	dfs(sy, sx);
	if(a[dy][dx] == 1 || visited[dy][dx] == false) cout << "NO";
	else cout << "YES";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
