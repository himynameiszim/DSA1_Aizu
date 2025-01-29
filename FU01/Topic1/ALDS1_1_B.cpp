//ALDS1_1_B
//Jimmy - s1312004

#include <bits/stdc++.h>

// #define int long long
using namespace std;

int gcd(int a, int b)
{
    // if(a == 0 || b == 0)
    // return a+b;
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n";

    return 0;
}
