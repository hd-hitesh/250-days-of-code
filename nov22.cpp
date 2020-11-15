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
#define FOR(i, n) for (ll i = 0; i < n; i++)
#define FORR(i,j,n) for(int i=j;i>=n;i--)
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define endl "\n";
#define tez_chal_bsdk                          \
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
typedef unordered_map<int, vector<int>> mpv;


void solve()
{
	int n; cin >> n;

	int a[n];
	mpv Mehndak_Hu_ME;

	FOR(i, n)
	{
		cin >> a[i];
		Mehndak_Hu_ME[a[i]].pb(i);
	}

	int b[n], h = 1;

	FORR(i, n - 1, 0)
	{
		if (Mehndak_Hu_ME.find(a[i]) == Mehndak_Hu_ME.end())
			continue;

		FOR(k, Mehndak_Hu_ME[a[i]].size())
		{
			b[Mehndak_Hu_ME[a[i]][k]] = h;
		}
		h++;
		Mehndak_Hu_ME.erase(a[i]);
	}

	FOR(i, n)
	cout << b[i] << " ";
}

int main()
{
	tez_chal_bsdk;
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
