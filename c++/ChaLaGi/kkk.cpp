#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> fibMemo;

int fibonacci(int n) {
    if (n <= 1)
        return n;

    if (fibMemo.find(n) != fibMemo.end())
        return fibMemo[n];

    int result = fibonacci(n - 1) + fibonacci(n - 2);
    fibMemo[n] = result;
    return result;
}

int main() {
	int n;
	cout << "nhap n: \n";
	cin >> n;
    int result = fibonacci(n);
    cout << result << endl;

    return 0;
}

