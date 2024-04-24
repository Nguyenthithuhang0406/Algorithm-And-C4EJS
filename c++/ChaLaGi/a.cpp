#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[10] = [1,2,3,4,5,6,7,8,9,10];

    // Sử dụng break và continue trong vòng lặp for
    for (int i = 0; i < 10; ++i) {
        if (i == 2) {
            continue; // Bỏ qua phần tử thứ 3
        }
        if (i == 4) {
            break; // Kết thúc vòng lặp khi in ra hết 5 phần tử đầu
        }
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}