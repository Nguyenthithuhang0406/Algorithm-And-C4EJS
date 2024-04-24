#include <bits/stdc++.h>
using namespace std;

// sắp xếp vun đống

// hàm hoán vị đổi vị trí 2 phần tử
void Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// hàm xây dựng và duy trì tính chất cây trong Heap
void PushDown(int a[], int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
    {
        if (last == 2 * r + 1)
        {
            if (a[r] > a[last])
            {
                Swap(&a[r], &a[last]);
            }
            r = last;
        }
        else
        {
            if ((a[r] > a[2 * r + 1]) && (a[2 * r + 1] <= a[2 * r + 2]))
            {
                Swap(&a[r], &a[2 * r + 1]);
                r = 2 * r + 1;
            }
            else
            {
                if ((a[r] > a[2 * r + 2]) && (a[2 * r + 2] < a[2 * r + 1]))
                {
                    Swap(&a[r], &a[2 * r + 2]);
                    r = 2 * r + 2;
                }
                else
                {
                    r = last;
                }
            }
        }
    }
}

// sắp xếp vun đống
void HeapSort(int a[], int n)
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
    {
        PushDown(a, i, n - 1);
    }
    for (int i = n - 1; i >= 2; i--)
    {
        Swap(&a[0], &a[i]);
        PushDown(a, 0, i - 1);
    }
    Swap(&a[0], &a[1]);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}