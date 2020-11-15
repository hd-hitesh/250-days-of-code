#include <bits/stdc++.h>
#define endl "\n";
#define Bahut_Tez_Bete                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

typedef long long int ll;

void solve () {

	ll n;
	cin >> n;
	ll x[n], y[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
	}
	
	ll res = 0;

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
