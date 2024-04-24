#include<bits/stdc++.h>
using namespace std;
 
long long solve(long long n, int k){
	if( n == 1) return 1; //nếu n == 1 hàm trả về 1 (người cuối cùng)
    //nếu k nằm trong nửa đầu
	if(k <= (n+1) / 2){
		if(2*k > n ) return (2*k) % n; //k nằm sau giữa
		else return 2 * k; //k nằm trước giữa
	}
    //trường hợp còn lại, đệ quy với nửa đầu của dãy trẻ em và vị trí mới của trẻ em (k - (n+1)/2)
	long long tmp = solve(n/2, k - (n+1)/2);
	if(n%2 == 1) return  2*tmp + 1 ;
	return 2*tmp - 1;	
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int q; cin >> q;
	while(q--){
		long long n; int k;  cin >> n >> k;
		cout << solve(n,k) << "\n";
	}
	return 0;
}