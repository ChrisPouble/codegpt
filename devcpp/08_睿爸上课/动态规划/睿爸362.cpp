#include <bits/stdc++.h> 
using namespace std;

int n, V, ans, a[35], f[35][20010];
int main() {
	cin >> V >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= V; j++)
			if(j >= a[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
			else f[i][j] = f[i - 1][j];
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i][V]);
	cout << V - ans << endl;
	return 0;
}
