// thuat toan sap xep topo dua tren DFS
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo;

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
    topo.push_back(u);
}

int main()
{
    inp();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());
    for (int x : topo)
    {
        cout << x << " ";
    }
    return 0;
}

// thuat toan kahn (xoa dan dinh)
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n, m;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo;
int in[maxn];

void inp()
{
    cin >> n >> m; // nhap so luong dinh va so luong canh
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    memset(visited, false, sizeof(visited));
}

void kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u])
        {
            in[v]--;
            if (in[v] == 0)
            {
                q.push(v);
            }
        }
    }
    for (int x : topo)
    {
        cout << x << " ";
    }
}
int main()
{
    inp();
    kahn();
    return 0;
}