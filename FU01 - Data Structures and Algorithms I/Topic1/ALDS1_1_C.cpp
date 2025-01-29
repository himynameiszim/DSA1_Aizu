//ALDS1_1_C
//Jimmy - s1312004

#include <bits/stdc++.h>
// #include <chrono>
// #include <cstddef>
// #include <iomanip>
// #include <chrono>
#define pb push_back

using namespace std;

bool check(int a)
{
    if (a == 1 || a == 0)
        return false;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int n, k;
    vector<int> res;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (check(k) == true)
            res.pb(k);
    }

    cout << res.size() << "\n";
    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    return 0;
}
