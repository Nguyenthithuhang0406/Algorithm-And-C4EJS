#include<bits/stdc++.h>
using namespace std;

long long n;
long long per[100];
bool check[101] = {};
	void pergen(long long ix){
		if (ix == n){
			for (int i = 0; i < n; i++){
				cout << per[i] <<" ";
			}
				cout <<'\n';
				return;
		}
		for (long long i = 1; i <= n; i++){
			if (check[i] == false){
				check[i] = true;
				per[ix] = i;
				pergen(ix+1);
				check[i] = false;
			}
		}
		
	}
	int main(int argc, char ** argv){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n;
	pergen(0);
	return 0;
}
//sinh hoan vi nhanh: next_permutation(a, a+n);
/*long long a[n];
for(int i = 1; i <= n;i++){
	a[i-1] = i;
}
next_permutation(a, a+n);
*/

