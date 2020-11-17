#include <bits/stdc++.h>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1e9 + 7
// #define len(x) x.size()
// #define min(a, b) ((a) < (b) ? (a) : (b))
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min3(a, b, c) min(a, min(b, c))
// #define max3(a, b, c) max(a, max(b, c))
// #define FOR(i, n) for (ll i = 0; i < n; i++)
#define FOR(i,j,n) for(int i=j;i<n;i++)
#define FORR(i, n) for (ll i = n - 1; i >= 0; i--)
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

# define    debug1(x)           cout<<#x<<" "<<x<<endl;
# define    debug2(x,y)         cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
# define    debug3(x,y,z)       cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
# define    debug4(x,y,z,w)     cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<endl;
# define    debug5(x,y,z,w,v)   cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#v <<" "<<v<<endl;
# define    debug6(x,y,z,w,a,b) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<" "<<#w <<" "<<w<<" "<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//         tree_order_statistics_node_update> indexed_set;

template<class T> T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template<class T> T min(T a, T b, T c) {
  return min(a, min(b, c));
}

void fastio()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
}

bool prime[10000005];
void SieveOfEratosthenes(ll n)//O(nloglogn)
{
  memset(prime, true, sizeof(prime));

  for (ll p = 2; p * p <= n; p++)
  {
    if (prime[p] == true)
    {
      for (ll i = p * p; i <= n; i += p)
        prime[i] = false;
    }
  }
}
bool isPrime(ll n)//O(sqrt(n))
{
  if (n < 2)
    return false;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}
std::vector<ll> generatePrimeFactors(ll n)
{
  std::vector<ll> prime;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      prime.pb(i);
      while (n % i == 0)
        n = n / i;
    }
  }
  if (n != 1)
    prime.pb(n);
  return prime;
}
std::vector<ll> generateFactors(ll n)
{
  std::vector<ll> fact;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      fact.pb(i);
      if (n / i != i)
        fact.pb(n / i);
      //24 - 1,2,3,4,6,8,12
    }
  }
  fact.pb(1);
  if (n != 1)
    fact.pb(n);
  sort(fact.begin(), fact.end());
  return fact;
}

bool dfs(vector<vector<int>> v, int find, vector<int> &visited, int ele, vector<int> &ret)
{
    if (ele == find)
    {
        return 1;
    }
    visited[ele] = 1;
    FOR(i, 0, v[ele].size())
    {
        if (v[ele][i] && visited[v[ele][i]] == 0)
        {
            ret.pb(v[ele][i]);
            if (dfs(v, find, visited, v[ele][i], ret))
                return 1;
            ret.ppb();
        }
    }
    return 0;
}

ll extendedGCD(ll a, ll b, ll &x, ll &y)
{
  //produces correct results for negative integers as well
  if (a == 0)
  {
    x = 0;
    y = 1;
    return b;
  }
  ll x1, y1, d;
  d = extendedGCD(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
ll gcd(ll a, ll b) //O(log min(a,b))
{
  /*
  recursive implementation below
  if(!b) return a;
  return gcd(b,a%b);
  */

  //non-recursive implementation below
  while (b)
  {
    a %= b;
    swap(a, b);
  }
  return a;
}

ll multiply(ll a, ll b, ll m);
ll singlemod(ll a, ll m);
ll modpow(ll x, ll n, ll m) //O(logn)// used for calculating (x^n)%m
{
  if (n == 0)
    return 1;
  ll res = 1;
  while (n)
  {
    if (n % 2)
      res = multiply(res, x, m);
    x = multiply(x, x, m);
    n = n >> 1;
  }
  return singlemod(res, m);
}
ll fastpow(ll x, ll n)
{
  if (n == 0)
    return 1;
  ll res = 1;
  while (n)
  {
    if (n % 2)
      res = res * x;
    x = x * x;
    n = n >> 1;
  }
  return res;
}
ll modinverse(ll x, ll m) //O(logn)
{
  return modpow(x, m - 2, m);
}
ll add(ll a, ll b, ll m)
{
  return (((a % m) + (b % m)) % m);
}
ll substract(ll a, ll b, ll m)
{
//    if (a < b)
//        swap(a, b);
  return (((a % m) - (b % m) + m) % m);
}
ll multiply(ll a, ll b, ll m)
{
  return (((a % m) * (b % m)) % m);
}
ll divide(ll a, ll b, ll m)
{
  ll temp = modinverse(b, m);
  return multiply(a, temp, m);
}
ll singlemod(ll a, ll m)
{
  return (a % m);
}
ll eulerstotientfunction(ll n)//O(sqrt(n))
{
  ll ans = n;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
        n = n / i;
      ans -= ans / i;
    }
  }
  if (n > 1)
    ans -= ans / n;
  return ans;
}

