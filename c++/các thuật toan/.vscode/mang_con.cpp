// //Tìm mảng con sao cho tổng các phần tử bằng s
// #include<bits/stdc++.h>
// using namespace std;

// int a[100005];
// int n, s;

// void findSubarrayWithSumM(){
//     int left = 0, right = 0, currentSum = 0;
//     //vị trí bắt đầu, kết thúc, tổng hiện tại của mảng con
//     while(right < n){
//         currentSum += a[right];

//         while(currentSum > s && left <= right){
//             currentSum -= a[left];
//             left ++;
//         }

//         if(currentSum == s){
//             //in kết quả
//             for(int i = left; i <= right; i++)
//                 cout << a[i] << " ";
//             cout << "\n";
//             return;
//         }
//         right ++;
//     } 
//     //nếu không tồn tại mảng con thoả mãn
//     cout << "Khong co mang con co tong cac phan tu bang s";

// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cin >> n >> s;
//     for(int i = 0; i < n; i ++) cin >> a[i];
//     findSubarrayWithSumM();
//     return 0;
// }

// //tìm dãy con dương có tổng lớn nhất
// #include<bits/stdc++.h>
// using namespace std;

// int a[100005];
// int n;

// void findMaxPositiveSubarray(){
//     int left = 0, right = 0, currentLeft = 0, currentRight = 0, currentSum = 0;
//     //vị trí bắt đầu, kết thúc của dãy con toàn dương có tổng lớn nhất, vị trí bắt đầu, kết thúc và tổng của dãy con toàn dương hiện tại
//     int maxSum = 0; //tổng lớn nhất của dãy toàn dương
//     for(int i = 0; i < n; i++){
//         //nếu a[i] là số dương thì cộng vào dãy con hiện tại, và cập nhật vị trí kết thúc
//         if(a[i] > 0){
//             currentSum += a[i];
//             currentRight = i;
//         }
//         else{
//             //ngược lại, so sánh nếu tổng dãy con lớn hơn giá trị max, thì cập nhật lại max và vị trí bắt đầu của dãy con
//             if(currentSum > maxSum){
//                 maxSum = currentSum;
//                 left = currentLeft;
//                 right = currentRight;
//             }
//             //khởi tạo lại giá trị của tổng và vị trí bắt đầu
//             currentSum = 0;
//             currentLeft = i + 1;
//         }
//     }
//     if(currentSum > maxSum){
//         maxSum = currentSum;
//         left = currentLeft;
//     }
//     for(int i = left; i <= right; i++) cout << a[i] << " ";
//     cout << "\n";
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cin >> n;
//     for(int i = 0; i < n; i ++) cin >> a[i];
//     findMaxPositiveSubarray();
//     return 0;
// }


// //tìm dãy con liên tiếp có tổng lớn nhất
// #include <bits/stdc++.h>
// using namespace std;

// int n ;
// int a[100005];

// void findSubArrayMaxWithIndices() {
//     int sumMax = INT_MIN, sum = 0;
//     //tổng lớn nhất và tổng của dãy hiện tại
//     int left = 0, right = 0, currentLeft = 0;
//     //vị trí bắt đầu, kết thúc của dãy có tổng lớn nhất, vị trí bắt đầu của dãy hiện tại
//     for (int i = 0; i < n; i++) {
//         if (sum + a[i] < a[i]) {
//             currentLeft = i;
//             sum = a[i];
//         } else {
//             sum += a[i];
//         }
//         if (sumMax < sum) {
//             sumMax = sum;
//             left = currentLeft;
//             right = i;
//         }
//     }
//     for(int i = left; i <= right; i ++) cout << a[i] << " ";
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cin >> n;
//     for(int i = 0; i <n ; i++) cin >> a[i];
//     findSubArrayMaxWithIndices();
//     return 0;
// }