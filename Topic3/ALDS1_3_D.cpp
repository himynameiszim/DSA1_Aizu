//ALDS1_3_D
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
    string s;
    cin >> s;
    s = '@' + s + '@';
    int n = s.size();
    vector<int> v(s.size());
    vector<int> pmax(s.size(), -1e9);
    vector<int> maxp(s.size(), -1e9);
    pmax[0] = 0;
    // maxp[s.size()-1]=0;

    for (int i = 1; i < s.size(); i++)
        v[i] = v[i - 1] + (s[i] == '/') - (s[i] == '\\');
    // for(auto i:v)cout<<i<<" ";
    for (int i = 1; i < s.size(); i++)
        pmax[i] = max(pmax[i - 1], v[i]);
    for (int i = s.size() - 2; i >= 0; i--)
        maxp[i] = max(maxp[i + 1], v[i]);
    long long ans = 0;
    vector<long long> wt;
    long long fans = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int tmp = min(pmax[i], maxp[i]) - v[i];
        fans += tmp;
        if (tmp == 0)
        {
            if (ans)
                wt.push_back(ans);
            ans = 0;
        }
        else
            ans += tmp;
    }
    if (ans)
        wt.push_back(ans);
    cout << fans << "\n";
    cout << wt.size() << (wt.size() ? " " : "");
    for (int i = 0; i < wt.size(); i++)
        cout << wt[i] << (i == wt.size() - 1 ? "" : " ");
    cout << "\n";
    return 0;
}