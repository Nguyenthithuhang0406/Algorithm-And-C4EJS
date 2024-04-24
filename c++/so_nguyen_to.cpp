// phân tích thừa số nguyên tố
// Input: 100
// Output: 2^2 x 5^2
#include <bits/stdc++.h>
using namespace std;

void phanTichNguyenTo(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        ì(n % i == 0)
        {
            int dem = 0;
            while (n % i == 0)
            {
                dem++;
                n /= i;
            }
            cout << i << '^' << dem;
            if (n != 1)
                cout << " x ";
        }
    }
    if (n != 1)
        cout << n << '^' << 1 << "\n";
}

int main()
{
    int n;
    cin >> n;
    phanTichNguyenTo(n);
}

// kiểm tra 1 số có phải số nguyên tố không?
#include <bits/stdc++.h>
using namespace std;

bool kiemTraSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (kiemTraSoNguyenTo(n) == true)
        cout << "YES";
    else
        cout << "NO";
}

// kiểm tra số đặc biệt(số có số lượng ước là số nguyên tố)
// intput: 2   10   18
// souoc:  2   4    8
// output: YES NO   NO
#include <bits/stdc++.h>
using namespace std;

int soLuongUocSo(int n)
{
    int dem = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n / i)
            {
                dem += 2;
            }
            else
            {
                dem += 1;
            }
        }
    }
    return dem;
}

bool kiemTraSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int soluonguoc = soLuongUocSo(n);
    if (kiemTraSoNguyenTo(soluonguoc) == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

// kiểm tra số mạnh mẽ(có tổng chữ số là số nguyên tố)
// input: 47  20  10  18
// output:YES YES NO  NO
#include <bits/stdc++>
using namespace std;

int TongChuSo(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int du = n % 10;
        sum += du;
        n = n / 10;
    }
    return sum;
}

bool kiemTraSoNguyenTo(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int tongchuso = tongChuSo(n);
    if (kiemTraSoNguyenTo(tongchuso) == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}

// tìm số nguyên tố lớn nhất trong một tập số đã cho
#include <bits/stdc++.h>
using namespace std;

// hàm kiểm tra số nguyên tố
bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// hàm tìm số nguyên tố lớn nhất trong một tập số
int findLargestPrime(vector<int> numbers)
{
    int largestPrime = -1;

    for (int num : numbers)
    {
        if (isPrime(num) && num > largestPrime)
        {
            largestPrime = num;
        }
    }

    return largestPrime;
}

int main()
{
    vector<int> numbers = {2, 3, 4, 7, 10, 15, 20};
    int largestPrime = findLargestPrime(numbers);
    cout << "số nguyên tố lớn nhất trong tập số đã cho là: " << largestPrime << endl;
    return 0;
}