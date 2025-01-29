// ALDS1_11_B
// Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;

int n, a[N][N], d[N], f[N], t = 0;

void dfs(int u)
{
    d[u] = ++t;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] && d[v] == 0 && v != u)
            dfs(v);
    }
    f[u] = ++t;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, k;
        cin >> u >> k;
        while (k--)
        {
            int v;
            cin >> v;
            a[u][v] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            dfs(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << d[i] << " " << f[i] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //	freopen("taskname.INP", "r", stdin);
    //	freopen("taskname.OUT", "w", stdout);

    solve();

    return 0;
}
