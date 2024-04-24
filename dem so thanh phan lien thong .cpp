

//dem so thanh phan lien thong
//ma gia
/*connectedComponent{
	// tao so thanh phan lien thong ban dau cua do thi = 0
	cnt = 0;
	//lap
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			cnt ++;  //tang so thanh phan lien thong
			dfs(i);  //bfs(i)
		}
	}
	return cnt;
}*/
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = true;
	cout << u << " ";
	for(int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

void connectedComponent(){
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i ++){
		if(!visited[i]){
			ans ++;
			//cout << "cac dinh thuoc thanh phan lien thong thu " << ans  << " : \n";
 			dfs(i);
		}
	}
	cout << ans << endl;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	connectedComponent();
	return 0;
}

/*
//cach 2: bfs
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";
		for(int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

void connectedComponent(){
	int ans = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			ans ++;
			cout << "cac dinh thuoc thanh phan lien thong thu " << ans << " : \n";
			bfs(i);
			cout << endl;
		}
	}
	if(ans == 1){
		cout << "do thi lien thong ! \n";
	}else{
		cout << "do thi khong lien thong ! \n";
	}
	return 0;
}
*/
