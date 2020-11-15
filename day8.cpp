#include <bits/stdc++.h>
#define endl "\n";
#define Bahut_Tez_Bete                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

typedef unsigned long long int ll;

ll countDigit(ll  n) {
	return floor(log10(n) + 1);
}

int check(ll n)
{
	ll l = countDigit(n);
	// cout<<"+++++"<<l<<endl;

	//single digit
	if (l == 1)
	{
		if (n % 2 == 0)
			return 0;
		else
			return 1;
	}

	int c = -1;
	if (l % 2 == 0)
		c = 0;
	else
		c = 1;

	while (n > 0)
	{
		int digit = n % 10;
		if (digit % 2 != c)
			return 0;
		c = (c + 1) % 2;
		n /= 10;
	}
	return 1;
}

void solve () {

	ll L, R;
	cin >> L >> R;
	ll res = 0;
	for (ll i = L; i <= R; i++)
	{
		if (check(i))
			res++;
	}
	cout << res << endl;
}

int main()
{
	Bahut_Tez_Bete;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +
