#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    // S? d?ng break và continue trong vòng l?p for
    for (int i = 0; i < 10; ++i) {
        if (i == 2) {
            continue; // B? qua ph?n t? th? 3
        }
        if (i == 5) {
            break; // K?t thúc vòng l?p khi in ra h?t 5 ph?n t? d?u
        }
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
