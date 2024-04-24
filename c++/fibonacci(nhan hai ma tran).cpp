// Code Mely
// Dev ơi mình đi đâu thế

#include <bits/stdc++.h>
using namespace std;

// khai bao ma tran
struct matrix
{
    long long mtx[2][2];
};
matrix f, a, b;

// khoi tao
void init()
{
    f.mtx[0][0] = 0;
    f.mtx[0][1] = 1; // f la ma tran ban dau

    a.mtx[0][0] = 0; // a la ma tran nhan
    a.mtx[0][1] = a.mtx[1][0] = a.mtx[1][1] = 1;

    b.mtx[0][0] = b.mtx[1][1] = 1; // b la ma tran don vi
}

// nhan hai ma tran
matrix mul(matrix a, matrix b)
{
    matrix result;
    for (long long i = 0; i < 2; i++)
        for (long long j = 0; j < 2; j++)
        {
            result.mtx[i][j] = 0;
            for (long long k = 0; k < 2; k++)
                result.mtx[i][j] += a.mtx[i][k] * b.mtx[k][j];
        }
    return result;
}

// luy thua cua matran a
matrix binPow(matrix a, long long n)
{
    if (n == 0)
        return b;

    matrix x = binPow(a, n / 2);
    if (n % 2)
        return mul(mul(x, x), a);
    return mul(x, x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << "0";
    }
    else
    {
        if (n == 1)
        {
            cout << "1";
        }
        else
        {
            init();
            matrix result = mul(f, binPow(a, n - 2));
            cout << result.mtx[0][1];
        }
    }
    return 0;
}