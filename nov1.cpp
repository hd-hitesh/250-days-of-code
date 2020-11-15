// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

// Returns the minimum value of the difference of the two sets.
int findMin(int arr[], int n)
{
	// Calculate sum of all elements
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// Create an array to store results of subproblems
	bool dp[n + 1][sum + 1];

	// Initialize first column as true. 0 sum is possible
	// with all elements.
	for (int i = 0; i <= n; i++)
		dp[i][0] = true;

	// Initialize top row, except dp[0][0], as false. With
	// 0 elements, no other sum except 0 is possible
	for (int i = 1; i <= sum; i++)
		dp[0][i] = false;

	// Fill the partition table in bottom up manner
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			// If i'th element is excluded
			dp[i][j] = dp[i - 1][j];

			// If i'th element is included
			if (arr[i - 1] <= j)
				dp[i][j] |= dp[i - 1][j - arr[i - 1]];
		}
	}

	// Initialize difference of two sums.
	int diff = INT_MAX;

	// Find the largest j such that dp[n][j]
	// is true where j loops from sum/2 t0 0
	for (int j = sum / 2; j >= 0; j--)
	{
		// Find the
		if (dp[n][j] == true)
		{
			diff = j ;
			break;
		}
	}
	return sum-diff ;
}

// Driver program to test above function
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		cout << findMin(arr, n)<<endl;
	}

	return 0;
}


// #include <bits/stdc++.h>

// #define pb push_back
// #define mp make_pair
// #define fr first
// #define sc second
// #define MOD 1e9 + 7
// #define len(x) x.size()
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min3(a, b, c) min(a, min(b, c))
// #define max3(a, b, c) max(a, max(b, c))
// #define FOR(i, n) for (ll i = 0; i < n; i++)
// #define FORR(i,j,n) for(int i=j;i>=n;i--)
// #define all(v) v.begin(), v.end()
// #define alla(a, n) a, a + n
// #define endl "\n";
// #define tez_chal_bsdk                          \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);

// using namespace std;

// typedef long long int ll;
// typedef unsigned long long int ull;
// typedef pair<ll, ll> pll;
// typedef vector<ll> vll;
// typedef vector<int> vi;
// typedef vector<pll> vpll;
// typedef vector<vll> vvll;
// typedef vector<string> vs;
// typedef unordered_map<int, int> mp;
// typedef unordered_map<ll, ll> mpl;
// typedef unordered_map<int, vector<int>> mpv;


// void solve()
// {
// 	int n; cin >> n;
// 	int a[n];
// 	FOR(i, n)
// 	cin >> a[i];

// }

// int main()
// {
// 	tez_chal_bsdk;
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt", "r", stdin);
// 	freopen("output1.txt", "w", stdout);
// #endif

// 	int t; cin >> t;

// 	while (t--)
// 	{
// 		solve();
// 		cout << endl;
// 	}

// 	return 0;
// }

// // ctrl +  alt + F   :  format the code
// // ctrl + shift + B  :  build with
// // ctrl + B          :  build
// // ctrl + X          :  cut the line
// // ctrl +
