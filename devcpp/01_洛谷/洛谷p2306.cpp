#include <bits/stdc++.h>
using namespace std;

int n, ans = 2e9;
struct food{
	int s, b;
}a[15];

int dfs(int x, int s, int b) {
	if(x > n) return abs(s - b);
	return min(dfs(x + 1, s * a[x].s, b + a[x].b), dfs(x + 1, s, b));
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].b;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dfs(i + 1, a[i].s, a[i].b));
	cout << ans << endl;
    return 0;
}
