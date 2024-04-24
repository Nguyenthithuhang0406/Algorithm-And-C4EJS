#include<bits/stdc++.h>
using namespace std;

const long long d = 1000000007;
long long pow(int a, int b){
	if(b == 0) return 1;
	long long kq = pow(a, b/2) % d;
	if(b % 2 != 0){
		return (a * kq ) % d * kq % d;
	}else return (kq * kq) % d ;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n < 2){
		cout << 0;
	}else{
		cout << (pow(10,n) - 2 * pow(9,n) + pow(8,n) + d * d) % d;
	}
	return 0;
}
