// //cách 1 : sử dụng mảng
// //Độ phức tạp: O(n)

// #include<bits/stdc++.h>
// using namespace std;

// //n: số lượng phần tử trong dãy
// int n;
// int a[200000];

// void solve() {
//     //tìm số lớn nhất trong dãy
//     int maxNumber = 0 ;
//     for(int i = 0; i < n; i++){
//         maxNumber = max(maxNumber, a[i]);
//     }

// //khởi tạo mảng đếm số lần xuất hiện các số từ 0 đến maxNumber
//     int counts[maxNumber + 1] = {0};

// // đếm số lần xuất hiện các số
//     for (int i = 0; i < n; i++) {
//             counts[a[i]]++;
//     }

//     for(int i = 0; i <= maxNumber; i++){
//         if(counts[i] != 0){
//             cout << "so " << i << " xuat hien : " << counts[i] << " lan. \n";
//         }
//     }
// }

// int main() {
//     cout << "Nhap so luong phan tu cua day: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua day: \n";
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     solve();
//     return 0;
// }

// //2. sử dụng map
// //Độ phức tạp: O(nlogn)

// #include<bits/stdc++.h>
// using namespace std;

// //n: số lượng phần tử trong dãy
// int n;
// int a[200000];

// void solve() {
//     map<int, int> counts; //map lưu trữ các cặp key(số), value(số lần xuất hiện)

//     // Đếm số lần xuất hiện của mỗi số
//     for (int i = 0; i < n; i++) {
//         counts[a[i]]++;
//     }

//     // In số lần xuất hiện của mỗi số
//     for (pair<int, int> x : counts) {
//         cout << "So " << x.first << " xuat hien : " << x.second << " lan. \n" ;
//     }
// }

// int main() {
//     cout << "Nhap so luong phan tu cua day: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua day: \n";
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     solve();

//     return 0;
// }

// //3. sử dụng unordered_map
// //Độ phức tạp: O(n)

// #include<bits/stdc++.h>
// using namespace std;

// //n: số lượng phần tử trong dãy
// int n;
// int a[200000];

// void solve() {
//     unordered_map<int, int> counts;

//     // Đếm số lần xuất hiện của mỗi số
//     for (int i = 0; i < n; i++) {
//         counts[a[i]]++;
//     }

//     // In số lần xuất hiện của mỗi số
//     for (auto pair : counts) {
//         cout << "So " << pair.first << " xuat hien : " << pair.second << " lan. \n" ;
//     }
// }

// int main() {
//     cout << "Nhap so luong phan tu cua day: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua day: \n";
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     solve();

//     return 0;
// }

// // 4.sort
// // Độ phức tạp: O(nlogn)

// #include <bits/stdc++.h>
// using namespace std;

// // n: số lượng phần tử trong dãy
// int n;
// int a[200000];

// void solve()
// {
//     // sắp xếp mảng tăng dần
//     sort(a, a + n);

//     int count = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i > 0 && a[i] == a[i - 1])
//         {
//             count++;
//         }
//         else
//         {
//             if (i > 0)
//             {
//                 cout << "So " << a[i - 1] << " xuat hien : " << count << " lan. \n";
//                 count = 1;
//             }
//         }
//     }
//     // trường hợp số cuối cùng của dãy
//     cout << "So " << a[n - 1] << " xuat hien : " << count << " lan. \n";
// }
// int main()
// {
//     cout << "Nhap so luong phan tu cua day: \n";
//     cin >> n;
//     cout << "nhap cac phan tu cua day: \n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     solve();

//     return 0;
// }

