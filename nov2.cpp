#include <bits/stdc++.h>

#define pb push_back
#define FOR(i, n) for (ll i = 1; i <= n; i++)
#define endl "\n";

using namespace std;

typedef unsigned long long int ll;

ll pp[100000];

void SieveOfEratosthenes(ll n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p * p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (ll i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	int q = 0;
	for (ll p = 2; p <= n; p++)
		if (prime[p])
			pp[q++] = p;

}

void solve () {
	ll n; cin >> n;
	ll b[n];
	ll a[n];

	FOR(i, n)
	cin >> b[i];

	FOR(i, n)
	{
		if (i + 1 == b[i])
			cout << (i + 1) << " ";
		else
			cout << pp[a[i - 1]] << " ";
	}

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

// cout<<"G1";
	SieveOfEratosthenes(40000);
	int t; cin >> t;
// cout<<"G11";

	while (t--)
// cout<<"G111";
	{
		solve();
		cout << endl;
	}
// cout<<"G1111";

	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +
