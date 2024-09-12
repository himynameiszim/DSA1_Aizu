//ALDS1_2_D
//Jimmy - s1312004

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
// #define int long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);

	long n, g, v, t, cnt = 0, m;
	cin >> n;
	vector<long> vt(n);

	for (long i = 0; i < n; i++)
	{
		cin >> vt[i];
	}

	if (n < 3)
		m = 1;
	else
		m = (long)(log(n) / log(3));
	vector<long> G(m);

	cnt = 0;
	for (long k = 0; k < m; k++)
	{
		G[k] = ((long)pow(3, m - k) - 1) / 2;
		g = G[k];
		for (long i = g; i < n; i++)
		{
			long j = 0;
			v = vt[i];
			j = i - g;
			while (j >= 0 && vt[j] > v)
			{
				vt[j + g] = vt[j];
				j = j - g;
				cnt++;
			}
			vt[j + g] = v;
		}
	}

	cout << m << endl;
	for (long i = 0; i < m - 1; i++)
		cout << G[i] << " ";
	cout << G[m - 1] << endl;
	cout << cnt << endl;
	for (long i = 0; i < n; i++)
		cout << vt[i] << endl;

	return 0;
}
