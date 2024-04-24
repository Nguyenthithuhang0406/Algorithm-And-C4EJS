//nhập vào l,r,a,b,c
//đếm xem trong khoảng [l,r] có bao nhiêu số chia hết cho a hoặc b hoặc c

#include<bits/stdc++.h>
using namespace std; 

int main(){
    int l, r, a, b, c, res;
    cin >> l >> r >> a >> b >> c;
    //xác định các số chia hết cho a trong khoảng [l,r]
    res += (r/a - (l-1)/a);
    //xác định các số chia hết cho b trong khoảng [l,r]
    res += (r/b - (l-1)/b);
    //xác định các số chia hết cho c trong khoảng [l,r]
    res += (r/c - (l-1)/c);
    
    //xác định các số bị lặp và trừ đi
    res -= (r/(a*b) - (l-1)/ (a*b));
    res -= (r/(b*c) - (l-1)/ (b*c));
    res -= (r/(c*a) - (l-1)/ (c*a));

    //cộng thêm lượng số chia hết cho cả a, b và c
    res += (r/(a*b*c) - (l-1)/ (a*b*c));
    
    cout << res;
    return 0;
}


//nhập l, r, n
//nhập mảng a gồm n số
//đếm trong khoảng [l,r] những số chia hết cho a[i], i=1,2,3,....,n
#include<bits/stdc++.h>
using namespace std;

//hàm tìm bội chung nhỏ nhất của x,y
long long lcm(long long x, long long y){
    return (x*y) / __gcd(x,y);
}

// Hàm đếm duyệt qua tất cả các tổ hợp của các số trong mảng, 
// bắt đầu từ mảng chỉ chứa 1 số và kết thúc là mảng chứa tất cả các số
long long dem(long long x){
    long long res = 0;
    for(int i = 1; i <(1 << n); ++i){
        long long lcm_m = 1, size = 0;
        for(int j = 0; j < n; ++j){
            if(i & (1 << j)){
                ++size;
                lcm_m = lcm(lcm_m, a[i]);

                if(lcm_m > x){
                    lcm_m = -1;
                    break;
                }
            }
        }

        if(lcm_m != -1){
            if(size % 2 == 1){
                res += x / lcm_m;
            }else{
                res -= x / lcm_m;
            }
        }
    }
    return res;
}
int main(){
    long long l,r,n;
    cin >> l >> r >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << dem(r) - dem(l - 1);
    return 0;
}