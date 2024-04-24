#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[100];
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n % 2 == 0) cout << (a[n/2] + a[n/2 + 1]) * 1.0 / 2;
	else cout << a[n/2 + 1]; 
	return 0;
}
