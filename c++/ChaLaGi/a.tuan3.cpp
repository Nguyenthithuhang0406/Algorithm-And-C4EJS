#include<bits/stdc++.h>
using namespace std;

long long a[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	long long res = -1000000000;
	res = max(res, a[n] * a[n-1] * a[n-2]); //khong co so am
	res = max(res, a[1] * a[2] * a[n]);    //< 3 so duong
	cout << res;
	return 0;
}
