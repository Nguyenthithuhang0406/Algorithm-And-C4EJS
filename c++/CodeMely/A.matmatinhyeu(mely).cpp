#include<bits/stdc++.h>
using namespace std;

int a, b;
vector<int> t;
void solve(){
	t.push_back(b);
	bool kt = true;
	while(b > a && kt == true){
		if(b % 10 == 1) 
			b /= 10;
		else if(b % 2 == 0) b/= 2;
		   else kt = false;
		if(kt == true) t.push_back(b);
	}
	
	if( b == a && kt == true ){
		reverse(t.begin(), t.end());
		cout << "YES" << "\n";
		cout << t.size() << "\n";
		for(int x : t){
			cout << x << " ";
		}
	}else
		cout << "NO";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> a >> b;
	solve();
	return 0;
}
