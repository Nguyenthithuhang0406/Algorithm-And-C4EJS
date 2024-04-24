//Các thuật toán sắp xép cơ bản _ ctdl&gt
//Dev ơi mình đi đâu thế?

//sắp xếp nổi bọt_ bubbleSort:
//thực hiện việc đổi chỗ các cặp phần tử kế tiếp trong dãy đối tượng cần sắp xếp nếu chúng chưa đúng thứ tự
#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

void nhap(){
    cin >> n; //số lượng phần tử của mảng
    //nhập mảng
    for(int i = 0; i < n; i++){
        cin >>  a[i];
    }
}

void bubbleSort(){
    for(int i = 1; i < n; i++)
        for(int j = n-1; j >= i ; j--)
            if(a[j] < a[j-1]) swap(a[j], a[j-1]);
}
void xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    nhap();
    bubbleSort();
    xuat();
    return 0;
}



//Các thuật toán sắp xép cơ bản _ ctdl&gt
//Dev ơi mình đi đâu thế?

//Sắp xếp lựa chọn_SelectionSort
//Dựa vào thuật toán tìm phần tử nhỏ nhất
//Duyệt và tìm phần tử nhỏ nhất của dãy và dổi chỗ các phần tử đó cho phần tử đầu dãy

#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

void nhap(){
    cin >> n; //số lượng phần tử của mảng
    //nhập mảng
    for(int i = 0; i < n; i++){
        cin >>  a[i];
    }
}

void SelectionSort(){
    for(int i = 0; i < n-1; i++){
        int m = i;
        for(int j = i + 1; j < n; j++)
            if(a[j] < a[m]) m = j;
        swap(a[i], a[m]);
    }
}

void xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    nhap();
    SelectionSort();
    xuat();
    return 0;
}




//Các thuật toán sắp xép cơ bản _ ctdl&gt
//Dev ơi mình đi đâu thế?

//sắp xếp chèn _ InsertionSort
//chèn một phần tử vào dãy đã được sắp xếp sao cho trật tự của dãy không bị thay đổi
//duyệt và tìm vị trí thích hợp cho phần tử mới trong dãy
//chèn phần tử mới vào vị trí thích hợp

#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

void nhap(){
    cin >> n; //số lượng phần tử của mảng
    //nhập mảng
    for(int i = 0; i < n; i++){
        cin >>  a[i];
    }
}

void InsertionSort(){
    for(int i = 1; i< n; i++){
        int tmp = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > tmp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
    }
}

void xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    nhap();
    InsertionSort();
    xuat();
    return 0;
}


//Các thuật toán sắp xép nâng cao _ ctdl&gt
//Dev ơi mình đi đâu thế?

//sắp xếp nhanh_QuickSort
//chia bài toán thành các bài toán con
//Giải quyết các bài toán con
//tổng hợp kết quả

#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

void nhap(){
    cin >> n; //số lượng phần tử của mảng
    //nhập mảng
    for(int i = 0; i < n; i++){
        cin >>  a[i];
    }
}

void QuickSort(int t, int p){
    if(t < p){
        int i = t, j = p, chot  = a[(t+p)/2];
        while(i < j){
            while(a[i] < chot) i++;
            while(a[j] > chot) j--;
            if(i <= j) swap(a[i], a[j]), i++, j--;
        }
        QuickSort(i, p);
        QuickSort(t, j);
    }
}

void xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    nhap();
    QuickSort();
    xuat();
    return 0;
}


//Các thuật toán sắp xép nâng cao _ ctdl&gt
//Dev ơi mình đi đâu thế?

//Sắp xếp vun đống _HeapSort
//tạo đống đầu tiên
//lặp lại quá trình (n-1 lần)
//+đổi chỗ phần tử đầu cho phần tử cuối
//+loại phần tử cuối
//+vun đống cho nút đầu tiên


#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[200005];

void nhap(){
    cin >> n; //số lượng phần tử của mảng
    //nhập mảng
    for(int i = 0; i < n; i++){
        cin >>  a[i];
    }
}

// hàm xây dựng và duy trì tính chất cây trong Heap
void PushDown( int first, int last)
{
    int r = first;
    while (r <= (last - 1) / 2)
    {
        if (last == 2 * r + 1)
        {
            if (a[r] > a[last])
            {
                Swap(a[r], a[last]);
            }
            r = last;
        }
        else
        {
            if ((a[r] > a[2 * r + 1]) && (a[2 * r + 1] <= a[2 * r + 2]))
            {
                Swap(a[r], a[2 * r + 1]);
                r = 2 * r + 1;
            }
            else
            {
                if ((a[r] > a[2 * r + 2]) && (a[2 * r + 2] < a[2 * r + 1]))
                {
                    Swap(a[r], a[2 * r + 2]);
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
void HeapSort()
{
    int i;
    for (i = (n - 2) / 2; i >= 0; i--)
    {
        PushDown(a, i, n - 1);
    }
    for (int i = n - 1; i >= 2; i--)
    {
        Swap(a[0], a[i]);
        PushDown(a, 0, i - 1);
    }
    Swap(a[0], a[1]);
}


void xuat(){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}
int main(){
    nhap();
    HeapSort();
    xuat();
    return 0;
}


//Các thuật toán sắp xép nâng cao _ ctdl&gt
//Dev ơi mình đi đâu thế?

//Sắp xếp trộn_MergeSort
//trộn hai dãy đã được sắp xếp thành một dãy được sắp xếp

#include <bits/stdc++.h>
using namespace std;

// hàm trộn
void merge(int arr[], int left[], int left_size, int right[], int right_size){
    int i = 0, j = 0, k = 0;
    // so sánh và trộn các phần tử của hai nửa
    while (i < left_size && j < right_size){
        if (left[i] <= right[i]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // đưa các phần tử còn lại của hai nửa vào mảng kết quả
    while (i < left_size){
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right_size){
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size){
    if (size <= 1)
        return;

    int middle = size / 2;
    int left[middle];
    int right[size - middle];

    // chia mảng thành hai nửa
    for (int i = 0; i < middle; i++){
        left[i] = arr[i];
    }
    for (int i = middle; i < size; i++){
        right[i - middle] = arr[i];
    }

    // đệ quy sắp xếp từng nửa
    mergeSort(left, middle);
    mergeSort(right, size - middle);

    // trộn hai nửa đã sắp xếp
    merge(arr, left, middle, right, size - middle);
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main(){
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    mergeSort(arr, size);
    printArray(arr, size);
    return 0;
}
