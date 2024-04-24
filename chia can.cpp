#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	/*long long n, q;
	cin >> n >> q;
	long long a[200005];
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	long long blockSize = sqrt(n);
	long long block[(long long)sqrt(n) + 5];
	
	for(long long i = 0 ; i < n ; i++)
		block[i/blockSize + 1] = min(block[i/blockSize + 1], a[i]);
		
	while(q --){
		long long l, r;
		cin >> l >> r;
		
		long long blockL = l / blockSize + 1;
		long long blockR = r / blockSize + 1;
		
		long long res = 1e18;
		if(blockL >= blockR){
			for(long long i = l; i <= r; i++)
				res = min(res, a[i]);
		}
		else{
			for(long long i = blockL + 1; i < blockR; i++)
				res = min(res, block[i]); //O(sqrt(n));
			for(long long i = l; i <= blockL * blockSize; i++)
				res = min(res, a[i]);	//O(sqrt(n));
			for(long long i = (blockR - 1) * blockSize; i < r; i++)
				res = min(res, a[i]); 	//O(sqrt(n));
		}
		
		cout << res << " ";
	}	*/
	
	
	//dem so lan xuat hien cua cac phan tu
	
	long long n, q;
	cin >> n >> q;
	long long a[200005];
	for(long long i = 0; i < n; i++){
		cin >> a[i];
	}
	
	long long blockSize = sqrt(n);
	vector<vector<long long>> block(n/blockSize + 5, vector<long long> (100005)); 
	for(long long i = 0; i < n; i++)
		block[i/blockSize + 1][a[i]] ++;
		
		while(q--){
			long long l, r , k;
			cin >> l >> r >> k;
			
			long long blockL = l/blockSize + 1;
			long long blockR = r/blockSize + 1;
			
			long long res = 0;
			if(blockL >= blockR){
				for(long long i = l; i <= r; i++)
					if(a[i] == k) res++;
			}
			else{
				for(long long i = blockL + 1; i < blockR; i++)
					res += block[i][k];
				for(long long i = l; i < blockL * blockSize; i++)
					if(a[i] == k) res++;
				for(long long i = (blockR - 1) * blockSize; i <= r; i++)
					if(a[i] == k) res++;
			}
			
			cout << res << "\n";
		}
	return 0;
}
