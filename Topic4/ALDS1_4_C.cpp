//ALDS1_4_C
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<string> st;
    for (int i = 1; i <= n; i++)
    {
        string c, s;
        cin >> c >> s;
        if (c == "insert")
            st.insert(s);
        else if (c == "find")
        {
            if (st.find(s) == st.end())
                cout << "no\n";
            else
                cout << "yes\n";
        }
    }
    return 0;
}