#include<bits/stdc++.h>
using namespace std;

char chu[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char so[8] = {'1','2','3','4','5','6','7','8'};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		for(int i = 0; i < 8; i ++){
			if(chu[i] != s[0]) cout << chu[i] << s[1] << "\n";
			if(so[i] != s[1]) cout << s[0] << so[i] << "\n";
		}
	}
	return 0;
}
