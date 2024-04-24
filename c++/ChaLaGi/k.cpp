
#include<bits/stdc++.h>
using namespace std;

int n, k;
long long a[15];
vector<pair<long long, int>> mp;

long long solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == 1 || n == 2) return 0;
	if(n == 3 ){
		if(a[2] < a[1] && a[3] > a[2]){
			if(k <= abs(a[1] - a[3])) return k + min(a[1], a[3]) - a[2];
			else return max(a[1], a[3]) + (k - abs(a[1] - a[3])) / 2 - a[2];
		}
		else return 0;
	}
	
	long long sum = 0;
	
	//do nuoc ban dau
	for(int i = 2; i < n; i++){
		int l = i, r = i;
		for(int j = i - 1; j >= 1 ; j--){
			if(a[j] > a[l]) l = j;
		}
		for(int j = i+1; j <= n; j++){
			if(a[j] > a[r]) r = j;
		}
		if(a[l] > a[i] && a[r] > a[i])
			for(int j = l + 1; j < r; j++){
				if(a[j] < min(a[l], a[r])){
					sum += min(a[l], a[r]) - a[j];
					a[j] = min(a[l], a[r]);
				}
			}
	}
	
	//sau khi do nuoc theo cac cot ban dau se tao day tang dan den dinh r giam dan
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt++;
		if(i == n || a[i] != a[i+1]){
			mp.push_back({a[i], cnt});
			cnt = 0;
		}
	}
	
//	for(auto it : mp) cout << it.first << " " << it.second << "\n";
//	cout << "\n";

	//neu sau khi do nuoc ma cac cot nuoc va da co do cao bang nhau, thi them da vao 2 cot ngoai cung
	if(mp.size() == 1) return (mp[0].second - 2) * (k/2);
		
	while(k){
		//tim doan co so cot bang nhau lien tiep dai nhat
		int ma = 0 , index = 0;
		for(int i = 0; i < mp.size(); i++){
			if((mp[i].first < mp[i+1].first || mp[i].first < mp[i-1].first) && mp[i].second - 1 > ma){
				ma = mp[i].second - 1;
				index = i;
			}
			if( i > 0 && i < mp.size() - 1 && mp[i].first > mp[i-1].first && mp[i].first > mp[i+1].first && mp[i].second - 2 > ma){
				ma = mp[i].second - 2;
				index = i;
			}	
		}
		
		//kiem tra day co tang ngat khong
		bool ok = true;
		for(int i = 0; i < mp.size() - 1; i++){
			if(mp[i].first > mp[i+1].first) ok = false;
		}
		//neu moi cot co 1 do cao khac nhau va tao thanh day tang dan
		if(ma == 0 && ok == true){
			long long pref[15];
			pref[0] = mp[0].first;
			for(int i = 1; i < mp.size(); i++){
				pref[i] = pref[i-1] + mp[i].first;
			}
			long long m = 0;
			for(int i = 2; i < mp.size() ; i++){
				for(int j = 0; j < i - 1; j++){
					if(mp[j].first + k >= mp[i].first){
						long long khoi = mp[i].first * (i - j + 1);
						long long denta = khoi - 2 * mp[i].first - (pref[i-1] - pref[j]);
						long long nuoc =denta + (i-j - 1) * ((k - (mp[i].first - mp[j].first)) / 2);
						m = max(m, nuoc);
					} 
				}
			}
			sum += m;
		}
		
		//neu doan dai nhat gom cac cot co chieu cao bang nhau va cao nhat, thi them vao 2 cot ngoai cung doan do 1 luong la k/2
		if(mp[index].first > mp[index-1].first && mp[index].first > mp[index+1].first){
			sum += ma * (k / 2);
			mp[index].first += k / 2;
			k = k%2;
		}
		
		//neu doan dai nhat thuoc doan dau (tang ngat), them cot ben trai cung cua doan do de cot ngoai cung trai = cot ngoai cung phai
		if( mp[index].first < mp[index+1].first){
			if(k < (mp[index+1].first - mp[index].first)){
				sum += k * ma;
				mp[index].first += k;
				k = 0;
			}
			if(k >= (mp[index+1].first - mp[index].first)){
				sum += (mp[index+1].first - mp[index].first) * ma;
				mp[index].first = mp[index+1].first;
				mp[index].second += mp[index+1].second;
				mp[index+1].second = mp[index].second;
				k -= (mp[index+1].first - mp[index].first);
 			}
		}
		
		//neu doan dai nhat thuoc doan sau(giam ngat), them vao cot ngoai cung ben phai cua doan do
		if(mp[index].first < mp[index-1].first){
			if(k < (mp[index-1].first - mp[index].first)){
				sum += k * ma;
				mp[index].first += k;
				k = 0;
			}
			if(k >= (mp[index-1].first - mp[index].first)){
				sum += (mp[index-1].first - mp[index].first) * ma;
				mp[index].first = mp[index-1].first;
				mp[index].second += mp[index-1].second;
				mp[index-1].second = mp[index].second;
				k -= (mp[index-1].first - mp[index].first);
 			}
		}
	}
		return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout << solve();
	return 0;
}
