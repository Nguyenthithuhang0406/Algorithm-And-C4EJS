#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		long long a, b, c; cin >> a>> b>> c; 
		if(a!= b && a!= c && b == c) cout << a << "\n";
		if(b!= a && b!= c && a==c) cout << b << "\n";
		if(c!= a && c!= b && a== b) cout << c << "\n";
	}
	return 0;
}
