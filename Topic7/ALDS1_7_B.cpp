//ALDS1_7_B
//Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

vector<int> a[N];
int n, sib[N], p[N], dep[N], height[N];

void dfs(int u, int par, int h)
{
    dep[u] = h;
    for (auto v : a[u])
    {
        dfs(v, u, h + 1);
    }
    height[par] = max(height[par], height[u] + 1);
}

void solve()
{
    cin >> n;
    fill(p, p + n, -1);
    fill(sib, sib + n, -1);
    for (int i = 1; i <= n; i++)
    {
        int u, v1, v2;
        cin >> u >> v1 >> v2;
        if (v1 != -1)
        {
            sib[v1] = v2;
            a[u].pb(v1);
            p[v1] = u;
        }
        if (v2 != -1)
        {
            sib[v2] = v1;
            a[u].pb(v2);
            p[v2] = u;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (p[i] == -1 && sz(a[i]))
        {
            root = i;
            break;
        }
    }
    if (n == 1)
    {
        cout << "node 0: parent = -1, sibling = -1, degree = 0, depth = 0, height = 0, root" << '\n';
        return;
    }
    dfs(root, -1, 0);
    for (int i = 0; i < n; i++)
    {
        cout << "node " << i << ": parent = " << p[i] << ", sibling = " << sib[i] << ", degree = " << sz(a[i])
             << ", depth = " << dep[i] << ", height = " << height[i] << ", "
             << (root == i ? "root" : (sz(a[i]) == 0 ? "leaf" : "internal node")) << '\n';
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