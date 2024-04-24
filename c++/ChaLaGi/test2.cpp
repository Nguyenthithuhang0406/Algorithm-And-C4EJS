#include<bits/stdc++.h>
using namespace std;

int n, m; 
int p[11];
int per[11];
bool check[101] = {};
int mi = INT_MAX;
void pergen(int ix){
	if (ix > n){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			sum += i * p[per[i]];
		}
			mi = min(mi, sum);
			return;
	}
	for (int i = 1; i <= n; i++){
		if (check[i] == false){
			check[i] = true;
			per[ix] = i;
			pergen(ix+1);
			check[i] = false;
		}
	}
		
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	pergen(1);
	if(mi > m) cout << "YES" ;
	else cout << "NO";
	return 0;
}
