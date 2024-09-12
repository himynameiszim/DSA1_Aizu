//ALDS1_5_B
//Jimmy - s1312004

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

const int N = 1e9 + 2;
int cnt = 0;
vector<int> vt;
void merge(vector<int> &vt, int l, int m, int r)
{
    int n1 = m - l; //[L,...,r)
    int n2 = r - m;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = vt[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = vt[m + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            vt[k++] = left[i++];
        else
            vt[k++] = right[j++];
        cnt++;
    }
    while (i < n1)
        vt[k++] = left[i++], cnt++;
    while (j < n2)
        vt[k++] = right[j++], cnt++;
}

void mergesort(vector<int> &vt, int l, int r)
{
    if (l + 1 < r)
    {
        int m = (l + r) / 2;
        mergesort(vt, l, m);
        mergesort(vt, m, r);
        merge(vt, l, m, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vt.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    mergesort(vt, 0, n);
    for (int i = 0; i < n; i++)
        cout << vt[i] << (i < n - 1 ? " " : "\n");
    // cout<<"\n";
    cout << cnt << "\n";

    return 0;
}