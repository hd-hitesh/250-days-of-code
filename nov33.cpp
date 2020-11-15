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
#define FOR(i, n) for (ll i = 1; i < n; i++)
#define FORR(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
#define endl "\n";
#define Tez_Chal_bsdk                          \
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

int main()
{
	Tez_Chal_bsdk;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;

	while (t--)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s;

		int magnet = 0, iron = 0, count = 0;
		int a[n];

		if (s[0] == ':')
			a[0] = 1;
		else
			a[0] = 0;

		FOR(i, n)
		{
			if (s[i] == ':')
				a[i] = a[i - 1] + 1;
			else
				a[i] = a[i - 1];
		}

		while (magnet < n && iron < n)
		{
			if (s[magnet] == 'X')
			{
				magnet++;
				iron = magnet;
			}
			else if (s[magnet] != 'M')
				magnet++;
			else
			{
				while (magnet > iron && (k + 1 - abs(magnet - iron) - abs(a[magnet] - a[iron])) <= 0)
					iron++;
				while (iron < n && (k + 1 - abs(magnet - iron) - abs(a[magnet] - a[iron])) > 0)
				{
					if (s[iron] == 'X')
					{
						magnet = iron;
						iron++;
						break;
					}
					if (s[iron] != 'I')
						iron++;
					else
					{
						count++;
						iron++;
						break;
					}
				}
				magnet++;
			}
		}
		cout << count;
		cout << endl;
	}

	return 0;
}

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +