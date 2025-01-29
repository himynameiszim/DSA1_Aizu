// ALDS1_9_C
// Jimmy - s1312004

#include <bits/stdc++.h>
#include <set>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    multiset<int> s;
    char cmd[50];

    while (1)
    {
        cin >> cmd;
        if (strcmp(cmd, "insert") == 0)
        {
            int k;
            cin >> k;
            s.insert(k);
        }
        else if (strcmp(cmd, "extract") == 0)
        {
            cout << *s.rbegin() << endl;
            s.erase(s.find(*s.rbegin()));
        }
        else if (strcmp(cmd, "end") == 0)
        {
            return 0;
        }
    }

    return 0;
}