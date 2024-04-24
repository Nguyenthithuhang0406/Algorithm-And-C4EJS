#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // Khởi tạo vector
    vector<int> numbers = {1, 2, 3, 4, 5};
    // Thêm phần tử vào cuối vector
    numbers.push_back(6);
    cout << "Vector sau khi thêm phần tử 6: "; // Vector sau khi thêm phần tử 6: 1 2 3 4 5 6
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout <<endl;
    // Loại bỏ phần tử ở cuối vector
    numbers.pop_back();
    cout << "Vector sau khi loại bỏ phần tử cuối cùng: "; // Vector sau khi loại bỏ phần tử cuối cùng: 1 2 3 4 5
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    // Chèn phần tử vào trước vị trí iterator
    auto it = numbers.begin() + 2;
    numbers.insert(it, 10);
    cout << "Vector sau khi chèn phần tử 10 vào vị trí thứ 3: "; // Vector sau khi chèn phần tử 10 vào vị trí thứ 3: 1 2 10 3 4 5
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    // Xoá phần tử ở vị trí iterator
    numbers.erase(numbers.begin() + 2);
    cout << "Vector sau khi xoá phần tử ở vị trí thứ 3: "; // Vector sau khi xoá phần tử ở vị trí thứ 3: 1 2 3 4 5
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    // Khởi tạo vector mới để hoán đổi
    vector<int> otherNumbers = {6, 7, 8, 9, 10};
    // Hoán đổi vector
    numbers.swap(otherNumbers);
    cout << "Vector sau khi hoán đổi: "; // Vector sau khi hoán đổi: 6 7 8 9 10
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    // Xoá vector
    numbers.clear();
    cout << "Vector sau khi xoá: "; // Vector sau khi xoá:
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
