#include <bits/stdc++.h>
using namespace std;

long long n, q, t[5000000], p[5000000], dp[5000000];
int main() {
	freopen("share15.in","r",stdin);
	freopen("share15.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int min_i = 1;
	for (int i = 2; i <= n; i++)
		min_i = t[i] < t[min_i] ? i : min_i;
	dp[min_i] = t[min_i];
	for (int i = 1; i <= n; i++) {
		int temp = min_i + i;
		if(temp > n) temp -= n;
//		if(temp == 1) dp[temp] = min(t[temp], dp[n] + p[n]); 
//		else dp[temp] = min(t[temp], dp[temp - 1] + p[temp - 1]);
		if(temp == 1) dp[temp] = t[temp] < (dp[n] + p[n]) ? t[temp] : (dp[n] + p[n]); 
		else dp[temp] = t[temp] < (dp[temp - 1] + p[temp - 1]) ? t[temp] : (dp[temp - 1] + p[temp - 1]);
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int t; cin >> t;
		cout << dp[t] << endl;
	}
	return 0;
}
/*
5
0 5 10 15 20
3 4 5 6 7
3
2
3
5

3
7
18
*/ 
