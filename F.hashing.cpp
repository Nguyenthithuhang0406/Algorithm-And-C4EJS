#include<bits/stdc++.h>
using namespace std;

int main(){
	const int base = 31;
	const long long mod = 100000007;
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	s = "*" + s;
	int n = s.size();
	long long hashS = 0;
	
	vector<long long> pref(n+1);
	for(long long i = 1; i < n; i ++){
		pref[i] = pref[i - 1] * base % mod + (s[i] - 'a' + 1) % mod;
	}
		
	long long p = 1;
	for(int i = 1; i < n-1; i++){
		p = p * base % mod;
		long long x = (pref[n-1] - pref[n - i - 1] * p % mod + mod) % mod;
		if(pref[i] == x){
			cout << i << " ";
		}
	}
	return 0;
}
