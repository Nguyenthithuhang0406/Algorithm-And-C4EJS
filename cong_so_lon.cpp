#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	vector<int> s, h, k;
	string a, b; cin >> a >> b;
	for(int i = a.size() - 1; i >= 0; i--){
		h.push_back(a[i] - '0');
	}
	for(int i = b.size() - 1; i >= 0; i--){
		k.push_back(b[i] - '0');
	}
	
	int n = 0;
	int i = 0;
	while(i < max(a.size(), b.size())){
		s.push_back((h[i] + k[i] + n) % 10);
		n = (h[i] + k[i]) / 10;
		i++;
	}
	s.push_back(n);
	reverse(s.begin(), s.end());
	 i = 0;
	while(i < s.size(), s[i] == 0){
		i++;
	}
	for(int j = i; j < s.size(); j++){
		cout << s[j];
	}
	
	return 0;
}
