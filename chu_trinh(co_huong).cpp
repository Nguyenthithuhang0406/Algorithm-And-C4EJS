//kiem tra chu trinh-do thi co huong
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];

void inp(){
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(color, 0, sizeof(color));
}

bool dfs(int u){
	color[u] = 1; //mau xam
	for(int v : adj[u]){
		if(color[v] == 0){
			if(dfs(v)) return true;
		}
		else if(color[v] == 1) return true;
	}
	color[u] = 2; //mau den
}

int main(){
	inp();
	for(int i = 1; i <= n; i++){
		if(color[i] == 0){
			if(dfs(i)){
				cout << "YES \n";
				return 0;
			}
		}
	}
	cout << "NO \n";
}


//kiem tra theo kahn
int n, m;
vector<int> adj[1001];
int degree[1001];   //ban bac vao tai dinh i

void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		degree[y]++;
	}
}

bool kahn(){
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(degree[i] == 0) 
			q.push(i);
	}
	int cnt = 0;  //cnt dem so dinh da duyet
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cnt++;
		for(int x : adj[v]){
			degree[x] -- ;
			if(!degree[x])
					q.push(x);
		}
	}
	if(cnt == n){
		return false;
	}
	return true;
}

int main(){
	inp();
	if(kahn()) cout << "YES \n";
	else{
		cout << "NO \n";
	}
	return 0;
}

