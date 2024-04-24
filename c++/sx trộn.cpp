#include <bits/stdc++.h>
using namespace std;

// sắp xếp trộn
void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    // so sánh và trộn các phần tử của hai nửa
    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[i])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // đưa các phần tử còn lại của hai nửa vào mảng kết quả
    while (i < left_size)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size)
{
    if (size <= 1)
        return;

    int middle = size / 2;
    int left[middle];
    int right[size - middle];

    // chia mảng thành hai nửa
    for (int i = 0; i < middle; i++)
    {
        left[i] = arr[i];
    }
    for (int i = middle; i < size; i++)
    {
        right[i - middle] = arr[i];
    }

    // đệ quy sắp xếp từng nửa
    mergeSort(left, middle);
    mergeSort(right, size - middle);

    // trộn hai nửa đã sắp xếp
    merge(arr, left, middle, right, size - middle);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, size);
    printArray(arr, size);
    return 0;
}
