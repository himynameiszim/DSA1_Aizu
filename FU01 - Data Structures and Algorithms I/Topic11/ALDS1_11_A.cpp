// ALDS1_11_A
// Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 5;

int n, a[N][N];

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
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
            if (j < n)
                cout << " ";
        }
        cout << '\n';
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