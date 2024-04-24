#include<bits/stdc++.h>
using namespace std;

int a[105], b[105];

int main(){
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	int cnt = 0;
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(abs(a[i] - b[j]) <= 1 && a[i] > 0 && b[j] > 0) {
				cnt ++ ;
				a[i] = 0;
				b[j] = 0;
			}
		}
	}
	cout << cnt ;
}
