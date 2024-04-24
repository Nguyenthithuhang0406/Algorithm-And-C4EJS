// LinearSearch

#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // trả về vị trí của giá trị cần tìm
        }
    }
    return -1; // trả về -1 nếu không tìm thấy giá trị cần tìm
}

int main()
{
    int n;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;

    int arr[n];
    cout << "\n nhập mảng: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "\n nhập giá trị cần tìm: ";
    cin >> key;

    int index = linearSearch(arr, n, key);
    if (index == -1)
    {
        cout << "\n không tìm thấy.";
    }
    else
    {
        cout << "\n số cần tìm ở vị trí: " << index;
    }

    return 0;
}

// binarySearch

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1; // không tìm thấy thì trả về -1
}

int main()
{
    int n;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;

    int arr[n];
    cout << "\n nhập mảng: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "\n nhập giá trị cần tìm: ";
    cin >> target;

    int index = binarySearch(arr, 0, n - 1, target);
    if (index == -1)
    {
        cout << "\n không tìm thấy.";
    }
    else
    {
        cout << "\n số cần tìm ở vị trí: " << index;
    }

    return 0;
}

// tìm kiếm bằng bảng băm(hashing)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, string> hashTable;

    hashTable[1] = "One";
    hashTable[2] = "Two";
    hashTable[3] = "Three";

    int keyToSearch = 2;
    auto it = hashTable.find(keyToSearch);
    if (it != hashTable.end())
    {
        cout << "key found! Value = " << it->second;
    }
    else
    {
        cout << "key not found!";
    }

    return 0;
}

// jumpSearch

#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n); // kích thước của bước nhảy
    int prev = 0;

    // tìm vị trí của khoảng chứa giá trị cần tìm
    while (arr[min(step, n) - 1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;
    }

    if (arr[prev] == x)
    {
        return prev;
    }

    return -1;
}
int main()
{
    int n;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;

    int arr[n];
    cout << "\n nhập mảng: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "\n nhập giá trị cần tìm: ";
    cin >> key;

    int index = jumpSearch(arr, x, n);
    if (index != -1)
    {
        cout << "\n số cần tìm ở vị trí: " << index;
    }
    else
    {
        cout << "\n không tìm thấy.";
    }

    return 0;
}

// Recursive search

#include <bits/stdc++.h>
using namespace std;

int recursiveSearch(int arr[], int left, int right, int target)
{
    if (left > right)
        return -1; // không tìm thấy

    int mid = (left + right) / 2;
    if (arr[mid] == target)
    {
        return mid; // trả về vị trí phần tử cần tìm
    }

    if (arr[mid] > target)
    {
        // tìm kiếm nửa đầu của mảng
        return recursiveSearch(arr, left, mid - 1, target);
    }
    else
    {
        // tìm kiếm nửa sau của mảng
        return recursiveSearch(arr, mid + 1, right, target);
    }
}

int main()
{
    int n;
    cout << "Nhập số lượng phần tử của mảng: ";
    cin >> n;

    int arr[n];
    cout << "\n nhập mảng: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "\n nhập giá trị cần tìm: ";
    cin >> target;

    int index = recursiveSearch(arr, 1, n - 1, target);

    if (index != 1)
    {
        cout << "\n phần tử cần tìm ở vị trí: " << index;
    }
    else
    {
        cout << "\n không tìm thấy trong mảng.";
    }

    return 0;
}