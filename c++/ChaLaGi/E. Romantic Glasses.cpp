#include<bits/stdc++.h>
using namespace std;

vector<long long> a, b;
long long pref_a[100005], pref_b[100005];
void solve(){
	int n; cin >> n;
	a.push_back(0);
	b.push_back(0);
	for(int i = 1; i <= n; i++){
		long long x; cin >> x;
		if(i%2) a.push_back(x);
		else b.push_back(x);
	}
	pref_a[0] = a[0];
	for(int i = 1; i < a.size(); i++) pref_a[i] = pref_a[i-1] + a[i];
	pref_b[0] = b[0]; 
	for(int i = 1; i < b.size(); i++) pref_b[i] = pref_b[i-1] + b[i];
	
//	for(int i = 1; i < a.size(); i++) cout << pref_a[i] << " ";
//	cout << "\n";
//	for(int i = 1; i < b.size(); i++) cout << pref_b[i] << " ";
//	cout << "\n";
	
	bool k = false;
	int i = 1; 
	while(i < n && k == false){
		int j = i+1;
		while(j <= n && k == false){
			if(i%2 == 0 && j % 2 == 0 && (pref_b[j/2] - pref_b[i/2-1]) == (pref_a[j/2] - pref_a[i/2])){
				k = true;
			}
			if(i%2 == 0 && j % 2 != 0 && (pref_b[j/2] - pref_b[i/2-1]) == (pref_a[j/2 + 1] - pref_a[i/2])){
				k = true;
			}
			if(i%2 != 0 && j % 2 == 0 && (pref_b[j/2] - pref_b[i/2]) == (pref_a[j/2] - pref_a[i/2 ])){
				k = true;
			}
			if(i%2 != 0 && j % 2 != 0 && (pref_b[j/2] - pref_b[i/2]) == (pref_a[j/2 + 1] - pref_a[i/2])){
				k = true;
			}
			j++;
		}
		i++;
	}
	a.clear();
	b.clear();
	if(k == true) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}
	
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
