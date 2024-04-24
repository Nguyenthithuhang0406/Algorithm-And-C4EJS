// Dev ơi mình đi đâu thế?
// Tìm chuỗi con dài nhất trong đoạn [l,r] tạo thành dãy ngoặc đúng (chuỗi con không cần liên tiếp)
// sử dụng Segment Tree

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int optimal; // lưu kết quả tối ưu trong đoạn [l,r]
    int open;    // số ngoặc '(' sau khi xoá đoạn optimal
    int close;   // số ngoặc ')' sau khi xoá đoạn optimal
};

// khai báo cây
Node st[800000];
char s[200000]; // lưu dãy ngoặc

// Thao tác kết hợp 2 nút
Node operator+(const Node &left, const Node &right)
{
    Node res; // trả về kq

    // đặt biến tmp lưu giá trị min (số dấu '(' ở cây con trái, số dấu ngoặc ')' thừa ở cây con phải) -> tạo thành tmp cặp ngoặc đúng
    int tmp = min(left.open, right.close);

    // kết quả là tổng dãy ngoặc tối ưu ở 2 con +  số ngoặc đúng thừa ra ở hai con
    res.optimal = left.optimal + right.optimal + tmp * 2;

    // cập nhật số ngoặc '(' và số ngoặc ')' thừa
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;

    return res;
}

// khởi tạo cây
void build(int id, int l, int r)
{
    // đoạn [l, r] chỉ có một phần tử
    if (l == r)
    {
        if (s[l] == '(')
            st[id] = {0, 1, 0};
        else
            st[id] = {0, 0, 1};
        return;
    }

    // trường hợp nhiều hơn 1 phần tử
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

// truy vấn
Node query(int id, int l, int r, int u, int v)
{
    // trường hợp không giao nhau
    if (v < l || r < u)
        return {0, 0, 0};

    // trường hợp [l,r] nằm trong [u,v]
    if (u <= l && r <= v)
        return st[id];

    // trường hợp còn lại
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
}

signed main()
{
    cout << "moi ban  nhap do dai day ngoac: \n";
    int n;
    cin >> n;
    cout << "moi ban nhap day ngoac: \n";
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        build(i, 1, n);
    }
    cout << "Nhap so luong truy van: \n";
    int t;
    cin >> t;
    cout << "Cac truy van lan luot la: \n";
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 1, n, l, r);
        cout << res.optimal << "\n";
    }
    return 0;
}