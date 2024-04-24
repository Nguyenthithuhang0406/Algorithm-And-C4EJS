//Code Mely
//Dev ơi mình đi đâu thế
//Thuật toán hashing
//tìm số lần xuất hiện của số t trong số s
//vd: s = 12309123462123
// t = 123
// => kq = 3

typedef long long ll;
int main(){
    ll s, t;
    cin >> s >> t;

    vector<ll> a; //mảng a lưu các chữ số trong s
    //tách các chữ số trong s cho vào mảng a
    while(s > 0){
        a.push_back(s % 10);
        s /= 10;
    }
    a.push_back(-1);
    reverse(a.begin(), a.end()); //đảo ngược mảng a

    ll n = a.size(), m = log10(t) + 1;
    //n là số phần tử của mảng a, m là số chữ số của t;
    vector<ll> pref(n+1);
    for(ll i = 1; i <= n; i++)
        pref[i] = pref[i-1] * 10 + a[i];
    //mảng pref lưu các số có i chữ số từ số s
    // vd số s = 12309123462123 sẽ tạo thành mảng pref như sau
    //  1 12 123 1230 12309 123091 1230912 12309123 123091234 1230912346 12309123462 123091234621 1230912346212 12309123462123

    ll res = 0;
    for(ll i = 1; i < n - m; i++){
        ll x = pref(i + m - 1) - pref[i-1] * pow(10, m);    // tách số có m chữ số từ vị trí i trong số s
        if(x == t)                                         /* vd số có 3 chữ số từ vị trí 5 trong số t là:
            res ++;                                         t = 912 = pref[7] - pref[4] * 10^m = 
    }                                                               = 1230912 - 1230 * 1000; */

    cout << res;
}

//Code Mely
//Dev ơi mình đi đâu thế
//hashing áp dụng với 2 chuỗi
//tìm số lần xuất hiện của chuỗi s trong chuỗi t
//khi chuỗi có độ dài quá lớn ta nên sử lý theo số lớn bằng cách MOD

typedef long long ll;
const int base = 31;    //bảng chữ cái có 26 số nên lấy số nguyên tố gần nhất là 31
const long long MOD = 10000007;

int main(){
    string s, t;
    cin >> s >> t;
    s = "." + s;
    t = "." + t;

    long long n = s.size(), m = t.size();
    ll hashS = 0; hashT = 0;
    for(ll i = 1; i < n; i++)
        hashS = hashS * base % MOD + (s[i] - 'a' + 1) % MOD;   //mã hóa chuỗi s sang số
    
    for(ll i = 1; i < m; i++)
        hashT = hashT * base % MOD + (t[i] - 'a' + 1) % MOD;   //mã hóa chuỗi t sang số

    vector<ll> pref(n+1);
    for(ll i = 1; i < n; i++)
        pref[i] = pref[i - 1] * base % MOD + (s[i] - 'a' + 1) % MOD; 
        //mảng pref lưu các số có i chữ số từ số hashS
    
    ll p =1;
    for(ll i = 0; i < m-1; i++)
        p = p * base % MOD;     //tạo  p = base ^ m;

    ll res = 0; //biến res đếm số lần xuất hiện của hashT trong hashS 
                //cũng chính là số lần xuất hiện của t trong s
    for(ll i =1; i <= n-m+1; i++){
        ll x = (pref[i + m - 2] - pref[i-1] * p % MOD + MOD) % MOD;   //tách số có m-1 chữ số từ vị trí i trong số hashS
        if(x == hashT)
            res ++;
    }

cout << res;

}