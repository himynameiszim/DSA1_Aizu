// ALDS1_9_B
// Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

const int N = 500001;

void maxHeapify(int *a, int i, int n)
{
    int childIndex = i << 1; // initialize as leftChild
    int tmp = a[i];          // initialize as root, store the value of current Node

    while (childIndex <= n)
    {
        if (childIndex < n && a[j + 1] > a[j]) 
            childIndex += 1;                   
        if (tmp > a[j])                        
            break;
        else if (tmp <= a[j])
        {                                      
            a[childIndex / 2] = a[childIndex]; 
            childIndex *= 2;                   
        }
    }
    a[childIndex / 2] = tmp;
    return;
}

void buildMaxHeap(int *a, int n)
{
    int i;
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(a, i, n);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, a[N];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    buildMaxHeap(a, n);

    for (int i = 1; i <= n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl;

    return 0;
}