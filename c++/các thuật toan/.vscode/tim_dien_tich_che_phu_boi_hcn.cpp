// #include <bits/stdc++.h>
// using namespace std;

// struct Segment
// {
//     int x, y1, y2, type;

//     bool operator<(const Segment &other) const
//     {
//         return x < other.x;
//     }
// };

// struct SegmentTree
// {
//     vector<pair<int, int>> s;

//     SegmentTree(int n) : s(n * 4 + 5)
//     {
//         for (int i = 0; i < 4 * n; i++)
//         {
//             s[i] = {0, 0};
//         }
//     }

//     void update(int id, int l, int r, int tl, int tr, int val)
//     {
//         if (l > tr || r < tl)
//             return;

//         if (l >= tl && r <= tr)
//         {
//             s[id].second += val;
//             if (s[id].second != 0)
//                 s[id].first = r - l + 1;
//             else if (l != r)
//                 s[id].first = s[id * 2].first + s[id * 2 + 1].first;
//             else
//                 s[id].first = 0;
//             return;
//         }

//         int m = (l + r) >> 1;
//         update(id * 2, l, m, tl, tr, val);
//         update(id * 2 + 1, m + 1, r, tl, tr, val);

//         if (s[id].second != 0)
//             s[id].first = r - l + 1;
//         else
//             s[id].first = s[id * 2].first + s[id * 2 + 1].first;
//     }
// };

// int n;
// vector<Segment> segments;

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);

//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;

//         segments.push_back({x1, y1, y2, 1});
//         segments.push_back({x2, y1, y2, -1});
//     }

//     sort(segments.begin(), segments.end());

//     SegmentTree ST(30000);
//     int res = 0;
//     for (int i = 0; i < (int)segments.size() - 1; i++)
//     {
//         ST.update(1, 0, 3000, segments[i].y1, segments[i].y2 - 1, segments[i].type);
//         res += (segments[i + 1].x - segments[i].x) * ST.s[1].first;
//     }

//     cout << res;
// }

// tách

#include <bits/stdc++.h>
using namespace std;

struct Segment
{
    int x, y1, y2, type;
    // x: toạ độ x của đoạn thẳng
    // y1,y2: toạ độ y của hình chữ nhật
    // type: loại của đoạn; 
    //type = 1: đoạn đó là đoạn mở của hcn, type = -1: đoạn đó là đoạn đóng của hcn;

    bool operator<(const Segment &other) const
    {
        return x < other.x;
    }
};

vector<pair<int, int>> s;

void update(int id, int l, int r, int tl, int tr, int val)
{
    if (l > tr || r < tl)
        return;

    // nếu đoạn thẳng hiện tại nằm hoàn toàn trong đoạn [tl,tr]
    if (l >= tl && r <= tr)
    {
        s[id].second += val; // cập nhật trạng thái
        // nếu s[id].second != 0 thì có ít nhất 1 đoạn thẳng đang chồng lên đoạn thẳng này
        if (s[id].second != 0)
            s[id].first = r - l + 1; // cập nhật diện tích bằng chiều dài đoạn hiện tại
        else if (l != r)
            // s[id].second = 0 và l != r chứng tỏ không còn đoạn nào chồng lên nhau nhưng chưa đến đoạn thẳng cuối cùng
            s[id].first = s[id * 2].first + s[id * 2 + 1].first;
        else
            // đến đoạn cuối
            s[id].first = 0;
        return;
    }

    int m = (l + r) / 2;
    update(id * 2, l, m, tl, tr, val);
    update(id * 2 + 1, m + 1, r, tl, tr, val);

    if (s[id].second != 0)
        s[id].first = r - l + 1;
    else
        s[id].first = s[id * 2].first + s[id * 2 + 1].first;
}

const int MAX = 30000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Segment> segments;

    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        segments.push_back({x1, y1, y2, 1});
        segments.push_back({x2, y1, y2, -1});
    }

    sort(segments.begin(), segments.end()); // sắp xếp theo x tăng dần

    s.resize(MAX * 4 + 5);
    int res = 0;
    for (int i = 0; i < (int)segments.size() - 1; i++)
    {
        update(1, 0, MAX, segments[i].y1, segments[i].y2 - 1, segments[i].type);
        res += (segments[i + 1].x - segments[i].x) * s[1].first;
    }

    cout << res;
}
