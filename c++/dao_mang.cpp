// input: Nhập vào từ bàn phím một mảng bất kì, kiểu số nguyên
// output: in ra mảng sau khi đảo

#include <bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        // hoán đổi giá trị của hai phần tử
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // di chuyển con trỏ đầu tiên lên và con trỏ cuối cùng lùi xuống
        start++;
        end--;
    }
}

int main()
{
    int n;
    cout << "nhập số lượng phần tử của mảng: ";
    cin >> n;

    int arr[n];
    cout << "\n nhập các giá trị của mảng: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverse_array(arr, n);

    cout << "\n mảng sau khi đảo là: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}