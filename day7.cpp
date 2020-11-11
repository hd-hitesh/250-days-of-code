#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--)
	{
		int n, k, f, m = 0, p = 0, l = 0, i = 0, j = 0;
		cin >> n >> k;
		string s;
		cin >> s;
		p = k + 1;
		// i for iron && j for magnet
		while (i < n && j < n)
		{
			if (s[i] == 'M')
			{
				if (s[j] == 'I')
				{

					f = p - abs(i - j) - l;
					if (f > 0)
					{
						m++;
						i++;
						j++;
					}
					else if (i > j)
						j++;
					else
						i++;
				}
				else if (s[j] == 'X')
				{
					i = j;
					i++;
					j++;
				}
				else
					j++;

			}
			else if (s[i] == 'X')
			{
				j = i;
				i++;
				j++;
			}
			else
				i++;
		}

		cout << m << endl;

	}
}
/*
Input
2
4 5
I::M
9 10
MIM_XII:M

Output
1
2
*/