#include<bits/stdc++.h>
using namespace std;

vector<int> g[3000];
int n;
int par[3000];
int F[3000][3000];
int cnt[3000][3000];
	
	int parent[3000];
	
	void make_set(){
		for(int i = 1; i <= n; i++){
			parent[i] = i;
		}
	}
	
	int find(int v){
		if(v == parent[v]) return v;
		return parent[v] = find(parent[v]);
	}
	
	void Union(int a, int b){
		a = find(a);
		b = find(b);
		parent[a] = b;
	}

void dijkstra(int s){
	for(int i = 1; i <= n; i++) F[s][i] = INT_MAX;
	F[s][s] = 0;
	cnt[s][s] = 1;
	
	bool vis[3000];
	memset(vis, false, sizeof(vis));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	
	q.push({0,s});
	while(!q.empty()){
		pair<int, int> t = q.top();
		int w = t.first, v = t.second;
		//auto [w, v] = q.top();
		q.pop();
		
		if(vis[v]) continue;
		vis[v] = true;
		
		for(auto it : g[v]){
			if(w+1 < F[s][it]){
				F[s][it] = w+1;
				cnt[s][it] = cnt[s][v];
				q.push({F[s][it], it});
			}else if(w+1 == F[s][it]){
				cnt[s][it] += cnt[s][v];
			}
		}
	}
}

void solve(){
	int m;
	cin >> n >> m;
	vector<pair<int, int>> pa;
	make_set();
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		int U = u, V = v;
		
		u = find(u);
		v = find(v);
		
		if(u != v){
			g[U].push_back(V);
			g[V].push_back(U);
			Union(u,v);
		}else
			pa.push_back({U,V});
	}
	int res = INT_MAX;
	int c = 0;
	for(pair<int, int> i : pa){
		int u = i.first, v = i.second;
		dijkstra(u);
		int m = F[u][v];
		if(m+1 < res){
			res = m+1;
			c = cnt[u][v];
		}else if(m+1 == res) c += cnt[u][v];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << c ;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
