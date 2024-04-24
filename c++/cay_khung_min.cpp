// Thuật toán Kruskal
#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int u, v;
	int w;
};

int n, m;
int parent[1001], sz[1001]; // sz[1001]: kích thước của mỗi tập hợp
vector<edge> canh;			// lưu các cạnh của tập hợp

// cấu trúc Disjoint Set Union
void make_set()
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i; // coi mỗi đỉnh là một tập hợp riêng biệt
		sz[i] = 1;
	}
}

int find(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return false; // vì a == b nên chúng cùng chung 1 tập hợp rồi nên không gộp được nữa
	if (sz[a] < sz[b])
		swap(a, b); // mục đích: gộp tập hợp ít phần tử hơn vào tập hợp nhiều phần tử hơn
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

// nhập input
void inp()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		edge e;
		e.u = x;
		e.v = y;
		e.w = w;
		canh.push_back(e);
	}
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

void kruskal()
{
	// tạo cây khung cực tiểu rỗng
	vector<edge> mst;
	int d = 0;
	// sort danh sách cạnh theo chiều dài tăng dần
	sort(canh.begin(), canh.end(), cmp);
	// bước 3: lặp
	for (int i = 0; i < m; i++)
	{
		if (mst.size() == n - 1)
			break;
		edge e = canh[i]; // chọn cạnh e là cạnh nhỏ nhất
		if (Union(e.u, e.v))
		{
			mst.push_back(e);
			d += e.w;
		}
	}
	// trả về kết quả
	if (mst.size() != n - 1)
	{
		cout << "Do thi khong lien thong ! \n";
	}
	else
	{
		cout << "MST : " << d << endl;
		for (auto it : mst)
		{
			cout << it.u << " " << it.v << " " << it.w << endl;
		}
	}
}

int main()
{
	inp();
	make_set();
	kruskal();
}

//
// cay khung cuc tieu
// thuat toan PRIM
// code binh thuong

#include <bits/stdc++.h>
using namespace std;

struct canh
{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001]; // used[i] = true : i thuoc tap V(MST), used[i] = false: i thuoc tap V

void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
}

void prim(int u)
{
	vector<canh> MST; // cay khung
	int d = 0;		  // chieu dai cay khung
	used[u] = true;	  // dua u vao tap V(MST)
	while (MST.size() < n - 1)
	{
		// e = (x,y) : canh ngan nhat co x thuoc V va y thuoc V(MST)
		int min_w = INT_MAX;
		int X, Y; // luu 2 dinh cua canh e
		for (int i = 1; i <= n; i++)
		{
			// neu dinh i thuoc tap V(MST)
			if (used[i])
			{
				// duyet danh sach ke cua dinh i
				for (pair<int, int> it : adj[i])
				{
					int j = it.first, trongso = it.second;
					if (!used[j] && trongso < min_w)
					{
						min_w = trongso;
						X = j;
						Y = i;
					}
				}
			}
		}
		MST.push_back({X, Y, min_w});
		d += min_w;
		used[X] = true; // cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << d << endl;
	for (canh e : MST)
	{
		cout << e.x << " " << e.y << " " << e.w << endl;
	}
}

int main()
{
	nhap();
	prim(1);
}

// sd hang doi uu tien

#include <bits/stdc++.h>
using namespace std;

struct canh
{
	int x, y, w;
};

int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001]; // used[i] = true : i thuoc tap V(MST), used[i] = false: i thuoc tap V
int parent[1001], d[1001];

void nhap()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++)
	{
		d[i] = INT_MAX;
	}
}

void prim(int u)
{ // sd hang doi uu tien
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	vector<canh> MST;
	int res = 0;
	Q.push({0, u});
	while (!Q.empty())
	{
		pair<int, int> top = Q.top();
		Q.pop();
		int dinh = top.second, trongso = top.first;

		if (used[dinh])
			continue;
		res += trongso;
		used[dinh] = true;
		if (u != dinh)
		{
			MST.push_back({dinh, parent[dinh], trongso});
		}
		// duyet tat ca cac dinh ke
		for (auto it : adj[dinh])
		{
			int y = it.first, w = it.second;
			if (!used[y] && w < d[y])
			{
				Q.push({w, y});
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for (auto it : MST)
	{
		cout << it.x << " " << it.y << " " << it.w << endl;
	}
}

int main()
{
	nhap();
	prim(1);
}
