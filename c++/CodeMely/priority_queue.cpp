#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Khởi tạo một priority_queue để lưu trữ các số nguyên
    priority_queue<int> pq;

    // Đẩy các phần tử vào priority_queue
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    // Hiển thị phần tử đầu tiên của priority_queue
    cout << "Phần tử đầu tiên (lớn nhất): " << pq.top() << endl;

    // Kích thước của priority_queue
    cout << "Kích thước hiện tại của priority_queue: " << pq.size() << endl;

    // Kiểm tra xem priority_queue có rỗng không
    cout << "Priority_queue có rỗng không? " << (pq.empty() ? "Có" : "Không") << endl;

    // Loại bỏ phần tử đầu tiên của priority_queue
    pq.pop();

    // Hiển thị phần tử đầu tiên mới của priority_queue
    cout << "Phần tử đầu tiên mới (lớn nhất) sau khi pop: " << pq.top() << endl;

    // Kích thước của priority_queue sau khi loại bỏ một phần tử
    cout << "Kích thước của priority_queue sau khi pop: " << pq.size() << endl;

    return 0;
}
