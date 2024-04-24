#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	long long a, b; cin >> a >> b;
	vector<long long> cs;
	cs.push_back(b);
	while(b > a){
		if(b%10 == 1) cs.push_back(b/10), b /= 10;
		else{
			cs.push_back(b / 2);
			b /= 2;
		}
	}
	if(a == b) {
		cout << "YES" << "\n";
		cout << cs.size() << "\n";
		reverse(cs.begin(), cs.end());
		for(auto x : cs) cout << x << " ";
	}else{
		cout << "NO";
	}
	return 0;
}
