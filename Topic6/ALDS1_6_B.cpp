//ALDS1_6_B
//Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, a[N];

int wtf(int p, int r)
{
    int v = a[r], i = p - 1;
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j] <= v)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int p = wtf(1, n);
    for (int i = 1; i <= n; i++)
    {
        if (i == p)
            cout << "[";
        cout << a[i];
        if (i == p)
            cout << "]";
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