//ALDS1_1_A
//Jimmy - s1312004

#include <bits/stdc++.h>
// #define int long long
using namespace std;
int A[100], n;
void insertion_sort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
		for (int j = 0; j < n; j++)
		{
			if (j == n - 1)
			{
				cout << A[j] << endl;
			}
			else
			{
				cout << A[j] << " ";
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n - 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << A[n - 1] << endl;
	insertion_sort(A, n);
	return 0;
}
