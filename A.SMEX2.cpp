#include<bits/stdc++.h>
using namespace std;

long long a[50000];
void dem(int l, int n, long long a[], long long res){
	long long min = 1000000000;
	int h = 0;
	
	for(int i = l; i <= n-1; i++){
		if(a[i] < min){
			min = a[i];
			h = i; 
		}
	}
	res += n-1 - h;
	if(h < n-1){
		dem(h+1, n, a, res);
	}else{
		cout << res;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long res = 0;
	for(int i = 1; i <= n; i++ ){
		cin >> a[i];
	}
	dem(1, n, a, res);
	return 0;
}
