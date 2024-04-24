//Code Mely
//Dev ơi mình đi đâu thế
//một số cách kiểm tra số nguyên tố

//cách thông thường, kiểm tra số n có phải là số nguyên tố hay không
bool isprime(int n){
    if(n < 2)
        return false;
    int i = 2;
    while(i * i <= n && n % i != 0)
        i++;
    if(n % i == 0)
        return false;
    return true;
}

//cách 2
bool isprime(int m){
    if(m == 2 || m == 3)
        return 1;
    if(m % 2 == 0 || m % 3 == 0 || m < 2)
        return 0;
    for(int i = 5; i * i <= m ; i += 6)
        if(m % i == 0 || m % (i+2) == 0)
            return 0;
    return 1;
}

//dùng sàng nguyên tố, in ra các số nguyên tố trong đoạn từ l đến r
int main(){
    int l, r;
    cin >> l >> r;
    bool isprime[1000006];
//íprime là mảng đánh dấu các số nguyên tố
    memset(isprime, true, sizeof(isprime));

    isprime[0] = isprime[1] = false;

//tạo sàng
    for(int i = 2; i <= r; i++)
        for(int j = 2 * i ; j <= r; j += i)
            isprime[j] = false;
    
    for(int i = l; i <= r ; i++)
        if(isprime[i] == true)
            cout << i <<" ";

    return 0;
}