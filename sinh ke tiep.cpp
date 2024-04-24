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
