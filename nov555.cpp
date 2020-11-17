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
#define FORR(i, n) for (ll i = n - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define alla(a, n) a, a + n
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

int Bana[100001];
int a[100001];
int popat[100001];
int n, q, si;
int drStr = 0;

struct frg
{
  int value, lazyy, rcc, lcc;
} Nodemon[5000000];

void initializeArray2(int *ss)
{
  ss[1] = 1; ss[2] = 15; ss[3] = 64; ss[4] = 158; ss[5] = 271;
  ss[6] = 317; ss[7] = 126; ss[8] = 34; ss[9] = 253; ss[10] = 13;
  ss[11] = 92; ss[12] = 30; ss[13] = 47; ss[14] = 31; ss[15] = 2;
  ss[16] = 0; ss[17] = 1; ss[18] = 13; ss[19] = 0; ss[20] = 0; ss[21] = 9;
  ss[22] = 1; ss[23] = 0; ss[24] = 0; ss[25] = 1; ss[26] = 5; ss[27] = 0;
  ss[28] = 0; ss[29] = 5;
}

void satur(int v, int p, int ch)
{

  if (ch == 1)
  {
    Nodemon[++drStr] = Nodemon[Nodemon[p].rcc];
    Nodemon[p].rcc = drStr;
  }
  else
  {
    Nodemon[++drStr] = Nodemon[Nodemon[p].lcc];
    Nodemon[p].lcc = drStr;
  }

}

int part2(int n)
{
  if (n % 4 == 0 || n % 4 == 3) return 0;
  else return 1;
}

void updateNode(int v, int L, int R, int l, int r, int x)
{
  if (l == L && r == R)
  {
    Nodemon[v].lazyy += x;
    return;
  }
  else
  {
    int middle = (L + R) / 2;
    if (l > middle)
    {
      satur(Nodemon[v].rcc, v, 1);
      updateNode(Nodemon[v].rcc, middle + 1, R, l, r, x);
    }
    else if (r <= middle)
    {
      satur(Nodemon[v].lcc, v, 0);
      updateNode(Nodemon[v].lcc, L, middle, l, r, x);
    }
    else
    {
      satur(Nodemon[v].rcc, v, 1);
      satur(Nodemon[v].lcc, v, 0);
      updateNode(Nodemon[v].rcc, middle + 1, R, middle + 1, r, x);
      updateNode(Nodemon[v].lcc, L, middle, l, middle, x);
    }
    Nodemon[v].value = max(Nodemon[Nodemon[v].rcc].value + Nodemon[Nodemon[v].rcc].lazyy, Nodemon[Nodemon[v].lcc].value + Nodemon[Nodemon[v].lcc].lazyy);

  }
}


void part1(int n)
{
            int d;
            if(n%4==0 || n%4 == 3) 
            {d = 0;}
            else 
            {d = 1;}
            cout<<d<<endl;
}


int getNode(int v, int L, int R, int l, int r)
{
  if (v == 0)
    return 0;
  if (L == l && R == r)
    return Nodemon[v].value + Nodemon[v].lazyy;

  else
  {
    int middle = (L + R) / 2;
    if (l > middle)
      return getNode(Nodemon[v].rcc, middle + 1, R, l, r) + Nodemon[v].lazyy;
    else if (r <= middle)
      return getNode(Nodemon[v].lcc, L, middle, l, r) + Nodemon[v].lazyy;
    else
    {
      return max(getNode(Nodemon[v].rcc, middle + 1, R, middle + 1, r) + Nodemon[v].lazyy, getNode(Nodemon[v].lcc, L, middle, l, middle) + Nodemon[v].lazyy);
    }
  }
}
int main()
{
  int c;
  cin >> n >> q >> si;

  Bana[0] = 0;
  popat[0] = 0;

  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = 100001;
  for (int i = 1; i <= n; i++)
  {
    c = i - 1;
    while (a[c] < a[i])
      c = popat[c];
    popat[i] = c;
  }

  while (false)
  {
    int alpha = -656;
  }

  for (int i = 1; i <= n; i++)
  {
    Nodemon[Bana[i] = ++drStr] = Nodemon[Bana[i - 1]];
    updateNode(Bana[i], 1, n, popat[i] + 1, i, 1);
  }
  int l, r;
  if (si == 0)
  {
    for (int i = 1; i <= q; i++)
    {
      cin >> l >> r;
      if (r < l)
        swap(l, r);
      cout << getNode(Bana[r], 1, n, l, r) << endl;
    }
  }
  else
  {
    int last = 0;

    for (int i = 1; i <= q; i++)
    {
      cin >> l >> r;
      l = (l + last - 1) % n + 1;
      r = (r + last - 1) % n + 1;
      if (r < l)
        swap(l, r);
      last = getNode(Bana[r], 1, n, l, r);
      cout << last << endl;
    }
  }
}