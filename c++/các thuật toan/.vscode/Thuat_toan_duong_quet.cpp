// //Dev ơi mình đi đâu thế?
// //Bài toán tìm cặp điểm gần nhất
// #include <bits/stdc++.h>
// using namespace std;

// // định nghĩa 1 điểm và toán tử < để sắp xếp theo hoành độ tăng dần
// struct Point
// {
//     long long x, y;
//     int id;

//     bool operator<(const Point &other)
//     {
//         if (x != other.x)
//             return x < other.x;
//         return y < other.y;
//     }
// };

// struct cmp
// {
//     bool operator()(const Point &a, const Point &b) const
//     {
//         if (a.y != b.y)
//             return a.y < b.y;
//         return a.x < b.x;
//     }
// };

// int n;
// vector<Point> points; // vector chứa các điểm nhập vào
// set<Point, cmp> T;

// // tính bình phương khoảng cách hai điểm (lưu về dạng bình phương khoảng cách để tránh sai số)
// long long squared_dist(Point a, Point b)
// {
//     return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
// }


// int main()
// {
//     cout << "nhap so luong diem \n";
//     cin >> n; // nhập số lượng điểm
//     cout << "nhap toa do cac diem \n";
//     // với mỗi điểm nhập hoành độ x và tung độ y
//     for (int i = 0; i < n; i++)
//     {
//         long long x, y;
//         cin >> x >> y;
//         points.push_back({x, y, i});
//     }

//     long long squared_d = squared_dist(points[0], points[1]); // lưu bình phương khoảng cách
//     int res_id1 = 0, res_id2 = 1;

//     sort(points.begin(), points.end()); // sắp xếp theo hoành độ tăng dần

//     for (Point p : points)
//     {
//         long long x = p.x, y = p.y;
//         int id = p.id;

//         long long d = sqrt(squared_d); // khoảng cách

//         Point current = {-100000, y - d, id};

//         // tìm tất cả các điểm có tung độ trong khoảng [y-d, y+d]
//         while (true)
//         {
//             auto it = T.upper_bound(current); // tìm vị trí phần tử đầu tiên chênh lệch tung độ lớn hơn

//             if (it == T.end())
//                 break;

//             current = *it;
//             if (current.y > y + d)
//                 break; // dừng lại nếu điểm đó có tung độ lớn hơn y+d

//             if (current.x < x - d)
//             {
//                 T.erase(it); // xoá các điểm có hoành độ bé hơn x-d
//                 continue;
//             }

//             // gán đáp án mới nếu tìm được d nhỏ hơn
//             if (squared_dist(p, current) < squared_d)
//             {
//                 squared_d = squared_dist(p, current);
//                 res_id1 = id;
//                 res_id2 = current.id;
//             }

//             T.insert(p); // thêm điểm đang xét vào T
//         }
//     }
//     if (res_id1 > res_id2)
//         swap(res_id1, res_id2);

//     cout << "hai diem co khoang cach nho nhat la: " << endl;
//     cout << res_id1 << " " << res_id2 << "\n";
//     cout << "khoang cach do la: " << fixed << setprecision(2) << sqrt(squared_d);
//     return 0;
// }