#include <bits/stdc++.h>
using namespace std;

// d?nh nghia 1 di?m và toán t? < d? s?p x?p theo hoành d? tang d?n
struct Point
{
    long long x, y;
    int id;

    bool operator<(const Point &other)
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

struct cmp
{
    bool operator()(const Point &a, const Point &b) const
    {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    }
};

int n;
vector<Point> points; // vector ch?a các di?m nh?p vào
set<Point, cmp> T;

// tính bình phuong kho?ng cách hai di?m (luu v? d?ng bình phuong kho?ng cách d? tránh sai s?)
long long squared_dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main()
{
    cout << "nhap so luong diem \n";
    cin >> n; // nh?p s? lu?ng di?m
    cout << "nhap toa do cac diem \n";
    // v?i m?i di?m nh?p hoành d? x và tung d? y
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y, i});
    }

    long long squared_d = squared_dist(points[0], points[1]); // luu bình phuong kho?ng cách
    int res_id1 = 0, res_id2 = 1;

    sort(points.begin(), points.end()); // s?p x?p theo hoành d? tang d?n

    for (Point p : points)
    {
        long long x = p.x, y = p.y;
        int id = p.id;

        long long d = sqrt(squared_d); // kho?ng cách

        Point current = {-100000, y - d, id};

        // tìm t?t c? các di?m có tung d? trong kho?ng [y-d, y+d]
        while (true)
        {
            auto it = T.upper_bound(current); // tìm v? trí ph?n t? d?u tiên chênh l?ch tung d? l?n hon

            if (it == T.end())
                break;

            current = *it;
            if (current.y > y + d)
                break; // d?ng l?i n?u di?m dó có tung d? l?n hon y+d

            if (current.x < x - d)
            {
                T.erase(it); // xoá các di?m có hoành d? bé hon x-d
                continue;
            }

            // gán dáp án m?i n?u tìm du?c d nh? hon
            if (squared_dist(p, current) < squared_d)
            {
                squared_d = squared_dist(p, current);
                res_id1 = id;
                res_id2 = current.id;
            }

            T.insert(p); // thêm di?m dang xét vào T
        }
    }
	if (res_id1 > res_id2)
            swap(res_id1, res_id2);

        cout << "hai diem co khoang cach nho nhat la: " << endl;
        cout << res_id1 << " " << res_id2 << "\n";
        cout << "khoang cach do la: " << fixed << setprecision(2) << sqrt(squared_d);
    return 0;
}
