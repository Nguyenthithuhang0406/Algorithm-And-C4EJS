//2. BFS
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
bool visited[10001];

void inp(){
	cin >> n >> m; //doc so dinh va canh
	//bien doi ve danh sach ke
	for(int i = 0 ; i < m ; i++){
		int x, y;
		cin >> x >> y; //doc dinh dau va dinh cuoi cua canh
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
}

void bfs(int u){
	//khoi tao
	queue<int> q;
	q.push(u);
	visited[u] = true; //danh dau la da tham
	//lap
	while(!q.empty()){  // khi ma q khac rong
		int v = q.front(); // lay dinh o dau hang doi q
		q.pop();  // xoa dinh o dau di
		cout << v << " ";
		//duyet cac dinh ke cua dinh u
		for(int x : adj[v]){
			if(!visited[x]){ //neu chua duoc tham
				q.push(x);   //thi them vao hang doi
				visited[x] = true; //danh dau la da tham
			}
		}
	}
}

int main (){
	inp();
	bfs(1);
	return 0;
}
