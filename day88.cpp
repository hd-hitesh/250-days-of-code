#include <bits/stdc++.h>
#define endl "\n";
#define Bahut_Tez_Bete                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

typedef unsigned long long int ll;
ll ps = 0;
ll pl =0;
ll countDigit(ll  n) {
	return floor(log10(n) + 1);
}

int check(ll n)
{
	ll l = countDigit(n);
	if(pl<l)
		{ps=1;pl=l;}

	//single digit
	if (l == 1)
	{
		if (n % 2 == 0)
			return 0;
		else
			return 1;
	}

	if (ps++%2==0)
		return 1;
	else
		return 0;
}

void solve () {

	ll L, R;
	cin >> L >> R;

	ll n = L;
	while (n > 0)
	{
		int digit = n % 10;
		ps += digit;
		n /= 10;
	}

	pl = countDigit(L);

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
