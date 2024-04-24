#include<bits/stdc++.h>
using namespace std;


	vector <string> result;
	long long n;
	void bingen(string curstr){
		if (curstr.size() == n){
			result.push_back(curstr);
			return;
		}
		bingen(curstr + "0");
		bingen(curstr + "1");
		
	}
	int main(int argc, char ** argv){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	bingen("");
	for (int i = 0; i < result.size(); i++){
		cout << result[i] << '\n';
	}
	return 0;
}
// cach 2: doi tu 0 -> 2^n-1 sang nhi phan
