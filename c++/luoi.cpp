//Dev ơi mình đi đâu thế?
/*
cho lưới sau:

A  o   o  x  o  o
o  x   o  o  o  o
o  x   o  o  o  o
o  o   o  o  x  x
B  o   o  o  x  o
o  o   o  x  x  x

trong đó: 'o' : có thể đi qua
          'x' : không thể đi qua

+Bài toán 1: kiểm tra xem có thể đi từ A đến B không
+Bài toán 2: tìm đường đi ngắn nhất từ A đến B
*/

//Bài toán 1: kiểm tra xem có thể đi từ A đến B không
#include<bits/stdc++.h>
using namespace std;

int n, m, u, v, s, t;
char a[1001][1001]; 
bool visited[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};


//sử dụng dfs
bool dfs(int i, int j){
	if(a[i][j] == 'B')  
		return true;
	a[i][j] = 'x';
	//duyet cac dinh ke
	for(int k = 0; k < 4; k ++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n  && j1 >= 1 && j1 <= m && a[i1][j1] != 'x'){
			if(dfs(i1,j1)) return true;
		}
	}
	return false;
}

//sử dụng bfs
bool bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'x';
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		//duyet cac dinh ke
		for(int k = 0; k < 4; k ++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x'){
				if(a[i1][j1] == 'B') return true;
				q.push({i1,j1});
				a[i1][j1] = 'x';
			}
		}
	}
	return false;
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

//Bài toán 2: tìm đường đi ngắn nhất từ A đến B
#include<bits/stdc++.h>
using namespace std;

int n, m, u, v, s, t;
char a[1001][1001]; //int a[1001][1001]
bool visited[1001][1001];
 int d[1001][1001];    //luu so buoc di tu ô bat  dau toi ô i,j

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i, j});
	a[i][j] = 'x';
	d[i][j] = 0;
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		//duyet cac dinh ke
		for(int k = 0; k < 4; k ++){
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x'){
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
