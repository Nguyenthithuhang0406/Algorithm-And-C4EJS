//thuat toan Dijkstra
//tim duong di ngan nhat tu 1 dinh S toi moi dinh con lai tren do thi
//do phuc tap O((E+V)logV)

#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<pair<int, int>> adj[1001];

void nhap(){
	cin >> n >> m >> s >> t;
	
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y,w});
		//adj[y].push_back({x,w});
	}
}

const long long INF = 1e9;
int pre[1001];

void dijkstra(int s, int t){
	//mang luu khoang cach duong di
	vector<long long> d(n+1, INF);
	d[s] = 0;
	pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		//chon ra dinh co khoang cach tu s nho nhat
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u])  continue;
		//relaxation : cap nhat khoang cach tu s cho toi moi dinh ke voi u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u; //truoc v la u
			}
		}
	}
	cout << d[t] << endl;
	vector<int> path;
	while(1){
		path.push_back(t);
		if(t == s) break;
		t = pre[t];
	}
	reverse(begin(path), end(path));
	for(int x : path){
		cout << x << " ";
	}
	/*for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}*/
}
int main(){
	nhap();
	dijkstra(s,t);
}
