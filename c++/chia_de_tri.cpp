#include <bits/stdc++.h>
using namespace std;

// Hàm tính tổng của một mảng
int sum(vector<int> &arr, int left, int right)
{
    int total = 0;
    for (int i = left; i <= right; i++)
    {
        total += arr[i];
    }
    return total;
}

// Hàm chia để trị tính tổng các phần tử trong mảng
int divideAndConquer(vector<int> &arr, int left, int right)
{
    if (left == right)
    {
        return arr[left];
    }
    else
    {
        int mid = (left + right) / 2;
        int leftSum = divideAndConquer(arr, left, mid);
        int rightSum = divideAndConquer(arr, mid + 1, right);
        int crossingSum = sum(arr, left, right);

        return max(max(leftSum, rightSum), crossingSum);
    }
}

int main()
{
    vector<int> arr = {1, -2, 3, 4, -5, 2, 6, -1};

    int result = divideAndConquer(arr, 0, arr.size() - 1);

    cout << "Tong lon nhat cua day so la: " << result << endl;

    return 0;
}