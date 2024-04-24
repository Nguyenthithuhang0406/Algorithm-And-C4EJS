#include<bits/stdc++.h>
using namespace std;

long long n;
double p;
struct matrix{
	double mtx[2][2];
};

matrix a, b;

//khoi tao
void init(){
	
	a.mtx[0][0] = 1.0 - p;
	a.mtx[0][1] = p;
	a.mtx[1][0] = p;
	a.mtx[1][1] = 1.0 - p;
	
	b.mtx[0][0] = b.mtx[1][1] = 1.0;
}

//nhan hai ma tran
matrix mul(matrix a, matrix b){
	matrix result;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			result.mtx[i][j] = 0.0;
			for(int k = 0; k < 2; k++){
				result.mtx[i][j] += a.mtx[i][k] * b.mtx[k][j];
			}
		}
	}
	return result;
}

//luy thua cua ma tran
matrix binPow(matrix a, long long n){
	if(n == 0) return b;
	
	matrix x = binPow(a, n/2);
	
	if(n % 2 == 1){
		return mul(mul(x,x), a);
	}else{
		return mul(x,x);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> p;
	init();
	matrix result = binPow(a,n);
	cout << fixed << setprecision(10) << result.mtx[0][0];
	return 0;
}
