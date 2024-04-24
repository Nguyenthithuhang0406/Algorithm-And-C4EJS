/*
            Author: Binh Nguyen 2k4
            I don't write code, code rides me
            From Binh Nguyen With Love
*/
#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fu(i, a, b) for(ll i = a; i < b; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define pb push_back
const int mod = 1e9 + 7;



// // A. Random Mood
// struct Matrix {
// 	double a[2][2] = {{0,0},{0,0}};
// Matrix operator *(const Matrix& other) {
// 		Matrix product;
// 		fu(i, 0, 2) fu(j, 0, 2) fu(k, 0, 2) {
// 			product.a[i][k] += a[i][j] * other.a[j][k];
// 		}
// 		return product;
// 	}
// };
// Matrix expo_power(Matrix a, int k) {
// 	Matrix product;
// 	fu(i, 0, 2) product.a[i][i] = 1;
// 	while(k > 0) {
// 		if(k % 2) {
//     	product = product * a;
// 		}
// 		a = a * a;
// 		k /= 2;
// 	}
// 	return product;
//     }
// int main() {
// 	int n;
// 	double p;
// 	cin >> n >> p;
// 	Matrix single;
// 	single.a[0][0] = 1 - p;
// 	single.a[0][1] = p;
// 	single.a[1][0] = p;
// 	single.a[1][1] = 1 - p;
// 	Matrix total = expo_power(single, n);
// 	cout << setprecision(10) << fixed << total.a[0][0] << endl;
// }



// // B. String Mood
// struct Matrix {
// 	int a[2][2] = {{0,0},{0,0}};
// 	Matrix operator *(const Matrix& other) {
// 		Matrix product;
// 		fu(i, 0, 2) fu(j, 0, 2) fu(k, 0, 2) {
// 			product.a[i][k] = (product.a[i][k] + (ll) a[i][j] * other.a[j][k]) % mod;
// 		}
//     	return product;
// 	}
// };
// Matrix expo_power(Matrix a, ll k) {
// 	Matrix product;
// 	fu(i, 0, 2) product.a[i][i] = 1;
// 	while(k > 0) {
// 		if(k % 2) {
// 			product = product * a;
// 		}
// 		a = a * a;
// 		k /= 2;
// 	}
// 	return product;
// }
// int main() {
// 	ll n;
// 	cin >> n;
// 	Matrix single;
// 	single.a[0][0] = 19;
// 	single.a[0][1] = 7;
// 	single.a[1][0] = 6;
// 	single.a[1][1] = 20;
// 	Matrix total = expo_power(single, n);
// 	cout << total.a[0][0] << endl;
// }




//// C. Fibonacci
//struct Matrix {
//	int a[2][2] = {{0,0},{0,0}};
//	Matrix operator *(const Matrix& other) {
//		Matrix product;
//		fu(i, 0, 2) fu(j, 0, 2) fu(k, 0, 2) {
//			product.a[i][k] = (product.a[i][k] + (ll) a[i][j] * other.a[j][k]) % mod;
//		}
//		return product;
//	}
//};
//Matrix expo_power(Matrix a, ll k) {
//	Matrix product;
//	fu(i, 0, 2) product.a[i][i] = 1;
//	while(k > 0) {
//		if(k % 2) {
//			product = product * a;
//		}
//		a = a * a;
//		k /= 2;
//	}
//	return product;
//}
//int main() {
//	ll n;
//	cin >> n;
//	Matrix single;
//	single.a[0][0] = 0;
//	single.a[0][1] = 1;
//	single.a[1][0] = 1;
//	single.a[1][1] = 1;
//	Matrix total = expo_power(single, n);
//	cout << total.a[1][0] << endl;
//}





//// D. Count Paths
//int n;
//struct Matrix {
//	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
//	Matrix operator *(const Matrix& other) {
//		Matrix product;
//		vector<vector<ll>> tmp(n, vector<ll>(n));
//		fu(i, 0, n) fu(j, 0, n) fu(k, 0, n) {
//			tmp[i][k] += (ll) a[i][j] * other.a[j][k];
//			if(tmp[i][k] >= 8LL * mod * mod) {
//				tmp[i][k] %= mod;
//			}
//		}
//		fu(i, 0, n) fu(j, 0, n) product.a[i][j] = tmp[i][j] % mod;
//		return product;
//	}
//};
//Matrix expo_power(Matrix a, ll k) {
//	Matrix product;
//	fu(i, 0, n) product.a[i][i] = 1;
//	while(k > 0) {
//		if(k % 2) {
//			product = product * a;
//		}
//		a = a * a;
//		k /= 2;
//	}
//	return product;
//}
//int main() {
//	int m;
//	ll k;
//	cin >> n >> m >> k;
//	Matrix single;
//	fu(i, 0, m) {
//		int u, v;
//		cin >> u >> v;
//		single.a[u-1][v-1] = 1;
//	}
//	Matrix total = expo_power(single, k);
//	int answer = 0;
//	fu(i, 0, n) fu(j, 0, n) {
//		answer = (answer + total.a[i][j]) % mod;
//	}
//	cout << answer << endl;
//}





