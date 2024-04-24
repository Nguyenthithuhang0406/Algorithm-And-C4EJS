#include<bits/stdc++.h>
using namespace std;

long long l[200005], r[200005], n;
void solve(){
	 cin >> n;
	 for(int i = 1; i <= n; i++){
	 	cin >> l[i] >> r[i];	
	 }
	 
	 long long L = 0, R = 1000000000, M, S = 0;
	 while(L <= R){
	 	M = (L+R) / 2;
	 	long long left = 0, right = 0;
	 	bool flag = true;
	 	
	 	for(int i = 0; i <= n; i++){
	 		left -= M;
	 		right += M;
	 		left = max(left, l[i]);
	 		right = min(right, r[i]);
	 		if(left > right)  flag = false;
		}
		
		if(flag == true){
			R = M - 1; S = M;
		}else{
			L = M + 1;
		}
	 }
	 cout << S << "\n"; 
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
