// #include <bits/stdc++.h>
// using namespace std;

// /*
//  n: số người
//  m: số căn hộ
//  a[i]: diện tích căn hộ mong muốn của mỗi người
//  b[i]: diện tích căn hộ thực tế
//  k: độ chênh lệch diện tích tối đa
//  res: lưu câu trả lời
//  */
// int n, m, k, a[200000], b[200000], res;

// void input(){
//     cin >> n >> m >> k;
// 	for (int i = 0; i < n; ++i) cin >> a[i];
// 	for (int i = 0; i < m; ++i) cin >> b[i];
// }

// void solve() {
// 	sort(a, a + n);  //sắp xếp mảng a tăng dần
// 	sort(b, b + m); //sắp xếp mảng b tăng dần
// 	int i = 0, j = 0;  //hai con trỏ duyệt mảng a, b
// 	while (i < n && j < m) {
// 		//nếu chênh lệch diện tích không quá k thì đếm là 1 cặp hợp lệ và di chuyển 2 con trỏ đến vị trí tiếp theo
// 		if (abs(a[i] - b[j]) <= k) {
// 			++i;
// 			++j;
// 			++res;
// 		} else {
// 			//nếu chênh lệch lớn hơn k và a[i] > b[j] => tăng j
// 			if (a[i] - b[j] > k) {
// 				++j;
// 			}
//             //ngược lại  => tăng i
// 			else {
// 				++i;
// 			}
// 		}
// 	}
// 	cout << res << "\n";
// }

// int main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(NULL);
//     input();
// 	solve();
// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     /*
//      n: số người
//      m: số căn hộ
//      a[i]: diện tích căn hộ mong muốn của mỗi người
//      b[i]: diện tích căn hộ thực tế
//      k: độ chênh lệch diện tích tối đa
//      res: lưu câu trả lời
//      */
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<long long> a(n + 1), b(m + 1);

//     for (int i = 1; i <= n; i++){
//         cin >> a[i];
//     }

//     for (int i = 1; i <= m; i++){
//         cin >> b[i];
//     }

//     // sắp xếp hai vector
//     sort(a.begin() + 1, a.end());
//     sort(b.begin() + 1, b.end());

//     long long cnt = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         // tìm vị trí phần tử đầu tiên không nỏ hone a[i] - k
//         auto it = lower_bound(b.begin() + 1, b.end(), a[i] - k);
//         if (it != b.end() && *it <= a[i] + k)
//         {
//             cnt++;
//             // cập nhật lại giá trị
//             b[it - b.begin()] = 0;
//         }
//     }

//     cout << cnt;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
 
long long n, x;
long long p[200005];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}

	sort(p+1, p+n+1);

	long long cnt = 0;

	int j = n;
	int i = 1;
	while(i <= j){
		if(i != j && p[i] + p[j] <= x) cnt++, i++, j--;
		if(i != j && p[i] + p[j] > x) cnt++, j--;
		if(i == j) cnt++, i++;
	}
    
	cout << cnt;
	return 0;
}
