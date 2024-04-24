#include<bits/stdc++.h>
using namespace std;
 
int n;
vector<pair<long long, long long>> t;
 
void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		long long a, b; cin >> a >> b;
		t.push_back({b, a});
	}
	sort(t.begin(), t.end()); //sort thoi gian ket thuc
	long long curr_end = t[0].first;
	long long res = 1;
	for(int i = 1; i < n; i++){
		if(t[i].second >= curr_end){
			curr_end = t[i].first;
			res++;
		}
	}
	cout << res ;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}
