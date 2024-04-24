#include<bits/stdc++.h>
using namespace std;

string s;
bool ktra(int a){
	bool kq = true;
	int k = s.size();
	int i = 0;
	int j = k - a - 1;
	while(i <= a && kq == true){
		if(s[i] != s[j]){
			kq = false;
		}
		i++;
		j++;
	}
	return kq;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> s;
	for(int i = 0; i+1 < s.size(); i++){
		if(ktra(i) == true){
			cout << i+1 << " ";
		}
	}
	return 0;
}
