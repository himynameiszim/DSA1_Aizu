//ALDS1_1_D
//Jimmy - s1312004

#include <bits/stdc++.h>
#include <climits>

// #define int long long
#define N 200000

using namespace std;

int main()
{
    int n, a[N];
    bool change = false;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int min_price = a[0];
    int min_lost = INT_MIN;
    int max_profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            min_lost = max(min_lost, a[i] - min_price);
        }
        if (max_profit < a[i] - min_price)
        {
            change = true;
            max_profit = a[i] - min_price;
        }
        // result = max(result, a[i] - min_price);
        min_price = min(min_price, a[i]);
    }

    cout << (change ? max_profit : min_lost) << endl;

    return 0;
}