//// E. Knight Paths
//const int A = 65;
//struct Matrix {
//	vector<vector<unsigned int>> a = vector<vector<unsigned int>>(A, vector<unsigned int>(A));
//	Matrix operator *(const Matrix& other) {
//		Matrix product;
//		fu(i, 0, A) fu(j, 0, A) fu(k, 0, A) {
//			product.a[i][k] += a[i][j] * other.a[j][k];
//		}
//		return product;
//	}
//};
//Matrix expo_power(Matrix a, int k) {
//	Matrix product;
//	fu(i, 0, A) product.a[i][i] = 1;
//	while(k > 0) {
//		if(k % 2) {
//			product = product * a;
//		}
//		a = a * a;
//		k /= 2;
//	}
//	return product;
//}
//
//bool inside(int row, int col) {
//	return 0 <= min(row, col) && max(row, col) < 8;
//}
//int main() {
//	int k;
//	cin >> k;
//	k++;
//	Matrix single;
//	fu(row, 0, 8) {
//		fu(col, 0, 8) {
//			for(int dr : {-2,-1,1,2}) {
//				for(int dc : {-2,-1,1,2}) {
//					if(abs(dr) != abs(dc)) {
//						int new_row = row + dr;
//						int new_col = col + dc;
//						if(inside(new_row, new_col)) {
//							single.a[8*row+col][8*new_row+new_col] = 1;
//						}
//					}
//				}
//			}
//		}
//	}
//	for(int i = 0; i <= 64; i++) {
//		single.a[i][64] = 1;
//	}
//	Matrix total = expo_power(single, k);
//	cout << total.a[0][64] << endl;
//}





//// F. Min Path
//const ll INF = 3e18L + 5;
//int n;
//struct Matrix {
//	vector<vector<ll>> a = vector<vector<ll>>(n, vector<ll>(n, INF));
//	Matrix operator *(const Matrix& other) {
//		Matrix product;
//		fu(i, 0, n) fu(j, 0, n) fu(k, 0, n) {
//			product.a[i][k] = min(product.a[i][k], a[i][j] + other.a[j][k]);
//		}
//		return product;
//	}
//};
//Matrix expo_power(Matrix a, ll k) {
//	Matrix product;
//	fu(i, 0, n) product.a[i][i] = 0;
//	while(k > 0) {
//		if(k % 2) {
//			product = product * a;
//		}
//		a = a * a;
//		k /= 2;
//	}
//	return product;
//}
//int main() {
//	int m;
//	ll k;
//	cin >> n >> m >> k;
//	Matrix single;
//	fu(i, 0, m) {
//		int u, v, c;
//		cin >> u >> v >> c;
//		single.a[u-1][v-1] = c;
//	}
//	Matrix total = expo_power(single, k);
//	ll answer = INF;
//	fu(i, 0, n) fu(j, 0, n) {
//		answer = min(answer, total.a[i][j]);
//	}
//	if(answer >= INF / 2) {
//		cout << "IMPOSSIBLE" << endl;
//	}
//	else {
//		cout << answer << endl;
//	}
//}




//// G. Recurrence with Square
//int s;
//struct Matrix {
//	vector<vector<int>> a = vector<vector<int>>(s, vector<int>(s));
//	Matrix operator *(const Matrix& other) {
//		Matrix product;
//		fu(i, 0, s) fu(j, 0, s) fu(k, 0, s) {
//			product.a[i][k] = (product.a[i][k] + (ll) a[i][j] * other.a[j][k]) % mod;
//		}
//		return product;
//	}
//};
//Matrix expo_power(Matrix a, ll k) {
//	Matrix product;
//	fu(i, 0, s) product.a[i][i] = 1;
//	while(k > 0) {
//		if(k % 2) {
//			product = product * a;
//		}
//		a = a * a;
//		k /= 2;
//	}
//	return product;
//}
//
//int main() {
//	int n;
//	ll k;
//	cin >> n >> k;
//	s = n + 3;
//	vector<int> a(n);
//	fu(i, 0, n) {
//		cin >> a[i];
//	}
//	vector<int> c(n);
//	fu(i, 0, n) {
//		cin >> c[i];
//	}
//	int p, q, r;
//	cin >> p >> q >> r;
//	if(k < n) {
//		cout << a[k] << endl;
//		return 0;
//	}
//	vector<int> dp(n + 3);
//	fu(i, 0, n) {
//		dp[i] = a[i];
//	}
//	dp[n] = 1;
//	dp[n+1] = n;
//	dp[n+2] = n * n;
//	int m[n+3][n+3];
//	fu(i, 0, n+3) fu(j, 0, n+3) m[i][j] = 0;
//	m[n][n] = 1;
//	m[n+1][n+1] = 1;
//	m[n][n+1] = 1;
//	m[n+2][n+2] = 1;
//	m[n+1][n+2] = 2;
//	m[n][n+2] = 1;
//	m[n][n-1] = p;
//	m[n+1][n-1] = q;
//	m[n+2][n-1] = r;
//	fu(j, 0, n) {
//		m[n-1-j][n-1] = c[j];
//	}
//	for(int j = 0; j < n - 1; j++) {
//		m[j+1][j] = 1;
//	}
//	Matrix single;
//	fu(i, 0, n+3) fu(j, 0, n+3) single.a[i][j] = m[i][j];
//	Matrix total = expo_power(single, k - n + 1);
//	vector<int> new_dp(n + 3);
//	fu(i, 0, n+3) fu(j, 0, n+3) {
//		new_dp[j] = (new_dp[j] + (ll) dp[i] * total.a[i][j]) % mod;
//	}
//	printf("%d\n", new_dp[n-1]);
//	return 0;
//}





