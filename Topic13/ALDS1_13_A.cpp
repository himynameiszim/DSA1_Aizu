// Jimmy - s1312004
// ALDS1_13_A

#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, r[N], c[N], ccr[N], ctr[N], t = 10, a[10][10];

void calc(int i)
{
    if (i == 9)
    {
        for (int x = 1; x <= 8; x++)
        {
            for (int y = 1; y <= 8; y++)
            {
                cout << (a[x][y] ? "Q" : ".");
            }
            cout << '\n';
        }
        exit(0);
    }
    for (int x = 1; x <= 8; x++)
    {
        for (int y = 1; y <= 8; y++)
        {
            if (!r[x] && !c[y] && !ccr[x + y] && !ctr[y - x + t])
            {
                r[x] = c[y] = ccr[x + y] = ctr[y - x + t] = a[x][y] = 1;
                calc(i + 1);
                r[x] = c[y] = ccr[x + y] = ctr[y - x + t] = a[x][y] = 0;
            }
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
        r[x] = c[y] = ccr[x + y] = ctr[y - x + t] = a[x][y] = 1;
    }
    calc(n + 1);
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