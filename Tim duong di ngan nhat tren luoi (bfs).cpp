
//bai toan 3: tim duong di ngan nhat giua hai diem tren luoi
#include<bits/stdc++.h>
using namespace std;

int n, m, u, v, s, t;
char a[1001][1001]; //int a[1001][1001]
bool visited[1001][1001];
 int d[1001][1001];    //luu so buoc di tu o bat  dau toi o i,j

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'x';
	d[i][j] = 0;
	//cout << i << " " << j << endl;
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		//duyet cac dinh ke
		for(int k = 0; k < 4; k ++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x'){
			//	cout << i1 << " " << j1 << endl;
				d[i1][j1] = d[top.first][top.second] + 1;
				if(a[i1][j1] == 'B') return;
				q.push({i1,j1});
				a[i1][j1] = 'x';
			}
		}
	}
}

void inp(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'A'){
				s = i; t = j;
			}
			else if(a[i][j] == 'B'){
				u = i; v = j;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	bfs(s, t);
	if(!d[u][v]){
		cout << "khong co duong di ! \n";
	}else{
		cout << d[u][v] << endl;
	}
}

