#include<bits/stdc++.h>
using namespace std;

int p[1001];
vector<pair<int, int>> adj[1001];
void xuly(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j ++){
			if(j != i) {
				int chiphi = i * p[j];
				adj[i].push_back({j, chiphi});
			}
		}
	}
}

int pre[1001];

long long dijkstra(int s, int t){
	//luu kc duong di
	vector<long long> d(n+1, INT_MAX);
	d[s] = 0;
	pre[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	While(!Q.empty()){
		//chon ra dinh co kc tu s nho nhat
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		
		//cap nhat khoang cach tu s cho toi moi dinh ke voi u
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
	return d[t];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m ; cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> p[i];
	}
	xuly();
	if(dijkstra(1,n) > m) cout << "YES";
	else cout << "NO";
	return 0;
}
