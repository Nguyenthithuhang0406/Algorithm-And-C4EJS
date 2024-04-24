//Thuat toan Kruskal su dung cau truc du lieu cac tap hop roi nhau_Disjoint Set Union DSU / Union Find
//tim tong duong di ngan nhat de noi cac dinh
#include<bits/stdc++.h>
using namespace std;

struct edge{
	int u, v;
	int w;
};

const int maxn = 1001;
int n, m;
int parent[maxn], sz[maxn];   //sz[maxn] :  kich thuoc cua moi tap hop
vector<edge> canh;  //luu cac canh cua tap hop

//cau truc Disjoint Set Union
void make_set(){
	for(int i = 1; i <= n; i ++){
		parent[i] = i;     //coi moi dinh la mot tap hop rieng biet voi cha la chinh no
		sz[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;  //vi a == b nen chung cung 1 tap hop roi nen khong gop duoc nua
	if(sz[a] < sz[b]) swap(a,b);
	parent[b] = a;   //gop tap hop it phan tu hon vao tap hop nhieu phan tu hon
	sz[a] += sz[b]; //sz tap hop moi la tong kich thuoc ca 2 tap hop
	return true;
}

//nhap input
void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		//edge e = edge(x,y,w);
		edge e;
		e.u = x; e.v = y; e.w = w;
		canh.push_back(e);
	}
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void kruska(){
	//tao cay khung cuc tieu rong
	vector<edge> mst;
	int d = 0;
	//sort danh sach canh theo chieu dai tang dan
	sort(canh.begin(), canh.end(), cmp);
	//buoc 3: lap
	for(int i = 0; i < m; i++){
		if(mst.size() == n-1) break;
		edge e = canh[i]; //chon canh e la canh nho nhat
		if(Union(e.u, e.v)){
			mst.push_back(e);
			d += e.w;
		}
	}
	//tra ve ket qua
	if(mst.size() != n-1){
		cout << "do thi khong lien thong! \n";
	}else{
		cout << "MST : " << d << endl;
		for(auto it : mst){
			cout << it.u << " " << it.v << " " << it.w << endl;
		}
	}
}

int main(){
	inp();
	make_set();
	kruska();
}

