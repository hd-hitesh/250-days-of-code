#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n, m , x, sum = 0;
	cin >> m >> n ;
	int ar[max(m, n)][max(m, n)];
	unordered_map<int, int> mp;

	fill_n(*ar, sizeof ar / sizeof **ar, 1);

	//input
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			{
				cin >> ar[i][j];
			}

	m = max(m, n);

	//freq
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			if ( i != j  )
				mp[ar[i][j]]++;

	cin >> x;

	//sum
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if ( i == j )
			{
				if ( (mp.find(ar[i][j]) != mp.end()) && mp[ar[i][j]] == x)
				{
					sum += ar[i][j];
				}
			}
		}
	}

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