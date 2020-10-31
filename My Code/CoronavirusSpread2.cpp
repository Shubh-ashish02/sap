#include<bits/stdc++.h>
#include<algorithm>
#include<limits.h>
using namespace std;
#define ll long long
#define ld long double
#define FastIo ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 998244353
#define pb push_back
#define mp make_pair
float crossing_time[5][5];
int isPositive[5];


initialize(int n) {
	int i;
	for (i = 0; i < n; i++) {
		isPositive[i] = 0;
	}
	return 1;
}

int count(int i, int n, float t) {
	isPositive[i] = 1;
	int j, c;
	c = 1;
	for (j = 0; j < n; j++) {
		if (crossing_time[i][j] > t && isPositive[j] == 0) {
			c += count(j, n, crossing_time[i][j]);
		}
	}
	return c;
}

int  main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FastIo
	int i, j, n, t, v[5], c[5], min, max;
	cin >> t;
	while (t--)
	{
		min = 0;
		max = 6;
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (i = 0; i < n; i++) {
			for (j = i; j < n; j++) {
				if (i == j) {
					crossing_time[i][j] = 0;
				}
				else if (v[i] - v[j] == 0) {
					crossing_time[i][j] = 0;
					crossing_time[j][i] = crossing_time[i][j];
				}
				else {
					crossing_time[i][j] = (float) (j - i) / (v[i] - v[j]) ;
					crossing_time[j][i] = crossing_time[i][j];
				}
			}
		}
		for (i = 0; i < n; i++) {
			c[i] = count(i, n, 0);
			if (c[i] > min)
				min = c[i];
			if (c[i] < max)
				max = c[i];
			initialize(n);
		}
		cout << max << " " << min << endl;
	}
	return 0;
}