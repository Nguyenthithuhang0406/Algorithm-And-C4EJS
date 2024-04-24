#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ask(int x, int y){
	cout << x << " " << y << "\n";
	
	ll res;
	cin >> res;
	return res;
}

void solve(){
	for(ll i = 1; i <= 7; i++){
		ll d1 = ask(0,0);
		if(d1 == 0) continue;
		ll d2 = ask(1,0);
		if(d2 == 0) continue;
		
		if(d1 >= d2){
			ll x = (d1 - d2 + 1) / 2;
			ll y = sqrt(d1 - x * x);
			ask(x,y);
		}else{
			ask(0, sqrt(d1));
		}
	}
	
}
int main(){
	solve();
}