ll ncr(ll n, ll k, ll m)
{
  if (k > n) return 0;
  if (m == 0)
  {
    ll res = 1;
    k = min(k, n - k);
    for (ll i = 1; i <= k; i++)
    {
      res *= (n - i + 1);
      res /= i;
    }
    return res;
  }
  else
  {
    ll res = 1;
    k = min(k, n - k);
    for (ll i = 1; i <= k; i++)
    {
      res = multiply(res, n - i + 1, m);
      res = divide(res, i, m);
    }
    return singlemod(res, m);
  }
}
ll kadaneAlgo(const std::vector<ll> &arr)
{
  ll size = arr.size();
  ll currmax = arr[0], maxsofar = arr[0];
  for (ll i = 1; i < size; i++)
  {
    //debug2(currmax,maxsofar);
    currmax = max(arr[i], currmax + arr[i]);
    maxsofar = max(maxsofar, currmax);
  }
  return maxsofar;
}
ll getDigitSum(ll n)
{
  ll co = 0;
  while (n > 0)
  {
    co += n % 10;
    n = n / 10;
  }
  return co;
}

template<class T>
void printArray(T arr[], ll n)
{
  for (ll i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
//const int p1 = 13331,m1 = 1e9+9,p2 = 7919, m2 = 1e9+9;
//const int p1 = 97266353,m1 = 972663749,p2 = 97336357, m2 = 1000000007;
//const int p1 = 31 ,m1 = 1e9+7;

//grid cells
//D U R L
//ll dx[] = {1, -1, 0, 0};
//ll dy[] = {0, 0, 1, -1};

//---------------TEMPLATE ABOVE--------------//

/*****   THIS CODE IS WRITTEN BY HITESH, DONT TRY TO COPY. ****/

// ll fastinputoutput()
// {
//   ll n = 0;
//   ll ch = getchar_unlocked();
//   while (ch < '0' || ch > '9')
//     ch = getchar_unlocked();
//   while (ch >= '0' && ch <= '9')
//   {
//     n = (n << 3) + (n << 1) + ch - '0';
//     ch = getchar_unlocked();
//   }
//   return n;
// }

// ll powerFulPerson(ll x, ll y, ll p)
// {
//   ll res = 1;
//   x = x % p;

//   if (x == 0)
//     return 0;

//   while (y > 0)
//   {
//     if (y & 1)
//       res = (res * x) % p;
//     y = y >> 1;
//     x = (x * x) % p;
//   }
//   return res;
// }


int main()
{
    tez_chal_bsdk;
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    int n, q; cin >> n >> q;
    int weight[n], queryyy[q][2];
    FOR(i, 0, n)
    cin >> weight[i];
    vector<vector<int>> v(n);
    FOR(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        v[a - 1].pb(b - 1);
        v[b - 1].pb(a - 1);
    }
    FOR(i, 0, q)
    {
        cin >> queryyy[i][0] >> queryyy[i][1];
    }
    
    FOR(i, 0, q)
    {
        vector<int> v11 = {0}, v22 = {0};
        vector<int> visited1(n, 0), visited2(n, 0);
        dfs(v, queryyy[i][0] - 1, visited1, 0, v11);
        dfs(v, queryyy[i][1] - 1, visited2, 0, v22);
        long long sum = 0;
        FOR(i, 0, v11.size())
        {
            sum = (sum + (long)weight[v11[i]] * (long)weight[v22[i]]) % 4294967296;
        }
        cout << sum ;
        cout<<endl;
    }
}





void initializeArray2(int *ss)
{
  ss[1] = 1; ss[2] = 15; ss[3] = 64; ss[4] = 158; ss[5] = 271;
  ss[6] = 317; ss[7] = 126; ss[8] = 34; ss[9] = 253; ss[10] = 13;
  ss[11] = 92; ss[12] = 30; ss[13] = 47; ss[14] = 31; ss[15] = 2;
  ss[16] = 0; ss[17] = 1; ss[18] = 13; ss[19] = 0; ss[20] = 0; ss[21] = 9;
  ss[22] = 1; ss[23] = 0; ss[24] = 0; ss[25] = 1; ss[26] = 5; ss[27] = 0;
  ss[28] = 0; ss[29] = 5;
}


int part2(int n)
{
  if (n % 4 == 0 || n % 4 == 3) return 0;
  else return 1;
}
void part1(int n)
{
  int d;
  if (n % 4 == 0 || n % 4 == 3)
  {d = 0;}
  else
  {d = 1;}
  cout << d << endl;
}
