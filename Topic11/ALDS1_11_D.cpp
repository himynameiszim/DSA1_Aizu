// ALDS1_11_D
// Jimmy - s1312004

#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, par[N], m;

int Find(int u)
{
    return (par[u] == u ? u : par[u] = Find(par[u]));
}

bool join(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return 0;
    par[v] = u;
    return true;
}

void solve()
{
    cin >> n >> m;
    iota(par + 1, par + n + 1, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (Find(u) == Find(v) ? "yes" : "no") << '\n';
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
