// thuật toán Kosaraju
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001], r_adj[1001];
bool visited[1001];
stack<int> st;

// nhập input
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

// dfs ở bước 1
void dfs1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs1(v);
        }
    }
    // đã duyệt xong đỉnh u
    cout << u << " ";
    st.push(u); // đẩy u vào trong stack
}

// dfs sử dụng ở bước 3
void dfs2(int u)
{
    visited[u] = true;
    cout << u << " ";
    for (int v : r_adj[u])
    {
        if (!visited[v])
        {
            dfs2(v);
        }
    }
}

void SCC()
{
    memset(visited, false, sizeof(visited));
    // bước 1: gọi thuật toán dfs trên đồ thị ban đầu
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    cout << endl;
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while (!st.empty())
    {
        // trong khi stack chưa rỗng thì lấy đỉnh ở đầu stack ra
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            cnt++;
            dfs2(u);
            cout << endl;
        }
    }
    if (cnt == 1)
        cout << "YES \n";
    else
        cout << "NO \n";
}

int main()
{
    inp();
    SCC();
}