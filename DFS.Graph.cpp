//1. DFS
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
bool visited[10001];

void inp(){
	cin >> n >> m; //nhap so dinh va canh
	//chuyen input ve danh sach ke
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;  //doc dinh dau va cuoi moi canh
		adj[x].push_back(y);
		adj[y].push_back(x);
		//neu ma do thi co huong thi bo adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void dfs(int u){
	cout << u << " ";
	//danh dau la u da duoc tham
	visited[u] = true;
	//duyet cac dinh v la dinh ke cua dinh u
	for(int v : adj[u]){
		//neu dinh v chua duoc den tham
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main(){
	inp();
	dfs(1);
}
