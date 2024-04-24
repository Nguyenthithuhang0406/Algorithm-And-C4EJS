// cho day a voi n phan tu
//1.cong tat ca cac so trong doan [l,r] len gia tri val
//2.in ra gia tri lon nhat cua cac so trong doan[l,r]
#include<bits/stdc++.h>
using namespace std;

int n, q;

//tao kieu du lieu cho mot nut
struct Node{
	int lazy; //gia tri T
	int val; //gia tri lon nhat
} nodes[800005];

//day gia tri T xuong cac con
void down(int id){
	int t = nodes[id].lazy;
	nodes[id*2].lazy += t;
	nodes[id*2].val += t;
	
	nodes[id*2+1].lazy += t;
	nodes[id*2+1].val += t;
	
	nodes[id].lazy = 0;
}

//Ham cap nhat
void update(int id, int l, int r, int u, int v, int val){
	if(v < l || r < u) return;
	
	//cac nut duoc cap nhat dong thoi voi gia tri lazy 
	if(u <= l && r <= v){
		nodes[id].val += val;
		nodes[id].lazy += val;
		return;
	}
	
	int mid = (l+r)/2;
	
	down(id); //day gia tri lazy xuong cac con
	
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);
	
	nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}

//ham lay gia tri lon nhat
int get(int id, int l, int r, int u, int v){
	if(v < l || r < u) return -INT_MAX;
	
	if(u <= l && r <= v) return nodes[id].val;
	
	int mid = (l+r)/2;
	down(id);
	
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		update(1, 1, n, i, i, a);
	}
	while(q--){
		int k, l, r, val;
		cin >> k;
		if(k == 1) {
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val); 
		}
		if(k == 2){
			cin >> l >> r;
			cout << get(1, 1, n, l, r) << "\n";
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
