// ALDS1_10_C
// Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e3 + 5;

int n, dp[N][N];

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    memset(dp, 0, sizeof(dp));
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int ans = 0;
    for (int i = 1; i < sz(s1); i++)
    {
        for (int j = 1; j < sz(s2); j++)
        {
            dp[i][j] = max({dp[i - 1][j - 1] + (s1[i] == s2[j]), dp[i - 1][j], dp[i][j - 1]});
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //	freopen("taskname.INP", "r", stdin);
    //	freopen("taskname.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}