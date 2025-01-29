//ALDS1_2_A
//Jimmy - s1312004

#include <bits/stdc++.h>
// #include<chrono>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j >= i + 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                cnt++;
                swap(a[j], a[j - 1]);
            }
        }
    }

    for (int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << a[n - 1] << endl;

    cout << cnt << endl;

    return 0;
}
