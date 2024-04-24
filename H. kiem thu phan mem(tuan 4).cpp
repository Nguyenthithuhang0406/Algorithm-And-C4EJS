#include <bits/stdc++.h>
using namespace std;

	long long a[100000] = {};
	long long b[100000] = {};
	long long c[100000] = {};
	map<long long , int > mp1;
	map<long long, int> mp2;
int main (int argc, char ** argv){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >>n;
	for (int i = 1; i <= n ; i++){
		cin >> a[i];
		mp1[a[i]]++;
	}
	for (int i = 1; i <= n - 1 ; i++){
		cin >> b[i];
		mp1[b[i]]--;
		mp2[b[i]]++;
	}
	for (int i = 1; i <= n - 2 ; i++){
		cin >> c[i];
		mp2[c[i]] --;
	}
	int i = 1;
	while (i <= n){
		if (mp1[a[i]] > 0){
			cout << a[i] << endl;
			break;
		} else {
			i++;
		}
	}
	 i = 1;
	while (i <= n){
		if (mp2[b[i]] > 0){
			cout << b[i] ;
			break;
		} else {
			i++;
		}
	}
	return 0;
} 
