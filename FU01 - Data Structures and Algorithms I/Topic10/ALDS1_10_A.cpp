// ALDS1_10_A
// Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[45];
int n;

void solve()
{
    cin >> n;
    a[0] = a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    cout << a[n] << '\n';
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