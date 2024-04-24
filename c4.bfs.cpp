#include<bits/stdc++.h>
using namespace std;

long long n, sy, sx, dy, dx;
int a[5005][5005];
bool visited[5005][5005];

void inp(){
	cin >> n >> sy >> sx >> dy >> dx;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++){
			cin >> a[i][j];
			visited[i][j] = false;
		}
}

void bfs(long long i, long j){
	queue<pair<long long, long long>> q;
	q.push({i,j});
	visited[i][j] = true;
	while(!q.empty()){
		pair<long long, long long> top = q.front();
		q.pop();
		i = top.first;
		j = top.second;

		if(i > 1 && a[i-1][j] == 0 && visited[i-1][j] == false)  {
			q.push({i-1, j});
			visited[i-1][j] = true;
		}
		if(i < n && a[i+1][j] == 0 && visited[i+1][j] == false)  {
			q.push({i+1, j});
			visited[i+1][j] = true;
		}
		if(j > 1 && a[i][j-1] == 0 && visited[i][j-1] == false)  {
			q.push({i, j-1});
			visited[i][j-1] = true;
		}
		if(j < n && a[i][j+1] == 0 && visited[i][j+1] == false)  {
			q.push({i, j+1});
			visited[i][j+1] = true;
		}
		
	}
}

void solve(){
	inp();
	bfs(sy, sx);
	if(a[sy][sx] == 0 || a[dy][dx] == 1 || visited[dy][dx] == false) cout << "NO";
	else cout << "YES";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
