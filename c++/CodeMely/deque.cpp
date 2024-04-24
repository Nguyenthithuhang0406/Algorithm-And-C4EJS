#include <iostream>
#include <deque>
using namespace std;
int main()
{
    // Khởi tạo một deque rỗng
    deque<int> d;
    // Thêm phần tử vào cuối deque
    d.push_back(5);
    d.push_back(6);
    // Thêm phần tử vào đầu deque
    d.push_front(4);
    d.push_front(3);
    // Hiển thị các phần tử trong deque
    cout << "Deque sau khi thêm các phần tử: "; /// Deque sau khi thêm các phần tử: 3 4 5 6
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
    // Loại bỏ phần tử ở cuối deque
    d.pop_back();
    // Loại bỏ phần tử ở đầu deque
    d.pop_front();
    // Hiển thị các phần tử trong deque sau khi loại bỏ
    cout << "Deque sau khi loại bỏ các phần tử: "; // Deque sau khi loại bỏ các phần tử: 4 5
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
    // Chèn phần tử vào deque
    deque<int>::iterator it = d.begin() + 1;
    d.insert(it, 10); // Chèn phần tử 10 vào vị trí thứ hai
    // Hiển thị các phần tử trong deque sau khi chèn
    cout << "Deque sau khi chèn phần tử 10: "; // Deque sau khi chèn phần tử 10: 4 10 5
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
    // Xoá phần tử trong deque
    it = d.begin() + 1;
    d.erase(it); // Xoá phần tử ở vị trí thứ hai
    // Hiển thị các phần tử trong deque sau khi xoá
    cout << "Deque sau khi xoá một phần tử: "; /// Deque sau khi xoá một phần tử: 4 5
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
    // Đổi nội dung của hai deque
    deque<int> newDeque = {100, 200, 300};
    d.swap(newDeque);
    // Hiển thị các phần tử trong deque sau khi đổi
    cout << "Deque sau khi đổi: "; // Deque sau khi đổi: 100 200 300
    for (int num : d)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
