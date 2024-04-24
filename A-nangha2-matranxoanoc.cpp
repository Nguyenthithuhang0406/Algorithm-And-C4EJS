#include<bits/stdc++.h>
using namespace std;

char a[200][200];
vector<char> b;
vector<int> c; //chi so cot
vector<int> r; //chi so hang
void spiral(char a[200][200], int rows, int cols){
	int top = 0, left = 0;
	int bottom = rows - 1, right = cols - 1;
	
	while(top <= bottom && left <= right){
		//in hang tu trai sang phai
		for(int i = left; i <= right; ++i){
			b.push_back(a[top][i]) ;
			r.push_back(top);
			c.push_back(i);
		}
		top ++;
		
		//in cot tu tren xuong duoi
		for(int i = top; i <= bottom; ++i){
			b.push_back(a[i][right]);
			r.push_back(i);
			c.push_back(right);
		}
		right --;
		
		//in hang tu phai sang trai
		if(top <= bottom){
			for(int i = right; i >= left; --i){
				b.push_back(a[bottom][i]);
				r.push_back(bottom);
				c.push_back(i);
			}
			bottom --;
		}
		
		//in cot tu duoi len tren
		if(left <= right){
			for(int i = bottom; i >= top; --i){
				b.push_back(a[i][left]);
				r.push_back(i);
				c.push_back(left);
			}
			left ++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			if(a[i][j] != 'P' && a[i][j] != 'H' && a[i][j] != 'U' && a[i][j] != 'O' && a[i][j] != 'N' && a[i][j] != 'G'){
				res++;
			}
		}
	}
	//	cout << res << endl;
	int l;
	spiral(a,n,n);
	int h = (k+1) % res ;
	int m = (k+1) / res;
	if(m % 2 == 0){
	int i = 0;
	while(h > 0){
		if(b[i] != 'P' && b[i] != 'H' && b[i] != 'U' && b[i] != 'O' && b[i] != 'N' && b[i] != 'G'){
				h--;
				l = i;
			}
			i++;
	}
	cout << b[l] << " " << r[l] + 1 << " "<< c[l] + 1;
	}
	else{
		int i = n*n -1;
		while(h >= 0){
			if(b[i] != 'P' && b[i] != 'H' && b[i] != 'U' && b[i] != 'O' && b[i] != 'N' && b[i] != 'G'){
				h--;
				l = i;
			}
			i--;
		}
		cout << b[l] << " " << r[l] + 1 << " "<< c[l] + 1;
	}
//		for(int i = 0; i < n*n ; i++){
//		cout << b[i] << " ";
//		}
	return 0;
} 
