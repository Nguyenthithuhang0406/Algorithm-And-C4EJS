//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n, p = 0, xi, yi;
//int cnt = 0;
//vector<pair<int, int>> qv;
//
//int sosanh(pair<int, int> a, pair<int, int> b){
//	if(a.first != b.first) return a.first < b.first;
//	else if(a.first == b.first) return a.second > b.second;
//}
//void GetInput(){
//	cin >> p >> n;
//	for (int i = 0; i < n; i++){
//		cin >> xi >> yi;
//		qv.push_back({xi, yi});
//	}
//	sort(qv.begin(), qv.end(), sosanh );
//	for (int i = 0; i < n; i++){
//		if (qv[i].first < p){
//			cnt++;
//			p += qv[i].second;
//		}
//	}
//	
//	if (cnt == n){
//		cout << "YES";
//	}
//	else if (cnt < n){
//		cout << "NO";
//	}
//}
//
//
//
//int main(){
//	
//	GetInput();
//	
//	return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;

int x[1005], y[1005], n, p, cnt =0;

int main(){
	cin >> p >> n;
	for(int i = 0; i < n ;i++){
		cin >> x[i] >> y[i];
	}
	for(int i = 0; i < n-1; i++){
		for(int j = i + 1; j< n; j++){
			if(x[i] > x[j]){
				swap(x[i], x[j]);
				swap(y[i], y[j]);
			}
			if(x[i] == x[j] && y[i] < y[j]){
				swap(y[i], y[j]);
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (x[i] < p){
			cnt++;
			p += y[i];
		}
	}
	if (cnt == n){
		cout << "YES";
	}
	else if (cnt < n){
		cout << "NO";
	}
	return 0;
}

