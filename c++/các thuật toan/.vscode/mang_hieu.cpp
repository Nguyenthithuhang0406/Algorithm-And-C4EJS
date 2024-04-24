//Dev ơi mình đi đâu thế?
//Code MeLy

//Mảng hiệu (difference array)
//ứng dụng: thay đổi 1 lượng k vào đoạn con [l,r] của mảng A
//cho một mảng A có vô số phần tử 0, 
//có n truy vấn , mỗi truy vấn yêu cầu lập nhật toàn bộ phần tử [l, r] lên 1 đơn vị
//q truy vấn: đếm số vị trí i trong đoạn [l,r] thoả mãn ai >= k;
#include<bits/stdc++.h>
using namespace std;

int n, q, k;
long long a[200005], d[200005], s[200005];//d là mảng hiệu, s là mảng cộng dồn

void  update(int l, int r){
    ++d[l], --d[r+1]; //cập nhật giá trí của mảng d tại 2 biên
}

void buildPrefixSum(){
    s[1] = a[1] = 0;
    for(int i = 2; i <= n; i++){
        a[i] = a[i-1] + d[i];
        s[i] = s[i-1] + (a[i] >= k);
    }
}

void solve(){
    cin >> n >> k >> q; // độ dài mảng và số lượng truy vấn
    fỏ(int i = 1; i <= n; i++){
        int l, r; cin >> l >> r;
        update(l,r);
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << s[r] - s[l-1] << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}