//ALDS1_3_B
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<string, int> mp;
    queue<pair<string, int>> q;
    int n, tl;
    cin >> n >> tl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        int t;
        cin >> s >> t;
        q.push({s, t});
    }
    int time = 0;
    while (q.size())
    {
        // cout<<q.size()<<"\n";
        auto [s, t] = q.front();
        q.pop();
        time += min(t, tl);
        if (t > tl)
        {
            q.push({s, t - tl});
        }
        else
        {
            cout << s << " " << time << "\n";
        }
    }

    return 0;
}