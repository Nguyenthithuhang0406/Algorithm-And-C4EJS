//kiem tra tinh lien thong manh(luon co 1 duong di giua hai dinh bat ki)
//thuat toan Kosaraju
//buoc1: DFS trên G -> luu vao 1 stack
//buoc 2: xay dung TG
//buoc 3: pop cac dinh trong stack o b1 va goi DFS tren TG

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n, m;
vector<int> adj[maxn], r_adj[maxn];
bool visited[maxn];
stack<int> st;

//nhap input
void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		r_adj[y].push_back(x);
	}
}

void dfs1(int u){   //dfs o buoc 1
	visited[u] = true;
	for(int v : adj[u]){
		if(!visited[v]){
			dfs1(v);
		}
	}
	//da duyet xong dinh u
	cout << u << " ";
	st.push(u);   //day u vao trong stack
}

void dfs2(int u){  //dfs su dung o buoc 3
	visited[u] = true;
	cout << u << " ";
	for(int v : r_adj[u]){
		if(!visited[v]){
			dfs2(v);
		}
	}
}

void SCC(){
	memset(visited, false, sizeof(visited));
	//b1: goi thuat toan dfs tren do thi ban dau
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs1(i);
		}
	}
	cout << endl;
	memset(visited, false, sizeof(visited));
	//int cnt = 0;
	while(!st.empty()){   //trong khi stack chua rong
		int u = st.top(); //lay dinh o dau stack ra
		st.pop();  //pop ra khoi stack
		if(!visited[u]){
		//	cnt++;
			dfs2(u);
			cout << endl;
		}
	}
	//if(cnt == 1) cout << "yes \n";
	//else cout << "no \n";
}

int main(){
	inp();
	SCC();
}
