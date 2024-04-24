#include<bits/stdc++.h>
using namespace std;

// Hàm đệ quy để đếm số cách phân tích x thành tổng lũy thừa bậc n
int countWays(int x, int n, int start) {
    if (x == 0) {
        return 1; // Tìm được một cách phân tích
    }

    int ways = 0;

    // Duyệt qua các số nguyên dương từ start đến căn bậc n của x
    for (int i = start; pow(i, n) <= x; i++) {
        ways += countWays(x - pow(i, n), n, i + 1);
    }

    return ways;
}

int main() {
    int x, n;

    // Nhập vào hai số nguyên x và n
    cout << "Nhap vao so nguyen x: ";
    cin >> x;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;

    // Gọi hàm đếm số cách phân tích và hiển thị kết quả
    int result = countWays(x, n, 1);
    cout << "So cach phan tich " << x << " thanh tong cac luy thua bac " << n << " la: " << result << endl;

    return 0;
}
