#include <bits/stdc++.h>
#include <math.h>
// ALDS1_9_A
// Jimmy - s1312004
using namespace std;

const int N = 2e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    int a[N];
    cin >> n;

    // memset(a, 1982, sizeof(a));
    for (int i = 0; i <= 100 * n; i++)
    {
        a[i] = -2;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << "node 1" << ": key = " << a[1] << ", left key = " << a[2] << ", right key = " << a[3] << ", " << endl;
    for (int i = 2; i <= n; i++)
    {
        int leftIndex = 2 * i;
        int rightIndex = (2 * i) + 1;

        if (a[leftIndex] != -2 && a[rightIndex] != -2)
        { // ton tai ca l+r
            cout << "node " << i << ": key = " << a[i] << ", parent key = " << a[(int)floor((float)((i) / 2))] << ", left key = " << a[2 * (i)] << ", right key = " << a[2 * (i) + 1] << ", " << endl;
        }
        else if (a[rightIndex] == -2 && a[leftIndex] != -2)
        { // ton tai moi l
            cout << "node " << i << ": key = " << a[i] << ", parent key = " << a[(int)floor((float)((i) / 2))] << ", left key = " << a[2 * (i)] << ", " << endl;
        }
        else if (a[leftIndex] == -2 && a[rightIndex] == -2)
        { // khong ton tai l+r
            cout << "node " << i << ": key = " << a[i] << ", parent key = " << a[(int)floor((float)((i) / 2))] << ", " << endl;
        }
    }

    return 0;
}