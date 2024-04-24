// VD1: cho dãy n phần tử. ban đầu các phần tử có giá trị là 0
// có q truy vấn, gồm 2 loại:
// + t = 1, cập nhật giá trị a[i] = v;
// + t = 2, tìm giá trị lớn nhất trong đoạn [i, j]

#include <bits/stdc++.h>
using namespace std;

int n, q;
int ST[400005];

// Truy vấn: A(i) = v
// Hàm cập nhật trên cây ST, cập nhật cây con gốc id quản lý đọan [l, r]
void update(int id, int l, int r, int i, int v)
{
    // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
    if (i < l || r < i)
    {
        return;
    }

    // Đoạn chỉ gồm 1 phần tử, không có nút con
    if (l == r)
    {
        ST[id] = v;
        return;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
}

// Truy vấn: tìm max đoạn [u, v]
// Hàm tìm max các phần tử trên cây ST nằm trong cây con gốc id - quản lý đoạn [l, r]
int get(int id, int l, int r, int u, int v)
{
    // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
    if (v < l || r < u)
    {
        return -INT_MAX;
    }

    // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại thông tin lưu ở nút id
    if (u <= l && r <= v)
    {
        return ST[id];
    }

    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q; // n: so luong phan tu mang, q: so luong truy van
    while (q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
        {
            update(1, 1, n, x, y); // t=1 thì thực hiện loại truy vấn 1: update giá trị
        }
        else
        {
            cout << get(1, 1, n, x, y); // t=2 thì thực hiện loại truy vấn 2: tìm max trong đoạn [x, y]
        }
    }

    return 0;
}



//VD: cho một dãy ngoặc có độ dài  n, có q truy vấn, mỗi truy vấn gômg l, r. yêu cầu tìm chuỗi con từ l đến r dài nhất mà tạo thành dãy ngoặc đúng
#include<bits/stdc++.h>
using namespace std;

//tạo dữ liệu cho 1 nút
struct node{
    int optimal;
    int open;
    int close;

    node(int opt, int o, int c){
        optimal = opt;
        open = o;
        close = c;
    }
};


node ST[400005];


//thao tác kết hợp 2 nút
node operator + (const node& left, const node& right){
    node res;
    //min( số dấu "(" thừa ra ở cây con trái, và số dấu ")" thừa ra ở cây con phải)
    int tmp = min(left.open, right.close);

    //để xây dựng kết quả tối ưu ở nút id, ta nối dãy ngoặc tối ưu ở 2 con, rồi thêm
    //min( số "(" thừa ra ở cây con trái , số ")" thừa ra ở cây con phải)
    res.optimal = left.optimal + right.optimal + tmp * 2;

    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

//khởi tạo cây
void build(int id, int l, int r){
    if( l == r){
        //đoạn [l, r] chỉ có 1 phần tử
        if(s[l] == '(' ) st[id] = Node(0, 1, 0);
        else st[id] = Node(0, 0, 1);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

Node query(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        //trường hợp không giao nhau
        return Node(0, 0, 0);
    }
    if(u <= l && r <= v){
        //trường hợp [l,r] nằm hoàn toàn trong [u, v]
        return st[id];
    }

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m; cin >> n >> m;//n: độ dài dãy ngoặc, m: số truy vấn
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        build(s[i], 0, n-1);
    }
    while(m--){
        int l, r;
        cin >> l, r;
        cout << query(0, 0, n-1, l, r) << "\n";
    }
    return 0;
}