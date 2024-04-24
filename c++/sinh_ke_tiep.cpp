//Thuat toan sinh ke tiep
//1.khoi tao cau hinh dau tien
//2.while(khi chua phai cau hinh cuoi cung){
// in ra cau hinh hien tai
//3.sinh ra cau hinh tiep theo
//}
//sinh day nhi phan n ki tu
#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005]; 
int ok;
void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = 0; 
	}
}

void sinh(){
	//tim ki tu 0 dau tien tinh tu phai sang trai
	int i = n;
	while(i >= 1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0){
		ok = 0; //da dat cau hinh cuoi cung
	}else{
		a[i] = 1;
	}
}

int main(){
	cin >> n;
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= n; i++){
			cout << a[i];
		}
		cout << "\n";
		sinh();
	}
	return 0;
}


//sinh tap con k phan tu cua tap n phan tu
int n , k, a[10000], ok;

void ktao(){
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = k;
	while(i >= 1 && a[i] == n - k + 1){
		 i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i] ++;
		for(int j = i + 1; j <= k; j++){
			a[j] = a[j-1] + 1;
		}
	}
}

int main(){
	cin >> n >> k;
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= k ; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		sinh();
	}
	return 0;
}

//sinh hoan vi n phan tu
//cach 1: tu code
int n, a[10000], ok;

void ktao(){
	for(int i = 1; i <= n; i++){
		a[i] = i;
	}
}

void sinh(){
	int i = n - 1;
	while(i >= 1 && a[i] > a[i+1]){   //tim vi tri so truoc lon hon so sau
		i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		int j = n;
		while(a[i] > a[j]) j--;   //duyet tu cuoi ve, tim phan tu nho hon a[i] dau tien
		swap(a[i], a[j]);         //doi 2 so cho nhau
		int l = i + 1, r = n;	  //dao nguoc mang doan tu l den r
		while(l < r){
			swap(a[l], a[r]);
			l++;
			r--;
		}
		//hoac dung ham dao nguoc  reverse(a+i+1, a+n+1);
	}
}

int main(){
	cin >> n;
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		sinh();
	}
	
}

//cach 2:dung ham next_permutation(a, a+n)

int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = i + 1;
	}
	do{
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}while(next_permutation(a, a+n));
	return 0;
}

//cach 3: dung ham prev_permutation(a, a+n)

int main(){
	int n ; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = n - i +1;
	}
	do{
		for(int i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
	}while(prev_permutation(a, a+n));
	return 0;
}


//sinh phan hoach nguyen cua so tu nhien (phan tich 1 so thanh tong cac so)
int n, a[10000], ok, cnt;
//cnt: dem so luong phan tu cua mang a
void ktao(){
	cnt = 1;
	a[1] = n;
}

void sinh(){
	int i = cnt;
	while(i >= 1 && a[i] == 1){  //tim phan tu khac 1 dau tien
		i--;
	}
	if(i == 0){
		ok = 0;
	}else{
		a[i] -- ;
		int d = cnt - i + 1;
		cnt = i;
		int q = d / a[i];
		int r = d % a[i];
		if(q){
			for(int j = 1; j <= q; j++){
				cnt ++;
				a[cnt] = a[i];
			}
		}
		if(r){
			cnt ++;
			a[cnt] = r;
		}
	}
}

int main(){
	cin >> n;
	ok = 1;
	ktao();
	while(ok){
		for(int i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << "\n";
		sinh();
	}
	return 0;
}