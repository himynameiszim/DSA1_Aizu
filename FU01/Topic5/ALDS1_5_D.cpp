//ALDS1_5_D
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const double Pi = acos(-1);
const int N = 2e5 + 2;
int cnt = 0, n;
int f[N];

int query(int i)
{
    int result = 0;
    while (i >= 1)
    {
        result = result + f[i];
        i = i - (i & -i);
    }
    return result;
}

int query(int l, int r)
{
    return query(r) - query(l - 1);
}

void update(int i, int x)
{
    while (i <= n)
    {
        f[i]++;
        i = i + (i & -i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pair<int, int>> tmp;
    // compress the array
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        tmp.push_back({t, i});
    }
    sort(tmp.begin(), tmp.end());
    vector<int> vt(n);
    for (int i = 0; i < n; i++)
    {
        tmp[i].first = i;
        vt[tmp[i].second] = i;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += query(vt[i] + 1, n);
        update(vt[i] + 1, 1);
    }
    cout << ans << "\n";

    return 0;
}