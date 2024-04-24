#include<bits/stdc++.h>
using namespace std;

char solve(){
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	bool a = false, b = false, c = false;
	for(int i = 0 ; i < 3; i ++){
		if(s1[i] == 'A') a = true;
		if(s1[i] == 'B') b = true;
		if(s1[i] == 'C') c = true;
	}
	if(a == false) return 'A';
	if(b == false) return 'B';
	if(c == false) return 'C';
	
	 a = false, b = false, c = false;
	for(int i = 0 ; i < 3; i ++){
		if(s2[i] == 'A') a = true;
		if(s2[i] == 'B') b = true;
		if(s2[i] == 'C') c = true;
	}
	if(a == false) return 'A';
	if(b == false) return 'B';
	if(c == false) return 'C';
	
	a = false, b = false, c = false;
	for(int i = 0 ; i < 3; i ++){
		if(s3[i] == 'A') a = true;
		if(s3[i] == 'B') b = true;
		if(s3[i] == 'C') c = true;
	}
	if(a == false) return 'A';
	if(b == false) return 'B';
	if(c == false) return 'C';
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		cout << solve() << "\n";
	}
	return 0;
}
