//ALDS1_2_B
//Jimmy - s1312004

#include <bits/stdc++.h>
// #include<chrono>
// #define int long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a[n], mini, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mini])
            {
                mini = j;
            }
        }
        swap(a[i], a[mini]);
        if (mini != i)
            cnt++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ' ';
    }

    cout << a[n - 1] << endl;
    cout << cnt << endl;

    return 0;
}
