
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int base = 31;
const long long MOD = 10000007;



int main(){
	/*ll s, t;
	cin >> s >> t;
	
	vector<ll> a;
	while(s > 0){
		a.push_back(s % 10);
		s /= 10;
	}
	a.push_back(-1);
	reverse(a.begin(), a.end());
	
	ll n = a.size(), m = log10(t) + 1;
	vector<ll> pref(n+1);
	for(ll i = 1; i <= n; i++){
		pref[i] = pref[i-1] * 10 + a[i];
	}
	
	ll res = 0;
	for(ll i = 1; i < n - m; i++){
		ll x = pref(i + m -1) - pref[i - 1] * pow(10, m);
		if(x == t){
			res ++;
		}
	}
	
	cout << res;*/
	
	//tim 1 so trong 1 so khac o(n);
	
	//tim mot xau trong mot xau khac
	
	string s, t;
	cin >> s >> t;
	s = "*" + s;
	t = "*" + t;
	
	ll n = s.size(), m = t.size();
	ll hashS = 0, hashT = 0;
	for(ll i = 1; i < n; i++){
		hashS = hashS * base % MOD + (s[i] - 'a' + 1) % MOD;
	}
	for(ll i = 1; i < m; i++){
		hashT = hashT * base % MOD + (t[i] - 'a' + 1) % MOD;
	}
	
	vector<ll> pref(n+1);
	for(ll i = 1; i < n; i++){
		pref[i] = pref[i - 1] * base % MOD + (s[i] - 'a' + 1) % MOD;
	}
	
	ll p = 1;
	for(ll i = 0; i < m - 1; i++){
		p = p * base % MOD;
	}
	
	ll res = 0;
	for(ll i =1; i <= n - m + 1; i++){
		ll x = (pref[i + m -2] - pref[i -1] * p % MOD + MOD) % MOD;
		if(x == hashT){
			res ++ ;
		}
	}
	
	cout << res;
}


