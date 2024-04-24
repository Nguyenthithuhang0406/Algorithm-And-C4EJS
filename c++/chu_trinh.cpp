// in ra chu trinh trong do thi vo huong
#include <bits/stdc++.h>
using namespace std;

int n, m, st, en;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

bool dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            if (dfs(v))
                return true;
        }
        else if (v != parent[u])
        {
            st = u;
            en = v;
            return true;
        }
    }
    return false;
}

int main()
{
    inp();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i))
            {
                cout << "YES \n";
                vector<int> cycle;
                cycle.push_back(st);
                while (en != st)
                {
                    cycle.push_back(en);
                    en = parent[en];
                }
                reverse(cycle.begin(), cycle.end());
                for (int x : cycle)
                {
                    cout << x << " ";
                }
                return 0;
            }
        }
    }
}

// do thi co huong (to mau)
// kiem tra chu trinh-do thi co huong theo DFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
int color[1001];

void inp()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(color, 0, sizeof(color));
}

bool dfs(int u)
{
    color[u] = 1; // mau xam
    for (int v : adj[u])
    {
        if (color[v] == 0)
        {
            if (dfs(v))
                return true;
        }
        else if (color[v] == 1)
            return true;
    }
    color[u] = 2; // mau den
}

int main()
{
    inp();
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (dfs(i))
            {
                cout << "YES \n";
                return 0;
            }
        }
    }
    cout << "NO \n";
}

// kiem tra chu trinh trong do thi co huong theo kahn
int n, m;
vector<int> adj[1001];
int degree[1001]; // ban bac vao tai dinh i

void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        degree[y]++;
    }
}

bool kahn()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (degree[i] == 0)
            q.push(i);
    }
    int cnt = 0; // cnt dem so dinh da duyet
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cnt++;
        for (int x : adj[v])
        {
            degree[x]--;
            if (!degree[x])
                q.push(x);
        }
    }
    if (cnt == n)
    {
        return false;
    }
    return true;
}

int main()
{
    inp();
    if (kahn())
        cout << "YES \n";
    else
    {
        cout << "NO \n";
    }
    return 0;
}
