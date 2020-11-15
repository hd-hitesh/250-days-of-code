#include <bits/stdc++.h>
#define endl "\n";
#define Bahut_Tez_Bete                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

typedef long long int ll;
\

int check(ll n)
{

}

void solve () {

	ll n, k, s;
	cin >> n >> k >> s;
	ll res = 0;

	res = min((k + n), (k + k - s + n - s ));
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
