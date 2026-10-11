#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9 + 10;
struct sb{
	int s, b;
}a[15];

void dfs(int x, int s, int b) {
	if(x == n) {
		ans = min(ans, abs(s - b));
		return;
	}
	dfs(x + 1, s * a[x + 1].s, b + a[x + 1].b);
	dfs(x + 1, s, b); 
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].b;
	for (int i = 1; i <= n; i++)
		dfs(i, a[i].s, a[i].b);
	cout << ans << endl;
	return 0;
} 
