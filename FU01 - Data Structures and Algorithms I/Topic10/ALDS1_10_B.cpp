// ALDS1_10_B
// Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int inf = (int)2e9 + 1;
const int N = 100 + 5;

int n, dp[N][N];
pii a[N];

int calc(int l, int r)
{
    // cout << l << " " << r << " " << dp[l][r] << '\n';
    if (l == r)
        return dp[l][r] = 0;
    if (dp[l][r] != inf)
    {
        return dp[l][r];
    }
    for (int m = l; m < r; m++)
    {
        dp[l][r] = min(dp[l][r], calc(l, m) + a[l].fi * a[m].se * a[r].se + calc(m + 1, r));
        // cout << l << " " << r << " " << dp[l][r] << '\n';
    }
    return dp[l][r];
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = dp[j][i] = inf;
    }
    calc(1, n);
    cout << dp[1][n] << '\n';
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