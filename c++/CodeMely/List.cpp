#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    // Khởi tạo và thêm phần tử vào list
    list<int> list1 = {1, 2, 2, 3, 4, 4, 4, 5};
    list<int> list2 = {10, 20, 30};
    // Splice: di chuyển phần tử từ list1 sang list2
    auto it = next(list1.begin(), 3);                    // Iterator tới phần tử thứ 4 của list1
    list2.splice(list2.begin(), list1, it, list1.end()); // Chuyển phần từ thứ 4 đến cuối list1 vào đầu list2
    // In list1 và list2 sau splice
    cout << "List1 sau splice: ";
    for (int num : list1)
    {
        cout << num << " ";
    }
    cout << "\nList2 sau splice: ";
    for (int num : list2)
    {
        cout << num << " ";
    }
    cout << "\n";
    // Remove: xóa tất cả các phần tử '2' trong list1
    list1.remove(2);
    // Remove_if: xóa tất cả các phần tử lớn hơn 10 trong list2
    list2.remove_if([](const int &value)
                    { return value > 10; });
    // In list sau remove và remove_if
    cout << "List1 sau remove: ";
    for (int num : list1)
    {
        cout << num << " ";
    }
    cout << "\nList2 sau remove_if: ";
    for (int num : list2)
    {
        cout << num << " ";
    }
    cout << "\n";
    // Unique: loại bỏ các phần tử trùng lặp liên tiếp trong list1
    list1.unique();
    // Sort và Reverse
    list1.sort();    // Sắp xếp list1
    list1.reverse(); // Đảo ngược list1
    // In list sau các thao tác unique, sort, và reverse
    cout << "List1 sau unique, sort, và reverse: ";
    for (int num : list1)
    {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}
