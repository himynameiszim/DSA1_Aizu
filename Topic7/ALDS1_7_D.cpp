//ALDS1_7_D
//Jimmy - s1312004

#include <bits/stdc++.h>

using namespace std;

const int N = 45;
int inOrder[N], preOrder[N];
vector<int> ans;

int find(int a[], int x, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i; // found
    }
    return -1; // not-found
}

void print(int inOrder[], int preOrder[], int n)
{

    int root = find(inOrder, preOrder[0], n);
    if (root != 0)
        print(inOrder, preOrder + 1, root); // left subtree if not null

    if (root != n - 1)
        print(inOrder + root + 1, preOrder + root + 1, n - root - 1); // right subtree if not null

    ans.push_back(preOrder[0]);
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    print(inOrder, preOrder, n);

    for (vector<int>::iterator it = ans.begin(); it != ans.end() - 1; it++)
    {
        cout << *it << " ";
    }
    cout << *ans.rbegin();
    return 0;
}