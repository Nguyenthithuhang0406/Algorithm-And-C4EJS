#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		for(int i = 0; i < n; i++){
			cout << s[i];
			//cvc.cv  //cvc.cvc
			if(s[i] != 'a' && s[i] != 'e' && s[i+1] != 'a' && s[i+1] != 'e' && i+1 < n){
				cout << '.';
			}
			//cv.cv  cv.cvc
			if((s[i] == 'a' || s[i] == 'e' ) && (s[i+2] == 'a' || s[i+2] == 'e') && i+2 < n){
				cout << '.';
			}
		}
		cout << "\n";
	}
	return 0;
}
