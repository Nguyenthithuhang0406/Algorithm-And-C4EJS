#include<bits/stdc++.h>
using namespace std;

int n; long long a[100005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	a[n+1] = 0;
	long long ma = 0;
	long long mi = INT_MAX;
	long long  i = 1, j = 1;
	while(i <= n){
		while(a[i+1] - a[i] >= 0 && a[i+1] - a[i] <= 2 ) i++;
		ma = max(ma, i - j + 1);
		mi = min(mi, i-j + 1);
		i++; j = i;
	}
	cout << mi << " " << ma;
	return 0;
}
