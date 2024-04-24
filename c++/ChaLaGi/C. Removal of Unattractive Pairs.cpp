#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		string s ; cin >> s;
		int dem[27] = {};
		for(int i = 0; i < n; i++) dem[s[i] - 'a'] ++;
		int cnt =  n%2; //so ki tu con lai ban dau duoc gan la 1 neu so luong ki tu le, nguoc lai gan bang 0
		
		//tim chu xuat hien nhieu hon n/2  luot; 
		//so ki tu con lai toi thieu sau khi xoa cac cap chu khac nhau la
		for(int i = 0; i < 26; i++ )
			if(dem[i] * 2 > n) cnt = n - 2 * (n - dem[i]);
		cout << cnt << "\n";
	}
	return 0;
	
}
