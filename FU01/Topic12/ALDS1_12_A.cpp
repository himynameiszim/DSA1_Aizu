// ALDS1_12_A
// Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <array>
#include <algorithm>

using namespace std;

int tmp[111][111];

vector<int> t(111, -1);
int parent(int u)
{
    if (t[u] < 0)
        return u;
    return t[u] = parent(t[u]);
}
void combine(int u, int v)
{
    if (t[u] > t[v])
        return combine(v, u); // t[u]<t[v]
    t[u] += t[v];
    t[v] = u;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> vt;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> tmp[i][j];
            if (tmp[i][j] == -1)
                continue;
            vt.push_back({tmp[i][j], i, j});
        }
    }
    long long ans = 0;
    sort(vt.begin(), vt.end());
    for (int i = 0; i < vt.size(); i++)
    {
        if (parent(vt[i][1]) != parent(vt[i][2]))
        {
            combine(parent(vt[i][1]), parent(vt[i][2]));
            ans += vt[i][0];
            // cout<<vt[i][1]<<" "<<vt[i][2]<<" "<<vt[i][0]<<"\n";
        }
        // for(int i=1;i<=5;i++)cout<<parent(i)<<" ";cout<<"\n";
    }
    cout << ans << "\n";

    return 0;
}