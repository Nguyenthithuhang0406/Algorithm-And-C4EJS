//thuat toan kiem tra do thi 2 phia
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1001];
int color[1001];

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	memset(color, -1, sizeof(color));
}

//0 : RED, 1: BLUE
bool bfs(int u){
	queue<int> q;
	q.push(u);
	color[u] = 0; //0: RED
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int x : ke[v]){
			if(color[x] == -1){
				color[x] = 1 - color[v];
				q.push(x);
			}
			else if(color[x] == color[v]) return false;
		}
	}
	return true;
}

bool dfs(int u, int par){
	color[u] = 1 - color[par];
	for(int v : ke[u]){
		if(color[v] == -1){
			if(!dfs(v,u)) return false;
		}
	}
	return true;
}
int main(){
	/*nhap();
	bool check = true;
	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			if(!bfs(i)){
				check = false; break;
			}
		}
	}
	if(check) cout << "YES \n";
	else cout << "NO \n";*/
	nhap();
	bool check = true;
	color[0] = 1;
	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			if(!dfs(i,0)){
				check = false; break;
			}
		}
	}
	if(check) cout << "YES \n";
	else cout << "NO \n";
}

