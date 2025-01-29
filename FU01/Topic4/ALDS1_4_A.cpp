//ALDS1_4_A
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int p;
    cin >> p;
    int ans = 0;
    // vector<int> t(p);
    for (int i = 0; i < p; i++)
    {
        int t;
        cin >> t;
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == t)
            {
                c++;
                break;
            }
        }
        ans += c;
    }
    cout << ans << "\n";
    return 0;
}