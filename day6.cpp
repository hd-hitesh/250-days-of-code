#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1e9 + 7
#define len(x) x.size()
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define FOR(i, n) for (ll i = 1; i <= n; i++)
#define FORR(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define endl "\n";
#define Bahut_Tez_Bete                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef unordered_map<int, int> mp;
typedef unordered_map<ll, ll> mpl;

void solve () {

	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];

	FOR(i, n)
	{
		FOR(j, m)
		{
			cin >> a[i][j];
		}
	}

	int res = 0;

	FOR(i, n ) {
		FOR(j, m ) {

			int jj1 = j, jj2 = j;
			int ii1 = i, ii2 = i;

			while (1) {
				if (jj1 <= 0 || m < jj2) break;
				if (ii1 <= 0 || n < ii2) break;

				if ((a[i][jj1] == a[i][jj2]) && (a[ii1][j] == a[ii2][j])) {
					++res;
					--ii1; ++ii2;
					--jj1; ++jj2;
					continue;
				}

				if (a[i][jj1] != a[i][jj2] || a[ii1][j] != a[ii2][j])
					break;
			}
		}
	}

	cout << res << '\n';
}

int main()
{
	Bahut_Tez_Bete;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;

	while (t--)
	{
		solve();
		cout << endl;
	}

	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +
