#include <bits/stdc++.h>
using namespace std;

// d?nh nghia 1 di?m v� to�n t? < d? s?p x?p theo ho�nh d? tang d?n
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
vector<Point> points; // vector ch?a c�c di?m nh?p v�o
set<Point, cmp> T;

// t�nh b�nh phuong kho?ng c�ch hai di?m (luu v? d?ng b�nh phuong kho?ng c�ch d? tr�nh sai s?)
long long squared_dist(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main()
{
    cout << "nhap so luong diem \n";
    cin >> n; // nh?p s? lu?ng di?m
    cout << "nhap toa do cac diem \n";
    // v?i m?i di?m nh?p ho�nh d? x v� tung d? y
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        points.push_back({x, y, i});
    }

    long long squared_d = squared_dist(points[0], points[1]); // luu b�nh phuong kho?ng c�ch
    int res_id1 = 0, res_id2 = 1;

    sort(points.begin(), points.end()); // s?p x?p theo ho�nh d? tang d?n

    for (Point p : points)
    {
        long long x = p.x, y = p.y;
        int id = p.id;

        long long d = sqrt(squared_d); // kho?ng c�ch

        Point current = {-100000, y - d, id};

        // t�m t?t c? c�c di?m c� tung d? trong kho?ng [y-d, y+d]
        while (true)
        {
            auto it = T.upper_bound(current); // t�m v? tr� ph?n t? d?u ti�n ch�nh l?ch tung d? l?n hon

            if (it == T.end())
                break;

            current = *it;
            if (current.y > y + d)
                break; // d?ng l?i n?u di?m d� c� tung d? l?n hon y+d

            if (current.x < x - d)
            {
                T.erase(it); // xo� c�c di?m c� ho�nh d? b� hon x-d
                continue;
            }

            // g�n d�p �n m?i n?u t�m du?c d nh? hon
            if (squared_dist(p, current) < squared_d)
            {
                squared_d = squared_dist(p, current);
                res_id1 = id;
                res_id2 = current.id;
            }

            T.insert(p); // th�m di?m dang x�t v�o T
        }
    }
	if (res_id1 > res_id2)
            swap(res_id1, res_id2);

        cout << "hai diem co khoang cach nho nhat la: " << endl;
        cout << res_id1 << " " << res_id2 << "\n";
        cout << "khoang cach do la: " << fixed << setprecision(2) << sqrt(squared_d);
    return 0;
}
