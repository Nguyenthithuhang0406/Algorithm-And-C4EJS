//cay khung cuc tieu
//thuat toan PRIM
//code trau
/*
#include<bits/stdc++.h>
using namespace std;

struct canh{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001];     //used[i] = true : i thuoc tap V(MST), used[i] = false: i thuoc tap V

void nhap(){
	cin >> n  >> m;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	memset(used, false, sizeof(used));
}

void prim(int u){
	vector<canh> MST;  //cay khung
	int d = 0; //chieu dai cay khung
	used[u] = true;  //dua u vao tap V(MST)
	while(MST.size() < n - 1){
		//e = (x,y) : canh ngan nhat co x thuoc V va y thuoc V(MST)
		int min_w = INT_MAX;
		int X,Y; //luu 2 dinh cua canh e
		for(int i = 1; i <= n; i++){
			//neu dinh i thuoc tap V(MST)
			if(used[i]){
				//duyet danh sach ke cua dinh i
				for(pair<int, int> it : adj[i]){
					int j = it.first, trongso = it.second;
					if(!used[j] && trongso < min_w){
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST.push_back({X, Y , min_w});
		d += min_w;
		used[X] = true; //cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << d << endl;
	for(canh e : MST){
		cout << e.x << " " << e.y<< " " << e.w << endl;
	}
}

int main(){
	nhap();
	prim(1);
}
*/
//sd hang doi uu tien 

#include<bits/stdc++.h>
using namespace std;

struct canh{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001];     //used[i] = true : i thuoc tap V(MST), used[i] = false: i thuoc tap V
int parent[1001], d[1001];

void nhap(){
	cin >> n  >> m;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n ; i++){
		d[i] = INT_MAX;
	}
}

void prim(int u){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	vector<canh> MST;
	int res = 0;
	Q.push({0,u});
	while(!Q.empty()){
		pair<int,int> top = Q.top(); Q.pop();
		int dinh = top.second, trongso = top.first;
		
		if(used[dinh]) continue;
		res += trongso;
		used[dinh] = true;
		if(u != dinh){
			MST.push_back({dinh, parent[dinh], trongso});
		}
		//duyet tat ca cac dinh ke
		for(auto it : adj[dinh]){
			int y = it.first, w = it.second;
			if(!used[y] && w < d[y]){
				Q.push({w,y});
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for(auto it : MST){
		cout << it.x << " " << it.y << " " << it.w << endl;
	}
}

int main(){
	nhap();
	prim(1);
}

 

