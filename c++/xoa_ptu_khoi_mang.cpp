// input: nhập vào từ bàn phím một mảng bất kì, kiểu số nguyên
// output: in ra mảng sau khi xoá

#include <bits/stdc++.h>
using namespace std;

void delete_element(int arr[], int n, int index)
{
    if (index >= 0 && index < n)
    {
        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1]; // di chuyển các ptử từ vị trí cần xoá trở đi sang trái
        }
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

    int index;
    cout << "\n nhập vị trí cần xoá phần tử: ";
    cin >> index;

    if (index < 0 || index >= n)
    {
        cout << "\n vị trí xoá không hợp lệ" return 1;
    }
    delete_element(arr, n, index);
    n--;

    cout << "\n mảng sau khi xoá là: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}