// đang bug
#include <bits/stdc++.h>
using namespace std;

struct Diem
{
   int x;
   int y, y2, type;

   bool operator<(const Diem &other) const
   {
      return x < other.x;
   }
};

struct FenwichTree
{
   int n;
   vector<int> s;

   FenwichTree(int n) : n(n), s(n + 5)
   {
      for (int i = 1; i <= n; i++)
         s[i] = 0;
   }

   void update(int i, int value)
   {
      for (; i <= n; i += i & -i)
         s[i] += value;
   }

   int getsum(int i)
   {
      int res = 0;
      for (; i; i -= i & -i)
         res += s[i];
      return res;
   }

   int query(int l, int r)
   {
      return getsum(r) - getsum(l - 1);
   }
};

int n;
int x1[100005], x2[100005], y[100005], y1[100005], y2[100005], x[100005];
vector<int> comppress_y;
vector<Diem> listDiem;

signed main()
{
   cin >> n;
   for (int i = 1; i <= n; i++)
   {
      cin >> x1[i] >> x2[i] >> y[i];

      if (x1[i] > x2[i])
         swap(x1[i], x2[i]);
      comppress_y.push_back(y[i]);
   }

   for (int i = 1; i <= n; i++)
   {
      cin >> y1[i] >> y2[i] >> x[i];

      if (y1[i] > y2[i])
         swap(y1[i], y2[i]);
      comppress_y.push_back(y1[i]);
      comppress_y.push_back(y2[i]);
   }

   sort(comppress_y.begin(), comppress_y.end());
   comppress_y.erase(unique(comppress_y.begin(), comppress_y.end()), comppress_y.end());

   for (int i = 1; i <= n; i++)
   {
      int yy = lower_bound(comppress_y.begin(), comppress_y.end(), y[i]) - comppress_y.begin() + 1;
      listDiem.push_back({x1[i], yy, 0, 1});
      listDiem.push_back({x2[i], yy, 0, 2});
   }

   for (int i = 1; i <= n; i++)
   {
      int l = lower_bound(comppress_y.begin(), comppress_y.end(), y1[i]) - comppress_y.begin() + 1;
      int r = lower_bound(comppress_y.begin(), comppress_y.end(), y2[i]) - comppress_y.begin() + 1;
      listDiem.push_back({x[i], l, r, 3});
   }

   sort(listDiem.begin(), listDiem.end());

   FenwichTree FT(n * 3);

   long long res = 0;
   for (auto d : listDiem)
   {
      if (d.type == 1)
         FT.update(d.y, 1);
      else if (d.type == 2)
         FT.update(d.y, -1);
      else
         res += FT.query(d.y, d.y2);
   }

   cout << res;
   return 0;
}