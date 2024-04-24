//tim day con tang dai nhat
#include<bits/stdc++.h>
using namespace std;

long long a[200005];
long long L[200005];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		L[i] = 1; // ban dau coi moi phan tu la 1 day nen L[i] = 1;
	}
	for(int i = 1; i <= n; i++){
		//duyet qua tung phan tu dung truoc chi so i
		for(int j = 1; j < i; j++){
			if(a[j] < a[i]){
				L[i] = max(L[i], L[j] + 1);   
				// neu so thu j nho hon so thu i thi co the them so thu i vao day con ket thuc la so thu j
				//do dai day con se chon so lon nhat trong 2 truong hop(neu them so i vao day j : L[i] = L[j] + 1; neu khong them vao: L[i] = L[i])
			}
		}
	}
	cout << *max_element(L.begin(), L.end());
	return 0;
}


/*bai toan cai tui,cai tui co the chua duoc toi da trong luong la S, co n mon do,
 moi mon do co trong luong w va gia tri v, ban co the lua chon tuy y sao cho tong gia tri la lon nhat*/
#include<bits/stdc++.h>
using namespace std;

long long w[100005], v[100005]; //mang w la trong luong moi mon do, va mang v la gia tri tuong ung cua mon do
long long dp[100005][100005];
int main(){
	int n, S;   //n: so luong mon do; S: trong luong toi da nguoi do co the mang
	cin >> n >> S;
	for(int i = 1; i <= n; i++){
		cin >> w[i];	}
	for(int i = 1; i ,= n; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= S; j++){
			//khong chon mon do thu i, thi gia tri trong tui bang gia tri truoc do
			dp[i][j] = dp[i-1][j];
			//chon do vat thu i, gia tri trong tui la dp[i-1][j -w[i]] + v[i]
			if(j >= w[i]){   //tui phai co trong luong it nhat bang trong luong mon do thi moi co the chua duoc no
				dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i] );
			}
		}
	}
	cout << dp[n][S];
	return 0;
}

//kiem tra co the tim duoc day con co tong la s khong
#include<bits/stdc++.h>
using namespace std;

long long a[200005];
bool dp[200005];
int main(){
	int n, S;
	cin >> n >> S;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, false, sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = S; j >= a[i]; j--){
			if(dp[j-a[i]] == true){
				dp[j] = true;
			}
		}
	}
	if(dp[S]) cout << "YES";
	else cout << "NO";
	return 0;
}

//Xau con doi xung dai nhat
#include<bits/stdc++.h>
using namespace std;

bool F[10005][10005];
int main(){
	string s;
	cin >> s;
	long long n = s.size();
	s = "@" + s;
	memset(F, false, sizeof(F));
	//xau doi xung khi 2 ki tu ngoai cung bang nhau va xau con o giua doi xung
	//F[i][j] = f[i+1][j-1] && s[i] == s[j]
	for(int i = 1; i <= n; i++) F[i][i] = true; //xau co do dai la 1 ki tu
	//xet ca xau co do dai tu 2 ki tu tro len
	long long res = 1;
	for(int l = 2; l <= n; l++){
		for(int i = 1; i <= n - l + 1; i++){
			int j = i + l - 1;
			//f[i][j]: la ket qua cua xau con co do dai tu ki tu i den ki tu j
			if(l == 2 && s[i] == s[j]) f[i][j] = true; // xau con co 2 ki tu thi no doi xung khi 2 ki tu bang nhau
			else{
				F[i][j] = F[i+1][j-1] && s[i] == s[j];  ///truong hop 3 ki tu tro nen
			}
				if(F[i][j])  res = max(res, l);
		}
	}
	cout << res;
}


//xau con chung dai nhat
#include<bits/stdc++.h>
using namespace std;

int F[1001][1001];  //luu xau con chung dai nhat trong doan [i, j]
int main(){
	string x, y;
	cin >> x >> y;
	int n = x.size();
	int m = y.size();
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(i == 0 || j == 0){
				F[i][j] == 0;
			}
			else{
				if(x[i-1] == y[j-1]){
					F[i][j] = F[i-1][j-1] + 1;
				}else{
					F[i][j] = max(F[i-1][j], F[i][j-1]);
				}
			}
		}
	}
	cout << F[n][m];
}
