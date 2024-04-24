#include<bits/stdc++.h>
using namespace std;

bool nt(long long  m){
    long i1, b1 = (sqrt(m));
    if(m == 2 || m == 3)
        return 1;
    if(m % 2==0 || m % 3 == 0|| m < 2)
        return 0;
    for(i1 = 5; i1 <= b1; i1 += 6)
        if(m % i1 == 0 || m % (i1+2) == 0)
            return 0;
    return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	int k = 0;
	for(int i = a; i <= b; i++){
		if(nt(i) == true){
			k++;
		}
	}
	cout << k;
	return 0;
}
