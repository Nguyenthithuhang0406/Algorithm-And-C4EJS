//Dev ơi mình đi đâu thế?
//Kiểm tra dãy ngoặc đúng bằng stack. Nếu đúng in vị trí các cặp ngoặc tương ứng
#include<bits/stdc++.h>
using namespace std;

stack<int> st;  //stack chỉ lưu trữ ngoặc mở
vector<pair<int, int>> matches;  ///lưu các cặp dấu ngoặc tương ứng

bool solve(string s){
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);  //nếu là ngoặc mở thì đẩy vào stack
        }else{
            //nếu là ngoặc đóng và stack rỗng -> không có ngoặc mở tương ứng -> dãy ngoặc sai
            if(st.empty()) return false;  

            //nếu stack không rỗng -> có ngoặc mở tương ứng -> đẩy cặp ngaocwj đúng vào vector -> xoá ngoặc mở khỏi stack
            matches.push_back({st.top(), i}); 
            st.pop();
        }
    }

    //kiểm tra đến cuối xâu, nếu stack không rỗng -> thừa ngoặc mở -> dãy ngoặc không đúng
    if(!st.empty()) return false;

    //ngược lại là dãy ngoặc đúng
    return true;
}
int main(){
    cout << "moi ban nhap day ngoac: \n";
    string s;
    cin >> s;
    if(solve(s)){ 
        cout << "Day ngoac dung! \n"; 
        cout << "vi tri cac cap ngoac tuong ung la: \n";
        for(auto x : matches){
            cout << x.first + 1 << " " << x.second + 1<< "\n";
        }
    }else cout << "Day ngoac khong dung!";
    return 0;
}