// ALDS1_11_C
// Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N][N], d[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
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
        queue<int> q;
        q.push(1);
        fill(d + 2, d + n + 1, 1000);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v = 1; v <= n; v++)
            {
                if (a[u][v] && v != u && d[u] + 1 < d[v])
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << (d[i] == 1000 ? -1 : d[i]) << endl;
    }

    return 0;
}