#include<bits/stdc++.h>
using namespace std;

long long n;
float p;
//khoi tao
struct matrix{
	float mtx[2][2];
};
matrix f, a, b;

void init(){
	f.mtx[0][0] = 0;
	f.mtx[0][1] = 1.0; //ma tran ket qua
	
	a.mtx[0][0] = a.mtx[1][1] = 1.0-p;
	a.mtx[0][1] = a.mtx[1][0] = p; // ma tran nhan
	
	b.mtx[0][0] = b.mtx[1][1] = 1.0; //ma tran don vi
}

//nhan hai ma tran
matrix mul(matrix a, matrix b){
	matrix result;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			result.mtx[i][j] = 0;
			for (int k = 0; k < 2; k++)
				result.mtx[i][j] += a.mtx[i][k] * b.mtx[k][j];
		}
	return result;
}

//a mu n
matrix binPow(matrix a, long long n){
	if(n == 0)
		return b;
	matrix x = binPow(a, n/2);
	if(n % 2)
		return mul(mul(x,x), a);
	return mul(x,x);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> p;
	init();
	//matrix result = binPow(a, 1);
	//cout << result.mtx[0][1];
	matrix result = mul(f, binPow(a, n));
	cout << fixed << setprecision(10) << result.mtx[0][1];
	return 0;
}
