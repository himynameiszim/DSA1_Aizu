//ALDS1_6_A
//Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 2e6 + 5;

int n, a[N], b[N], c[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // count all elements
        c[a[i]]++;
    }
    for (int i = 0; i <= N - 5; i++)
    {
        // the numbers lower than i is c[i]
        c[i] += (i > 0 ? c[i - 1] : 0);
    }
    for (int i = 1; i <= n; i++)
    {
        // sort
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i];
        if (i < n)
            cout << " ";
    }
    cout << '\n';
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