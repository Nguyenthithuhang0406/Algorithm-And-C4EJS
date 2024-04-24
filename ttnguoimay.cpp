#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ask(int x, int y){
	cout <<"?" << x << " " << y << "\n";
	
	ll res;
	cin >> res;
	return res;
}

void solve(){
	int a[] = {4,8,15,16,23,42};
	ll res[6] = {};
	
	ll x = ask(1,2);
	ll y = ask(1,3);
	for(ll i = 0; i <  6; i++){
		for(ll j = i+1; j < 6; j++){
			if(a[i] * a[j] == x){
				res[1] = a[i];
				res[2] = a[j];
			}
		}
	}
	for(ll i = 0; i <  6; i++){
		for(ll j = i+1; j < 6; j++){
			if(a[i] * a[j] == y){
				if(res[1] != a[i]){
					swap(res[1],res[2]);
				}
				res[3] = a[j];
			}
		}
	}
	
	 x = ask(4,5);
	 y = ask(4,6);
	for(ll i = 0; i <  6; i++){
		for(ll j = i+1; j < 6; j++){
			if(a[i] * a[j] == x){
				res[4] = a[i];
				res[5] = a[j];
			}
		}
	}
	for(ll i = 0; i <  6; i++){
		for(ll j = i+1; j < 6; j++){
			if(a[i] * a[j] == y){
				if(res[4] != a[i]){
					swap(res[4],res[5]);
				}
				res[6] = a[j];
			}
		}
	}
	
	cout << "! ";
	for(int i = 1; i <= 6; i++){
		cout << res[i] << " ";
	}
}
int main(){
	solve();
}
