#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    bool arr[3005];
    memset(arr, false, sizeof(arr));
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        arr[a] = true;
    }
    for (int i = 1; i <= 3005; ++i) {
        if (arr[i] == false) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
