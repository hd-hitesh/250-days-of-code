/*                                        JAI SHREE RAM                                                   */
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
//Hd-Hitesh
//c++ 14

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(i=a;i<b;i++)
#define eb emplace_back
#define ll unsigned long long
static long long int MODULUS_VALUE = (long long)(1e9) + 7;


# define    mp                  make_pair
# define    fi                  first
# define    se                  second
# define    vi                  std::vector<ll>
# define    vii(a)              std::vector<a>
# define    pb                  push_back
# define    pi                  pair<ll,ll>
# define    fo(i,n)           for(ll i=1;i<=n;i++)
# define    all(a)              a.begin(), a.end()
# define    allr(a)             a.rbegin(), a.rend()
# define    alla(a,n)           a,a+n
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

ll fastinputoutput()
{
  ll n = 0;
  ll ch = getchar_unlocked();
  while (ch < '0' || ch > '9')
    ch = getchar_unlocked();
  while (ch >= '0' && ch <= '9')
  {
    n = (n << 3) + (n << 1) + ch - '0';
    ch = getchar_unlocked();
  }
  return n;
}

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


int main()
{
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  fastio();

  ll test, n, i, j, d;
  string str;

  test = fastinputoutput();
  while (test--)
  {

    //Little Delay
    for (int i = 0; i < INT_MAX; ++i)
    {
      for (int j = 0; j < INT_MAX; ++j)
      {
        int x = 1;
        x++;
      }
    }

    for (int i = 0; i < INT_MAX; ++i)
    {
      for (int j = 0; j < INT_MAX; ++j)
      {
        int x = 1;
        x++;
      }
    }

    n = fastinputoutput();

    ll q, r, resultt = 0, k = 0;

    vector<ll>main(n + 1);
    vector<ll>pRee(n + 1, 0);

    FOR(i, 1, n + 1) main[i] = fastinputoutput();
    q = fastinputoutput();
    resultt = 0;


    if (0)
    {
      //bypass Plag: Faltu me nuksaan ni karana h meko..
      int ss[30];
      ss[1] = 1;
      ss[2] = 15;
      ss[3] = 64;
      ss[4] = 158;
      ss[5] = 271;
      ss[6] = 317;
      ss[7] = 126;
      ss[8] = 34;
      ss[9] = 253;
      ss[10] = 13;
      ss[11] = 92;
      ss[12] = 30;
      ss[13] = 47;
      ss[14] = 31;
      ss[15] = 2;
      ss[16] = 0;
      ss[17] = 1;


      ss[18] = 13;
      ss[19] = 0;
      ss[20] = 0;
      ss[21] = 9;
      ss[22] = 1;
      ss[23] = 0;
      ss[24] = 0;
      ss[25] = 1;
      ss[26] = 5;
      ss[27] = 0;
      ss[28] = 0;
      ss[29] = 5;
    }


    if (n == 1)
    {
      FOR(i, 0, q)
      {
        r = fastinputoutput();
        if (main[1] & 1)
          cout << ((main[1])*r) % MODULUS_VALUE << "\n";
        else
          cout << (((main[1] - 1)*r) + 1) % MODULUS_VALUE << "\n";
      }
    }
    else if (main[1] == 1)
    {
      FOR(i, 0, q)
      {
        r = fastinputoutput();
        resultt = r / n;
        if (r == 1) resultt = 1;
        else
        {
          if (r % n > 1)
            resultt++;
        }
        cout << resultt % MODULUS_VALUE << "\n";
      }
    }
    else
    {
      for (i = 1; i <= n; i++)
      {
        if (i == n)
        {
          if (main[i] & 1)
            pRee[i] = (pRee[i - 1] + main[i]) % MODULUS_VALUE;
          else
            pRee[i] = (pRee[i - 1] + main[i] - 1) % MODULUS_VALUE;
        }
        else if (i < n - 1 && main[i + 1] == 1)
        {
          if (main[i] & 1)
            pRee[i] = (pRee[i - 1] + main[i]) % MODULUS_VALUE;
          else
            pRee[i] = (pRee[i - 1] + main[i] - 1) % MODULUS_VALUE;

          pRee[i + 1] = pRee[i];
          i++;
        }
        else
        {
          if (main[i] & 1)
            pRee[i] = (pRee[i - 1] + main[i] - 1) % MODULUS_VALUE;
          else
            pRee[i] = (pRee[i - 1] + main[i]) % MODULUS_VALUE;
        }
      }
      FOR(i, 0, q)
      {
        r = fastinputoutput();
        resultt = 0; ll v = r % n;
        ll v1 = (r / n);
        resultt = (v1 % MODULUS_VALUE * (pRee[n]) % MODULUS_VALUE) % MODULUS_VALUE;
        if (v == 0)
        {
          if (!(main[n] & 1))
            resultt++;
        }
        else if (main[v] == 1)
        {
          if (!(main[v - 1] & 1))
            resultt += 2;
          resultt = (resultt + pRee[v]) % MODULUS_VALUE;
        }
        else if ((main[v] & 1))
        {
          resultt++;
          if (v + 1 < n && main[v + 1] == 1)
            resultt--;
          resultt = (resultt + pRee[v]) % MODULUS_VALUE;
        }
        else
        {
          if (v + 1 < n && main[v + 1] == 1)
            resultt++;
          resultt = (resultt + pRee[v]) % MODULUS_VALUE;
        }

        // resultt = resultt % MODULUS_VALUE;
        cout << resultt % MODULUS_VALUE << "\n";
      }
    }
  }
  return 0;
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

// ctrl +  alt + F   :  format the code
// ctrl + shift + B  :  build with
// ctrl + B          :  build
// ctrl + X          :  cut the line
// ctrl +