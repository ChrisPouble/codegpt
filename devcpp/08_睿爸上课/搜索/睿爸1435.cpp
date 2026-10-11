#include <bits/stdc++.h>
using namespace std;

int n, k, ans, a[25];
bool is(int x) {
	if (x == 0 || x == 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}

void dfs(int x, int pts, int sum) {
	if(pts == k) {
		if(is(sum)) ans++;
		return;
	}
	if(x == n + 1) return;
	dfs(x + 1, pts + 1, sum + a[x]);
	dfs(x + 1, pts, sum);
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
