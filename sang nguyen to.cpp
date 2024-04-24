#include<bits/stdc++.h>
using namespace std;

bool isprime[10000007];
int main(int argc, char ** argv){
	int n;
	cin >> n;
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for (int i = 2; i<= n; i++){
		for (int j = 2 * i ; j <= n; j+= i){
			isprime[j] = false;
		}
	}
	for (int i = 1; i <= n; i++){
		if (isprime[i] == true){
			cout << i << " ";
		}
	}
	return 0;
}
