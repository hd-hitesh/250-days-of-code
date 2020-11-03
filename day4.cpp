#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1e9 + 7
#define len(x) x.size()
#define all(x) x.begin(),x.end()
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define FOR(i, n) for (ll i = 0; i < n; i++)
#define FORR(i, n) for (ll i = n - 1; i >= 0; i--)
#define endl "\n";
#define fast                          \
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

void solve()
{
	ull n, q , ans;
	cin >> n >> q;
	ull ar[n];

	//input
	FOR(i, n)
	{
		cin >> ar[i];
	}

	ans = n;
	FOR(i, n - 1)
	{
		if (ar[i] == ar[i + 1])
			ans--;
	}

	//queries
	FOR(i, q)
	{

		ull x, y;
		cin >> x >> y;
		x--;
		// ar[x] = y;

		if (x != 0)
		{
			if (ar[x] != ar[x - 1]) ans--;
			if (y != ar[x - 1]) ans++;
		}
		if (x != n - 1)
		{
			if (ar[x] != ar[x + 1]) ans--;
			if (y != ar[x + 1]) ans++;
		}

		ar[x]=y;
		cout << ans << endl;

	}
}

int main()
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;

	while (t--)
	{
		solve();
		// cout << endl;
	}

	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +

/*
input
1
5 2
1 1 2 5 2
1 3
4 2

output
5
3
*/