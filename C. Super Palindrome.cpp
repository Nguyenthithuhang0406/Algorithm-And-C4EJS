#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	s = "*" + s + "*";
	int p[n+2];
	int l = 0, r = 1;
	for(int i = 1; i <= n; i++){
		p[i] = max(0, min(r - i, p[l + (r - i)]));
		while (s[i - p[i]] == s[i + p[i]]){
			p[i] ++;
		}
		if (i + p[i] > r){
			l = i - p[i];
			r = i + p[i];
		}
	}
	for(int i = 1; i <= n ; i++){
		cout << 2 * p[i] - 1 << " ";
	}
	return 0;
}
