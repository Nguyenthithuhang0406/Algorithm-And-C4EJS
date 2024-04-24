#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stack; // Khai báo một stack để lưu trữ các số nguyên

    // Đẩy phần tử vào stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Truy cập tới phần tử ở đỉnh stack
    cout << "Phần tử trên cùng của stack: " << stack.top() << endl;

    // Loại bỏ phần tử ở đỉnh stack
    stack.pop();
    cout << "Phần tử trên cùng sau khi pop: " << stack.top() << endl;

    // Kiểm tra kích thước của stack
    cout << "Kích thước của stack: " << stack.size() << endl;

    // Kiểm tra stack có rỗng không
    cout << "Stack có rỗng không? " << (stack.empty() ? "Có" : "Không") << endl;

    // Loại bỏ các phần tử còn lại để minh họa hàm empty
    stack.pop();
    stack.pop();
    cout << "Stack có rỗng không sau khi pop tất cả phần tử? " << (stack.empty() ? "Có" : "Không") << endl;

    return 0;
}
