//ALDS1_7_C
//Jimmy - s1312004

#include <bits/stdc++.h>

#define sz(a) ((int)(a.size()))
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n;
bool cc[N];

struct code1timeac
{
    int u, l, r;
} a[N];

void preorder(int u)
{
    cout << " " << u;
    if (a[u].l != -1)
        preorder(a[u].l);
    if (a[u].r != -1)
        preorder(a[u].r);
}

void inorder(int u)
{
    if (a[u].l != -1)
        inorder(a[u].l);
    cout << " " << u;
    if (a[u].r != -1)
        inorder(a[u].r);
}

void postorder(int u)
{
    if (a[u].l != -1)
        postorder(a[u].l);
    if (a[u].r != -1)
        postorder(a[u].r);
    cout << " " << u;
}

void solve()
{
    cin >> n;
    int root = -1;
    for (int i = 1; i <= n; i++)
    {
        int u, v1, v2;
        cin >> u >> v1 >> v2;
        a[u].l = v1;
        a[u].r = v2;
        if (v1 != -1)
            cc[v1] = 1;
        if (v2 != -1)
            cc[v2] = 1;
    }
    for (int i = 0; i < n; i++)
        if (cc[i] == 0)
            root = i;
    cout << "Preorder" << '\n';
    preorder(root);
    cout << '\n';
    cout << "Inorder" << '\n';
    inorder(root);
    cout << '\n';
    cout << "Postorder" << '\n';
    postorder(root);
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