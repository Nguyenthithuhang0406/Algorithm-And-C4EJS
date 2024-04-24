#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n; cin >> n;
	long long cnt = n;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		mp[a] ++;
		if(mp[a-1] != 0) cnt--;
	}
	cout << cnt ;
	return 0;	
}
