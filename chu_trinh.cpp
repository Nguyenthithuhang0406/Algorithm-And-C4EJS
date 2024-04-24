//kiem tra co chu trinh hay khong - do thi vo huong(do thi lien thong)
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

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
		if(!visited[u]){
			if(dfs(v,u)) return true;
		}
		else if(v != par){     //ton tai canh nguoc(v,u)
			return true;
		}	}
	return false;
}
/*
bool bfs(int u){
	visited[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v = q.front();
		p.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push();
				visited[x] = true;
				parent[x] = v''
			}
			else if(x != parent[v]) return true;
		}
	}
	return false;
}
*/
int main(){
	inp();
	for(int i = 1; i <= n; i++){   //ap dung cho do thi khong lien thong
		if(!visited[i]){
			if(dfs(i,0)){
				cout << "YES \n";
				return 0;
			}
		}
	}
	cout << "NO \n";
	return 0;
}

/*
//truong hop dung mang parent rieng
int n, m;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

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

bool dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			if(dfs(v)) return true;
		}
		else if(v != parent[u]) return true;
	}
	return false;
}

int main(){
		inp();
	for(int i = 1; i <= n; i++){   //ap dung cho do thi khong lien thong
		if(!visited[i]){
			if(dfs(i)){
				cout << "YES \n";
				return 0;
			}
		}
	}
	cout << "NO \n";
}
*/



//in ra chu trinh
#include<bits/stdc++.h>
using namespace std;

int n, m, st, en;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

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

bool dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			if(dfs(v)) return true;
		}
		else if(v != parent[u]){
			st = u;
			en = v;
			return true;
		}
	}
	return false;
}

int main(){
	inp();
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			if(dfs(i)){
				cout << "YES \n";
				vector<int> cycle;
				cycle.push_back(st);
				while(en != st){
					cycle.push_back(en);
					en = parent[en];
				}
				reverse(cycle.begin(), cycle.end());
				for(int x : cycle){
					cout << x << " ";
				}
				return 0;
			}
		}
	}
}
