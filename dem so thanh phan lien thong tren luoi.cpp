
//bai toan 1: dem so thanh phan lien thong tren luoi
#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];   //int a[1001][1001]
bool visited[1001][1001];

//          i-1,j
//  i,j-1   i,j     i,j+1
//			i+1,j

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};    //dx, dy phai theo cap

void dfs(int i, int j){
	cout << i << " " << j << endl;
	visited[i][j] = true;
	//duyet cac dinh ke
	for(int k = 0; k < 4; k ++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]){
			dfs(i1,j1);
		}
	}
}

void inp(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	} 
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'x' && !visited[i][j]){
				cout << "thanh phan lien thong thu " << cnt + 1 << " : " << endl;
				dfs(i,j);
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
}
int main(){
	inp();
	return 0;
}

/*
//bai toan 1: dem so thanh phan lien thong tren luoi
//cach 2: dung bfs
#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[1001][1001];   //int a[1001][1001]
bool visited[1001][1001];

//          i-1,j
//  i,j-1   i,j     i,j+1
//			i+1,j

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};    //dx, dy phai theo cap

void bfs(int i, int j){
	queue<pair<int, int>> q;
	q.push({i,j});
	a[i][j] = 'o';
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		//duyet cac dinh ke
		for(int k = 0; k < 4; k ++){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]){
				q.push({i1,j1});
				a[i1][j1] = 'o';
			}
		}
	}
}

void inp(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	} 
	memset(visited, false, sizeof(visited));
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'x' && !visited[i][j]){
				cout << "thanh phan lien thong thu " << cnt + 1 << " : " << endl;
				bfs(i,j);
				cnt ++;
			}
		}
	}
	cout << cnt << endl;
}
int main(){
	inp();
	return 0;
}
*/
