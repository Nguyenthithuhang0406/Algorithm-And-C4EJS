#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> queue;

    // Đẩy phần tử vào cuối queue
    queue.push(5);
    queue.push(10);
    queue.push(15);

    // Trả về kích thước hiện tại của queue
    cout << "Kích thước của queue: " << queue.size() << endl;

    // Kiểm tra xem queue có rỗng không
    cout << "Queue có rỗng không? " << (queue.empty() ? "Có" : "Không") << endl;

    // Truy cập phần tử ở đầu queue
    cout << "Phần tử ở đầu của queue: " << queue.front() << endl;

    // Truy cập phần tử ở cuối queue
    cout << "Phần tử ở cuối của queue: " << queue.back() << endl;

    // Loại bỏ phần tử ở đầu queue
    queue.pop();
    cout << "Phần tử ở đầu của queue sau khi pop: " << queue.front() << endl;

    // Kiểm tra lại kích thước và trạng thái của queue
    cout << "Kích thước của queue sau khi pop: " << queue.size() << endl;
    cout << "Queue có rỗng không sau khi pop? " << (queue.empty() ? "Có" : "Không") << endl;

    return 0;
}
