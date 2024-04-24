//Dev ơi mình đi đâu thế?

//#Algorithm function in STL
//-min
//-max
//-min_element
//-max_element
//-accumulate
//-swap
//-sort
//-stable_sort
//-find
//-binary_search
//-lower_bound
//-upper_bound
//-memset
//-fill
//-merge
//-reverse
//-set_union
//-set_intersection
//-set_diference
//-set_symmetric_diference

//Dev ơi mình đi đâu thế?

//#Algorithm function in STL
//min, max
int main(){
    cout << min(10, 20) << endl;  //min 2 số
    cout << min({1, 2, 1, 4}) << endl; //min của dãy số


    cout << max(10, 20) << endl;  //max 2 số
    cout << max({1, 2, 1, 4}) << endl; //max của dãy số
}

//min_element, max_element: min ,max  trong mảng hoặc vector
//trả về con trỏ chỉ đến vị trí min, max
int main(){
    int a[5] = {1, 8, 4, 8,2};
    cout << *min_element(a, a+5) << endl;

    vector<int> b = {1, 8, 4, 8,2};
    cout << *min_element(begin(b), end(b));

    cout << *max_element(a, a+5) << endl;

    cout << *max_element(begin(b), end(b));
}

//accuulate: tính tổng các phần tử trong mảng, vector
int main(){
    int a[5] = {1,9,4,8,4};
    int sum = accumulate(a, a+5, 0); 
    //accumulate(a+x, a+y+1, 0): tổng các phần tử trong đoạn [x, y]

    vector<int> b = {1,9,2,6,3};
    cout << accumulate(begin(b), end(b), 0); 
    //accumulate(b.begin() + x, b.begin() + y + 1): tổng các phần tử trong đoạn [x, y]
}

//swap: hoán vị 2 phần tử
int main(){
    int x = 10, y = 50;
    swap(x,y);
    cout << x << " " << y;
}

//sort
int main(){
    int a[5] = {1,6,3,9,4};
    sort(a, a+5); //sắp xếp tăng dần;  
    //sort(a+x, a+y+1):sắp xếp đoạn [x,y]
    sort(a, a+5, greater<int>()); //sắp giảm dần

    vector<int> b = {8, 2,1,0,4};
    sort(begin(b), end(b));//sắp tăng; 
    //sort(b.begin() + x, b.begin() + y + 1): sắp xếp đoạn [x,y]
    sort(begin(b), end(b), greater<int>());//sắp giảm
}

//stable_sort: sắp xếp các phần tử cùng giá trị tiêu chí, 
//đảm bảo thứ tự xuất hiện của các phần tử cùng giá trị tiêu chí trước và sau khi sắp xếp không thay đổi
//vd sắp xếp theo giá trị tuyệt đối tăng dần
bool cmp(int a, int b){
    return abs(a) < abs(b);
}
int main(){
    int a[6]= {-1, 3, 1, -1, -2, -3};
    stable_sort(a, a+6, cmp);  //-1 1 -1 -2 3 -3
}

//find: tìm kiếm phần tử: trả về con trỏ tại vị trí tìm thấy
//nếu không tìm thấy trả và iterator thứ 2 truyền vào
int main(){
    int a[5] = {1, 2, 6, 1, 5};
    auto it = find(a, a+5, 2);
    if(it == a+5) cout << "NOT FOUND";
    else cout << "FOUND";


    vector<int> b = {1, 2, 6, 1, 5}
    auto x = find(b.begin(), b.end(), 5);
    if(x == b.end()) cout << "NOT FOUND";
    else cout << "FOUND";
}


//binary_search: tìm kiếm nhưng chỉ dùng với mảng đã được sắp xếp; trả về TRUE hoặc FALSE
int main(){
    int a[5] = {1,4,6,8,9};
    if(binary_search(a, a+5, 4)) cout << "FOUND";
    else cout << "NOT FOUND";

    vector<int> b = {1,4,6,8,9};
    if(binary_search(begin(b), end(b), 1)) cout << "FOUND";
    else cout << "NOT FOUND";
}

//lower_bound : mảng, vector đâ sắp xếp; trả về con trỏ, iterator đến phần tử đầu tiên >= x
//nếu không tồn tại sẽ trả về iterator thứ 2 truyền vào
int main(){
    int a[5] = {1,4,6,8,9};
    auto it = lower_bound(a, a+5, 4);
    cout << *it;

    vector<int> b = {1,4,6,8,9};
    auto it1 = lower_bound(begin(b), end(b), 4);
    cout << *it1;
}

//upper_bound : mảng, vector đâ sắp xếp; trả về con trỏ, iterator đến phần tử đầu tiên > x
//nếu không tồn tại sẽ trả về iterator thứ 2 truyền vào
int main(){
    int a[5] = {1,4,6,8,9};
    auto it = upper_bound(a, a+5, 4);
    cout << *it;

    vector<int> b = {1,4,6,8,9};
    auto it1 = upper_bound(begin(b), end(b), 4);
    cout << *it1;
}


//memset : gán giá trị ban đầu cho tất cả các phần tử trong mảng
int main(){
    int a[5]  = {1,4,6,8,9};
    memset(a, 0, sizeof(a));
    for(int it : a) cout << it << " ";
}


//fill: gán giá trị ban đầu cho các phần tử trong mảng, vector
int main(){
    vector<int> a(10);
    fill(a.begin(), a.end(), 11);
    for(int it : a) cout << it << " ";
}

//merge: trộn các mảng đã sắp xếp tăng dần
int main(){
    vector<int> a = {1,3, 5, 7, 9};
    vector<int> b = {1,1, 4,5,7, 9};
    vector<int> res(11);
    merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
    for(int it : res) cout << it << " ";
}

//reverse: lật ngược mảng, vector, string
int main(){
    int a[5]  = {1,4,6,8,9};
    reverse(a, a+5);
    for(int it : a) cout << it << " ";

    vector<int> b = {1,1, 4,5,7, 9};
    reverse(b.begin(), b.end());
    for(int it : b) cout << it << " ";
}

//set_union : gộp 2 tập hợp,  chỉ áp dụng với mảng đã sắp xếp
int main(){
    int a[] = {1,1,2,3,5};
    int b[] = {1,4,7,9};
    vector<int> u;
    auto it = set_union(a, a+5, b, b+4, u.begin());
    u.resize(it - u.begin());
    for(int it : u) cout << it << " ";
}

//set_intersection: giao của hai tập hợp, chỉ áp dụng với mảng đã sắp xếp
int main(){
    int a[] = {1,1,2,3,5};
    int b[] = {1,4,7,9};
    vector<int> u;
    auto it = set_intersection(a, a+5, b, b+4, u.begin());
    u.resize(it - u.begin());
    for(int it : u) cout << it << " ";
}

//set_diference: các phần tử có trong tập thứ nhất nhưng không có trong tập thứ 2, chỉ áp dụng với mảng đã sắp xếp
int main(){
    int a[] = {1,1,2,3,5};
    int b[] = {1,4,7,9};
    vector<int> u;
    auto it = set_diference(a, a+5, b, b+4, u.begin());
    u.resize(it - u.begin());
    for(int it : u) cout << it << " ";
}

//-set_symmetric_diference: tập hợp những phần tử có ở tập hợp này nhưng không có ở tập hợp kia, chỉ áp dụng với mảng đã sắp xếp
int main(){
    int a[] = {1,1,2,3,5};
    int b[] = {1,4,7,9};
    vector<int> u;
    auto it = set_symmetric_diference(a, a+5, b, b+4, u.begin());
    u.resize(it - u.begin());
    for(int it : u) cout << it << " ";
}