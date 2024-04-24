#include <bits/stdc++.h>
using namespace std;

int main(){
	
	string s, t = "";
	cin >> s;
	long long n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int j = 0;
	for(int i = 0; i < s.size(); i ++){
		if(i < a[j] || i > a[n-1]) t += s[i];
		else{
			t += " ";
			t += s[i];
			j++;
		}
	}
	cout << t;
	return 0;
}

