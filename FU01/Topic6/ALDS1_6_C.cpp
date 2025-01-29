//ALDS1_6_C
//Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n;

struct shit
{
    // char, value, index;
    char c;
    int v, p;
} a[N];

int wtf(int p, int r)
{
    int v = a[r].v, i = p - 1;
    // find pivot
    for (int j = p; j <= r - 1; j++)
    {
        if (a[j].v <= v)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void slowsort(int p, int r)
{
    if (p < r)
    {
        // sort left side and right side
        int q = wtf(p, r);
        slowsort(p, q - 1);
        slowsort(q + 1, r);
    }
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c >> a[i].v;
        a[i].p = i;
    }
    slowsort(1, n);
    bool ok = 1;
    for (int i = 1; i <= n; i++)
        if (a[i].v == a[i - 1].v && a[i].p < a[i - 1].p)
        {
            ok = 0;
            break;
        }
    cout << (ok ? "Stable" : "Not stable") << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].c << " " << a[i].v << '\n';
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
