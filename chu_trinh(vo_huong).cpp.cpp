//kiem tra co chu trinh hay khong (do thi lien thong)
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
//dung mang parent rieng
//int parent[200005]

void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

bool dfs(int u, int par){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			//parent[v] = u;
			if(dfs(v,u)) return true;
		}
		else if(v != par){  // v != parent[u]
			return true;
		}
	}
	return false;
}

int main(){
	inp();
	if(dfs(1,0)){
		cout << "YES \n";
	}else cout << "NO \n";
	return 0;
}
