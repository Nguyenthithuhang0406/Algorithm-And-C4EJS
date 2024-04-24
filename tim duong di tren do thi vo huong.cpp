#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			//ghi nhan cha cua v la u
			parent[v] = u;
			dfs(v);
		}
	} 
}

void Path(int s, int t){
	memset(visited, false, sizeof(visited));
	memset(parent, 0 , sizeof(parent));
	dfs(s);
	if(!visited[t]){
		cout << "Khong co duong di !";
	}else{
		//truy vet duong di
		vector<int> path;
		//bat dau tu dinh t;
		while(t != s){
			path.push_back(t);
			//lat nguoc lai
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end()); //dao nguoc duong di
		for(int x : path){
			cout << x << " ";
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> s >> t;
	Path(s,t);
	return 0;
}

/*
//cach 2: voi bfs
#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}
		}
	}
}

void Path(int s, int t){
	memset(visited, false, sizeof(visited));
	memset(parent, 0 , sizeof(parent));
	bfs(s);
	if(!visited[t]){
		cout << "Khong co duong di !";
	}else{
		//truy vet duong di
		vector<int> path;
		//bat dau tu dinh t;
		while(t != s){
			path.push_back(t);
			//lat nguoc lai
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end()); //dao nguoc duong di
		for(int x : path){
			cout << x << " ";
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> s >> t;
	Path(s,t);
	return 0;
}
*/
