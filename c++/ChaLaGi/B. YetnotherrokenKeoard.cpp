#include<bits/stdc++.h>
using namespace std;

vector<int> hoa;
vector<int> thuong;
void solve(){
	string s; cin >> s;
	int n = s.size();
	for(int i = 0; i < n ; i++){
		if(s[i] >= 'a' && s[i] <= 'z' && s[i] != 'b') thuong.push_back(i);
		if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'B') hoa.push_back(i);
		if(s[i] == 'b' && thuong.size() != 0){
			int j = thuong[thuong.size() - 1];
			s[j] = '0';
			thuong.pop_back();
		}
        if(s[i] == 'B' && hoa.size() != 0){
			int j = hoa[hoa.size() - 1];
			s[j] = '0';
			hoa.pop_back();
		}
	}
    hoa.clear();
    thuong.clear();
    for(int i = 0; i < n; i++){
        if(s[i] != '0' && s[i] != 'b' && s[i] != 'B') cout << s[i];
    }
    cout << "\n";
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
