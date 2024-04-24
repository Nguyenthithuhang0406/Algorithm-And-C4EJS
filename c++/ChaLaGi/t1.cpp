#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	char k = s[0];
	for(int i = 1; i < s.size(); i++) 
		if(s[i] > k) k = s[i];
	int i = 0; 
	while(k >= 'a'){
		for(int j = i; j < s.size(); j++){
			if(s[j] == k){
				cout << s[j] ;
				i = j;
			}
		}
		k--;
	}
	return 0;
}
