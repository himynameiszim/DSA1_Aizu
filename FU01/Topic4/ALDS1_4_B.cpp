//ALDS1_4_B
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

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
    sort(s.begin(), s.end());

    int p;
    cin >> p;
    int ans = 0;
    // vector<int> t(p);
    for (int i = 0; i < p; i++)
    {
        int t;
        cin >> t;
        int c = min(1, int(upper_bound(s.begin(), s.end(), t) - lower_bound(s.begin(), s.end(), t)));
        // cout<<t<<" "<<c<<"\n";
        ans += c;
    }
    cout << ans << "\n";
    return 0;
}