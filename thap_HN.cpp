
#include <bits/stdc>
using namespace std;

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << from_rod << " sang " << to_rod << endl;
        return;
    }
    TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Di chuyen dia " << n << " tu " << from_rod << " sang " << to_rod << endl;
    TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    cout << "Nhap so dia: ";
    cin >> n;
    cout << "Các buoc di chuyen de giai bài toán Tháp Hà Noi voi " << n << " dia:" << endl;
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}


