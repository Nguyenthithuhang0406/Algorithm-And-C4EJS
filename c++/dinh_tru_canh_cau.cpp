//kiem tra dinh tru va canh cau
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		dscanh.push_back({x,y});
	}
//	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v])  dfs(v);
	}
}

void dinhtru(){
	int ans = 0;
	int tplt = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++tplt;
			dfs(i);
		}
	}
	for(int i = 1; i <= n; i++){
		//loai bo dinh i khoi do thi
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		int dem = 0;  //dem tplt sau khi loai bo dinh i
		for(int j = 1; j <= n; j++){
			if(!visited[j]){
				++dem;
				dfs(j);
			}
		}
		if(dem > tplt){
			cout << i << " ";
			++ans;
		}
	}
	cout << "\n" << ans << endl;
}

void dfs2(int u, int s, int t){
	visited[u] = true;
	for(int v : adj[u]){
		if((u == s && v == t ) || (u == t && v == s)) continue; //loai bo canh s t
		if(!visited[v])  dfs2(v, s, t);
	}
}

void canhcau(){
	int ans = 0;
	int tplt = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1 ; i <= n; i++){
		if(!visited[i]){
			++tplt;
			dfs(i);
		}
	}
	for(auto it : dscanh){
		int x = it.first, y = it.second;
		//loai bo canh (x,y) khoi do thi
		memset(visited, false, sizeof(visited));
		int dem = 0;
		for(int j = 1; j <= n; j ++){
			if(!visited[j]){
				++dem;
				dfs2(j, x, y);
			}
		}
		if(dem > tplt){
			++ans;
			cout << x << " " << y << '\n';
		}
	}
	cout << "\n"<< ans << endl;
}
int main(){
	nhap();
	//dinhtru();
	canhcau();
}