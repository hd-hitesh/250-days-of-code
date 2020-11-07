#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1e9 + 7


void solve()
{
	ll n, k;
	cin >> k >> n;
	ll ar[n];
	ll m = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> ar[i];
	}

	ll r = sqrt(n);
	int a[r][r];
	int b[r][r];


	m = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < r; ++j)
		{
			a[i][j] = ar[m++];
		}
	}  

	//matrix

	while (k--) {

		//rotation
		int t = ar[n - 1];
		for (int i = n - 1; i >= 1; i--)
		{
			ar[i] = ar[i - 1];
		}
		ar[0] = t;

		//filling b matrix
		m = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				b[i][j] = ar[m++];
			}
		}

		//product
		int i, j, k;
		int res[r][r];

		for (i = 0; i < r; i++) {
			for (j = 0; j < r; j++) {
				res[i][j] = 0;
				for (k = 0; k < r; k++)
				{
					res[i][j] += a[i][k] * b[k][j];
					// res[i][j] += (ll)(((ll)a[i][k]%MOD) * ((ll)b[k][j]%MOD))%MOD;

				}

			}
		}

		//transferring res to a;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < r; ++j)
			{
				a[i][j] = res[i][j];
			}
		}

	}//end of k

	ll sum = 0;

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < r; ++j)
			sum += a[i][j];

	cout << sum;

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	solve();

	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +