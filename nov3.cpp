#include<bits/stdc++.h>
using namespace std;
#define fori(i,j,n) for(int i=j;i<n;i++)
#define ford(i,j,n) for(int i=j;i>=n;i--)
#define ll long long int


void testcase()
{
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    int mag = 0, iro = 0, count = 0;
    int a[n];
    if (s[0] == ':')
        a[0] = 1;
    else
        a[0] = 0;
    fori(i, 1, n)
    {
        if (s[i] == ':')
            a[i] = a[i - 1] + 1;
        else
            a[i] = a[i - 1];
    }
    while (mag < n && iro < n)
    {
        if (s[mag] == 'X')
        {
            mag++;
            iro = mag;
        }
        else if (s[mag] != 'M')
            mag++;
        else
        {
            while (mag > iro && (k + 1 - abs(mag - iro) - abs(a[mag] - a[iro])) <= 0)
                iro++;
            while (iro < n && (k + 1 - abs(mag - iro) - abs(a[mag] - a[iro])) > 0)
            {
                if (s[iro] == 'X')
                {
                    mag = iro;
                    iro++;
                    break;
                }
                if (s[iro] != 'I')
                    iro++;
                else
                {
                    // cout<<iro<<" "<<mag<<"----------"<<endl;
                    count++;
                    iro++;
                    break;
                }
            }
            mag++;
        }
    }
    cout << count;
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        testcase();
    }
}