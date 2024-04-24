#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t -- ){
		int a, b, c; cin >> a >> b >> c;
		if(abs(b-c) % 2 == 0) cout << "1 ";
		else cout << "0 ";
		if(abs(a-c) % 2 == 0) cout << "1 ";
		else cout << "0 ";
		if(abs(a-b) % 2 == 0) cout << "1" << "\n";
		else cout << "0" << "\n";
	}
	return 0;
}
