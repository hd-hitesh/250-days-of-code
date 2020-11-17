#include <bits/stdc++.h>
typedef unsigned long long int ll;
#define FOR(i, n) for (ll i = 0; i < n; i++)
#define endl "\n";
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using namespace std;

/* lis() returns the length of the longest   
  increasing subsequence in arr[] of size n */
int lis( int arr[], int l,int r )  
{  
	int n=r-l+1;
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in  
       bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i+l-1] > arr[j+l-1] && lis[i] < lis[j] + 1)  
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  

int main()
{
	fast;
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int n, q, s;
	cin >> n >> q >> s;

	int h[n];
	FOR(i, n)
	cin >> h[i];

	int last = 0;

	FOR(i, q)
	{
		int x, y;
		cin >> x, y;
		int l, r;

		l = (x + (s * last)) % n + 1;
		r = (y + (s * last)) % n + 1;

		//swap
		if (l > r)
		{
			int t = l; l = r; r = t;
		}

		int ans = lis(h,l,r);
		cout<<ans<<endl;
	}

	return 0;
}