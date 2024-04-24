// kiểm tra chuỗi đảo ngược bằng stack
#include <bits/stdc++.h>
using namespace std;

bool kiemTraChuoiDaoNguoc(string str)
{
    stack<char> myStack;

    // Đẩy tất cả các ký tự của chuỗi vào ngăn xếp
    for (char ch : str)
    {
        myStack.push(ch);
    }

    // So sánh ký tự từ pop() và ký tự từ chuỗi gốc
    while (!myStack.empty())
    {
        if (myStack.top() != str.front())
        {
            return false;
        }

        myStack.pop();
        str = str.substr(1); // Loại bỏ ký tự đầu tiên của chuỗi
    }

    return true;
}

int main()
{
    string str;
    cout << "Nhap vao mot chuoi: ";
    cin >> str;

    if (kiemTraChuoiDaoNguoc(str))
    {
        cout << "Chuoi la chuoi dao nguoc" << endl;
    }
    else
    {
        cout << "Chuoi khong phai la chuoi dao nguoc" << endl;
    }

    return 0;
}

// chuyển đổi hệ số
#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển đổi hệ số từ hệ thập phân sang hệ khác (ví dụ hệ 2)
void convertToBase(int n, int base)
{
    stack<int> s;

    // Chuyển đổi hệ số
    while (n > 0)
    {
        s.push(n % base);
        n = n / base;
    }

    // In kết quả chuyển đổi từ stack
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main()
{
    int num = 13; // Số cần chuyển đổi
    int base = 2; // Hệ số muốn chuyển đổi

    convertToBase(num, base);

    return 0;
}

// sắp xếp chuỗi kí tự
#include <bits/stdc++.h>
using namespace std;

// hàm sắp xếp chuỗi
void sortStringUsingStack(string &inputStr)
{
    stack<char> sortedStack;

    // Đưa từng ký tự của chuỗi vào stack
    for (char c : inputStr)
    {
        sortedStack.push(c);
    }

    // Xóa ký tự khỏi chuỗi
    inputStr.clear();

    // Lấy ký tự từ stack và thêm vào chuỗi đã xóa
    while (!sortedStack.empty())
    {
        inputStr.push_back(sortedStack.top());
        sortedStack.pop();
    }
}

int main()
{
    string input = "stack";

    sortStringUsingStack(input);

    cout << "Chuỗi kí tự đã sắp xếp: " << input << endl;

    return 0;
}

// kiểm tra dấu ngoặc
#include <bits/stdc++.h>
using namespace std;

bool kiemTraDauNgoac(const string &chuoi)
{
    std::stack<char> stack_dau_ngoac;

    for (char c : chuoi)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stack_dau_ngoac.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (stack_dau_ngoac.empty())
            {
                return false; // Nếu stack là rỗng mà gặp dấu đóng ngoặc thì không hợp lệ
            }
            else if ((c == ')' && stack_dau_ngoac.top() == '(') ||
                     (c == ']' && stack_dau_ngoac.top() == '[') ||
                     (c == '}' && stack_dau_ngoac.top() == '{'))
            {
                stack_dau_ngoac.pop(); // Nếu gặp dấu đóng ngoặc khớp với dấu mở ngoặc trên đỉnh stack, loại bỏ nó khỏi stack
            }
            else
            {
                return false; // Nếu gặp dấu đóng ngoặc không khớp với dấu mở ngoặc trên đỉnh stack, không hợp lệ
            }
        }
    }

    return stack_dau_ngoac.empty(); // Cuối cùng, nếu stack rỗng thì chuỗi hợp lệ
}

int main()
{
    string chuoi;
    cout << "Nhập chuỗi chứa các dấu ngoặc: ";
    getline(cin, chuoi);

    if (kiemTraDauNgoac(chuoi))
    {
        cout << "Các dấu ngoặc trong chuỗi hợp lệ." << endl;
    }
    else
    {
        cout << "Các dấu ngoặc trong chuỗi không hợp lệ." << endl;
    }

    return 0;
}

// tính giá trị biểu thức hậu tố
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int calculate(char op, int num1, int num2)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    default:
        return 0;
    }
}

int evaluatePostfix(string postfix)
{
    stack<int> operands;

    for (char ch : postfix)
    {
        if (isOperator(ch))
        {
            int num2 = operands.top();
            operands.pop();
            int num1 = operands.top();
            operands.pop();

            int result = calculate(ch, num1, num2);
            operands.push(result);
        }
        else
        {
            operands.push(ch - '0');
        }
    }

    return operands.top();
}

int main()
{
    string postfix = "423+*";
    int result = evaluatePostfix(postfix);

    cout << "The result is: " << result << endl;

    return 0;
}
