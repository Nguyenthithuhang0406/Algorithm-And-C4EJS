#include<bits/stdc++.h>
using namespace std;

int  n, m;
set<int> adj[1005];
int degree[1005];

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
		degree[x] ++;
		degree[y] ++;
	}
}

void euler(int v){
	stack<int> st;
	vector<int> EC;
	st.push(v);
	while(!st.empty()){
		int x = st.top();
		if(adj[x].size() != 0){
			int y = *adj[x].begin();
			st.push(y);
			//xoa (x,y)
			adj[x].erase(y);
			adj[y].erase(x);
		}else{
			st.pop();
			EC.push_back(x);
		}
	}
	reverse(begin(EC), end(EC));
	for(int x : EC) cout << x << " ";
}

int main(){
	nhap();
	euler(1);
	return 0;
}


