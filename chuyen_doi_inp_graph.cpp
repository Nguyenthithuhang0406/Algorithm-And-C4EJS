//1. chuyen danh sach canh sang danh sach ke 
#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[10001];
//adj[j] : luu danh sach ke cua dinh i

int main(){
	cin >> n >> m;  // nhap so dinh n va so canh m cua do thi
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;   // nhap dinh dau va dinh cuoi cua canh thu i
		adj[x].push_back(y); //them dinh y vao danh sach ke cua dinh x
		adj[y].push_back(x); //them dinh x vao danh sach ke cua dinh y
		//neu la do thi co huong thi bo adj[y].push_back(x);
		
	}
	for(int i = 1; i <= n; i++){
		cout << i << ":";
		for(int x : adj[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}

//2.chuyen danh sach canh sang ma tran ke
#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[10001][10001];

int main(){
	cin >> n >> m;  // nhap so dinh n va so canh m cua do thi
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;   // nhap dinh dau va dinh cuoi cua canh thu i
		a[x][y] = a[y][x] = 1;
		
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//3. chuyen ma tran ke sang danh sach canh
#include<bits/stdc++.h>
using namespace std;

int n; 
vector<pair<int, int>> edge; // edge luu danh sach canh
int a[10001][10001]; // ma tran ke

int main(){
	cin >> n; // nhap so dinh
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j] ; //doc ma tran ke
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1 && i < j){
				edge.push_back({i,j}); //them canh i j  vao edge
			}
		}
	}
	for(auto it : edge){
		cout << it.first << " " << it.second << endl;
	}
} 

//4. chuyen ma tran ke sang danh sach ke
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<pair<int, int>> edge;
int a[10001][10001];

int main(){
	int n;
	cin >> n; //nhap so dinh
	//nhap ma tran ke
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j]; 
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 1){
				adj[i].push_back(j); //them dinh j vao danh sach ke cua dinh i
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << i << ":";
		for(int x : adj[i]){
			cout << x << " ";
		}
		cout << endl;
	}
}

//5. chuyen doi danh sach ke sang ma tran ke
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[10001];
//adj[j] : luu danh sach ke tai dinh j
int a[10001][10001];

int main(){
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s, num;
		getline(cin,s);
		stringstream ss(s); //tach chuoi
		while(ss > num){
			a[i][stoi(num)] = 1;   //stoi(num) : chuyen xau num ve so
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

//6. chuyen danh sach ke ve danh sach canh
#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> edge;
int a[10001][10001];

int main(){
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s, num;
		getline(cin,s);
		stringstream ss(s); //tach chuoi
		while(ss > num){
			if(stoi(num) > i){
				edge.push_back({i, stoi(num)});
			}
		}
	}
	for(auto it : edge){
		cout << it.first << " " << it.second << endl;
	}
}


 
