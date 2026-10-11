#include <bits/stdc++.h>
using namespace std;

int n, l, r, ans, a[45];
void dfs(int x, int sum) {
	if(sum > r) return;
	if(x == n + 1) {
		if(sum >= l && sum <= r) {
			ans++;
		}
		return;
	}
	dfs(x + 1, sum + a[x]);
	dfs(x + 1, sum);
}

int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
/*
4 1 20
2 3 4 5
*/
