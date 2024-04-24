// input: nhập từ bàn phím một mảng bất kì, kiểu số nguyên
// output: in ra mảng sau khi chèn

#include <bits/stdc++.h>
using namespace std;

void insert_element(int arr[], int n, int index, int value)
{
    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i]; // di chuyển các phần tử từ vị trí chèn trở đi sang phải
    }
    arr[index] = value; // chèn phần tử mới vào vị trí cần chèn
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

    int index, value;
    cout << "\n nhập vị trí cần chèn phần tử: ";
    cin >> index;

    if (index < 0 || index > n)
    {
        cout << "\n vị trí chèn không hợp lệ" return 1;
    }

    cout << "\n Nhập giá trị cần chèn: ";
    cin >> value;

    insert_element(arr, n, index, value);
    n++; // tăng số lượng phần tử sau khi chèn

    cout << "\n mảng sau khi chèn là: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}