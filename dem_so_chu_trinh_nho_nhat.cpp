#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 3e3 + 10;
vector<int> g[N];
int n;
int par[N];
int F[N][N];
int cnt[N][N];
 
struct Dsu
{
    int siz;
    vector<int> par;
    Dsu() {}
    Dsu(int _siz): siz(_siz) {}
    void init()
    {
        par.resize(siz + 10);
        for (int i = 1; i <= siz; i++)
        {
            par[i] = i;
        }
    }
    int find_par(int u)
    {
        if (u == par[u]) return u;
        return par[u] = find_par(par[u]);
    }
    void join(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        par[u] = v;
    }
};
void dijkstra(int s)
{
 
    for (int i = 1; i <= n; i++) F[s][i] = 1e18;
    F[s][s] = 0;
    cnt[s][s] = 1;
    vector<int> vis(n + 1, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>que;
    que.push({0, s});
    while(que.size())
    {
        auto [w, v] = que.top();
        que.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        for (auto it : g[v])
        {
            if (w + 1 < F[s][it])
            {
                F[s][it] = w + 1;
                cnt[s][it] = cnt[s][v];
                que.push({F[s][it], it});
            }
            else if (w + 1 == F[s][it])
            {
                cnt[s][it] += cnt[s][v];
            }
        }
    }
}
void Solve()
{
    int m;
    cin >> n >> m;
    vector<pair<int,int>> pa;
    Dsu dsu(n + 1);
    dsu.init();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
 
        cin >> u >> v;
        int U = u, V = v;
        u = dsu.find_par(u);
        v = dsu.find_par(v);
        if (u != v)
        {
            g[U].push_back(V);
            g[V].push_back(U);
            dsu.join(u, v);
        }
        else pa.push_back({U, V});
    }
    int ans = 1e18;
    int c = 0;
    for (auto [u, v] : pa)
    {
        dijkstra(u);
        int m = F[u][v];
        if (m + 1 < ans)
        {
            ans = m + 1;
            c = cnt[u][v];
        }
        else if (m + 1 == ans) c += cnt[u][v];
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << c  << '\n';
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t = 1;
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }
}