//// H. String Mood Updates
//const int nax = 5e5 + 5;
//char s[nax];
//struct Matrix {
//	int a[2][2] = {{0,0},{0,0}};
//	Matrix operator *(const Matrix& other) const {
//		Matrix product;
//		fu(i, 0, 2) fu(j, 0, 2) fu(k, 0, 2) {
//			product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
//		}
//		return product;
//	}
//	void init(char match) {
//		fu(i, 0, 2) fu(j, 0, 2) {
//			a[i][j] = 0;
//		}
//		for(char ch = 'A'; ch <= 'Z'; ++ch) {
//			if(match == '?' || ch == match) {
//				if(ch == 'H') {
//					a[0][1]++;
//					a[1][1]++;
//				}
//				else if(ch == 'S' || ch == 'D') {
//					a[0][0]++;
//					a[1][0]++;
//				}
//				else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'U' || ch == 'O') {
//					a[0][1]++;
//					a[1][0]++;
//				}
//				else {
//					a[0][0]++;
//					a[1][1]++;
//				}
//			}
//		}
//	}
//};
//
//int main() {
//	int n, q;
//	cin >> n >> q >> s;
//	int BASE = 1;
//	while(BASE < n) {
//		BASE *= 2;
//	}
//	vector<Matrix> tree(2 * BASE);
//	fu(i, 0, n) {
//		tree[BASE+i].init(s[i]);
//	}
//	for(int i = n; i < BASE; ++i) {
//		tree[BASE+i].init('Z');
//	}
//	for(int i = BASE - 1; i >= 1; --i) {
//		tree[i] = tree[2*i] * tree[2*i+1];
//	}
//	printf("%d\n", tree[1].a[1][1]);
//	while(q--) {
//		int i;
//		char new_ch;
//		scanf("%d %c", &i, &new_ch);
//		i--;
//		tree[BASE+i].init(new_ch);
//		for(int x = (BASE + i) / 2; x >= 1; x /= 2) {
//			tree[x] = tree[2*x] * tree[2*x+1];
//		}
//		printf("%d\n", tree[1].a[1][1]);
//	}
//}




//// I. Count Paths Queries
//int n;
//struct Matrix {
//	vector<vector<int>> a = vector<vector<int>>(n, vector<int>(n));
//	Matrix operator *(const Matrix& other) {
//		vector<vector<int>> product(n, vector<int>(n));
//		fu(i, 0, n) {
//			fu(j, 0, n) {
//				fu(k, 0, n) {
//					product[i][k] = (product[i][k] + (ll) a[i][j] * other.a[j][k]) % mod;
//				}
//			}
//		}
//		Matrix retu{product};
//		return retu;
//	}
//};
//int main() {
//	int m, q;
//	cin >> n >> m >> q;
//	Matrix base;
//	fu(i, 0, m) {
//		int a, b;
//		cin >> a >> b;
//		base.a[a-1][b-1]++;
//	}
//	vector<Matrix> powers{base};
//	for(int i = 1; i <= 30; ++i) {
//		powers.pb(powers.back() * powers.back());
//	}
//	while(q--) {
//		int a, b, k;
//		cin >> a >> b >> k;
//		a--;
//		b--;
//		vector<int> dp(n);
//		dp[a]++;
//		for(int bit = 0; (1 << bit) <= k; ++bit) {
//			if(k & (1 << bit)) {
//				vector<int> new_dp(n);
//				fu(i, 0, n) {
//					fu(j, 0, n) {
//						new_dp[j] = (new_dp[j] + (ll) dp[i] * powers[bit].a[i][j]) % mod;
//					}
//				}
//				dp = new_dp;
//			}
//		}
//		printf("%d\n", dp[b]);
//	}
//}