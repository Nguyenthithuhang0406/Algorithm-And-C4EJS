#include<bits/stdc++.h>
using namespace std;

long long p[10001];
int n, m;
long long f[1001][1001];

long long kt(int i, int j){
	if(f[i][j] != 0) return f[i][j];
	if(i==j) return p[i] * n;
	f[i][j] = min(kt(i+1,j) + p[i] * (i+n-j), kt(i, j-1) + p[i] * (i+n-j));
	return f[i][j];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	cout << kt(1, n);
	return 0;
}
