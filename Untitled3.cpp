#include<bits/stdc++.h>
using namespace std;

bool b0_red[5], b1_red[5], b2_red[5], b3_red[5];
bool b0_bl[65], b1_bl[65], b2_bl[65], b3_bl[65];
	
void solve(){
	
	b0_red[0] = true;
	b1_red[1] = b1_red[4] = true;
	b2_red[2] = b2_red[8] = b2_red[5] = true;
	b3_red[3] = b3_red[12] = b3_red[6] = b3_red[9] = true;
	
	int b[4] = {2, 3, 5, 6};
	
	b0_bl[0] = true;
	b1_bl[2] = b1_bl[3] = b1_bl[5] = b1_bl[6] = true;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			b2_bl[b[i] + b[j]] = true;
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int l = 0; l < 4; l++)
				b3_bl[b[i] + b[j] + b[l]] = true;
	
	int A, B; cin >> A >> B;
	if((b0_red[A] == true && b3_bl[B] == true) || (b1_red[A] == true && b2_bl[B] == true) || (b2_red[A] == true && b1_bl[B] == true) || (b3_red[A] == true && b0_bl[B] == true)) cout << "YES";
	else cout << "NO";
} 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();
	return 0;
}

