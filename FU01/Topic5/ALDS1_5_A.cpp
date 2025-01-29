//ALDS1_5_A
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
    // also exhaustive search, iterate through all possible combinations instead of backtracking
    int n;
    cin >> n;
    int a[22];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        auto check = [&](int x)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                int sum = 0;
                for (int k = 0; k < n; k++)
                {
                    if (j & (1 << k))
                        sum += a[k];
                }
                if (sum == x)
                    return true;
            }
            return false;
        };
        if (check(t))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}