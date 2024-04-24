#include<bits/stdc++.h>
using namespace std;

long long n;
double p;
	
struct matrix{
	double mtx[2][2];
};

matrix f, a, b;

//khoi tao
void init(){
	f.mtx[0][0] = p;
	f.mtx[0][1] = 1.0 - p;
	
//	a.mtx[0][0] = 1.0;
	a.mtx[0][1] = p;
	a.mtx[1][0] = 1.0;
	a.mtx[1][1] = 1.0 - p;
	
	b.mtx[0][0] = b.mtx[1][1] = 1.0;
}

//nhan hai ma tran
matrix mul(matrix a, matrix b){
	matrix result;
	for(long long i = 0; i< 2; i++)
		for(long long j = 0; j <2; j++){
			result.mtx[i][j] = 0.0;
			for(long long k = 0; k < 2; k++)
				result.mtx[i][j] += a.mtx[i][k] * b.mtx[k][j];
		}
		return result;
}

//ma tran A mu n-2
matrix binPow(matrix a, long long n ){
	if(n == 0) return b;
	
	matrix x = binPow(a, n/ 2);
	if(n % 2)
		return mul(mul(x,x) , a);
	return mul(x,x);
}
int main(){
	cin >> n >> p;
	if(n == 1){	
		cout << 1.0-p;
	}else{
		init();
		matrix result = mul(f, binPow(a, n-1));
		/*for(long long i = 1; i < n; i++){
			matrix result = mul(f, binPow(a, i-1));
			cout << result.mtx[0][1] << " ";
		}*/
		cout <<fixed << setprecision(9) << result.mtx[0][1];
	}
	return 0;
}
