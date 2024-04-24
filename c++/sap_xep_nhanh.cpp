//Các thuật toán sắp xếp nâng cao_ctdl&gt
//Dev ơi mình đi đâu thế?

#include<bits/stdc++.h>
using namespace std;

//sắp xếp nhanh_QuickSort
//chia bài toán thành các bài toán con
//Giải quyết các bài toán con
//tổng hợp kết quả

//hàm hoán đổi vị trí hai phần tử
void Swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Hàm tìm chốt
int FindPivot(int a[], int i, int j){
    int firstkey = a[i];
    int k = i+1;
    while ((k <= j) && (a[k] == firstkey)){
        k++;
    }

    if( k > j)
        return -1;
    else
    if(a[k] > firstkey)
        return k;
    else
        return i;
}


//hàm phân hoạch mảng
int Partition(int a[], int i, int j, int pivot){

    int L = i, R = j;

    while (L <= R){
        while(a[l] < pivot)
            L++;
        while(a[R] >= pivot)
            R--;
        ì(L < R)
            Swap(&a[L], &a[R]);
    }
    return L;
}

//sắp xếp nhanh
void QuickSort(int a[], int i, int j){
    
    int pivot, k;

    int pivot_index = FindPivot(a, i , j);
    if(pivot_index != -1){

        pivot = a[pivot_index];
        k = Partition(a, i, j, pivot);

        QuickSort(a, i, k-1);
        QuickSort(a, k, j);
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    QuickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}