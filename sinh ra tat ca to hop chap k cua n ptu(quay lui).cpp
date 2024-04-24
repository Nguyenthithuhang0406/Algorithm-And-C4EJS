#include<bits/stdc++.h>
using namespace std;

	vector <string> result;
	long long n;
	long long a[1000];
	void comgen(long long i, string curstr){
		if (i == n){
			result.push_back(curstr);
			return;
		}
		comgen(i+1, curstr);
		comgen(i + 1, curstr + " " + to_string(a[i]));
		}
	int main(int argc, char ** argv){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	comgen(0, "");
		for (int i = 0; i < result.size(); i++){
		cout << result[i] << '\n';
	}
	
	return 0;
}
