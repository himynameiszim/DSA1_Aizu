// Jimmy - s1312004
// ALDS1_12_C

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 4;
const int INFTY = 1 << 20;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k, u, v, c, sum = 0;
    vector<pair<int, int>> adj[MAX];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> k;
        sum += k;

        for (int j = 0; j < k; j++)
        {
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }

    priority_queue<pair<int, int>> PQ;
    int vis[MAX], d[MAX];

    for (int i = 0; i < n; i++)
    {
        d[i] = INFTY;
        vis[i] = false;
    }

    d[0] = 0;
    PQ.push(make_pair(0, 0));
    pair<int, int> f;

    while (!PQ.empty())
    {

        f = PQ.top();
        PQ.pop();
        u = f.second;
        c = (-1) * f.first;

        vis[u] = true;

        for (int j = 0; j < adj[u].size(); j++)
        {

            v = adj[u][j].first;
            if (vis[v])
                continue;
            if (d[v] > d[u] + adj[u][j].second)
            {
                d[v] = d[u] + adj[u][j].second;
                PQ.push(make_pair(d[v] * (-1), v));
                // cout << d[v] << endl;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }

    // cout << "sum = " << sum << endl;

    return 0;
}