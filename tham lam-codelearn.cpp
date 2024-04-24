#include<bits/stdc++.h>
using namespace std;

int arr[1000];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	int k;
	cin >> k;
	sort(arr,arr + n); //sap xep tu nho den lon
	int i = 0;
	int res = 0;
 while (i <= n; k >= arr[i]){
 	res++;
 	k -= arr[i];
 	i++;
 }
 cout << res;
	return 0;
}
