#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int T, n, a[2 * maxn], p[2 * maxn], vis[2 * maxn];
void solve() {
	int ans = 0;
	for (int i = 1; i <= 2 * n; i++) p[i] = vis[i] = 0;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) cin >> a[i];
	for (int i = 1; i <= 2 * n; i++)
		if (vis[a[i]] == 0) vis[a[i]] = i;
		else p[i] = vis[a[i]];
	for (int i = 2; i <= 2 * n; i++)
		if(p[i - 1]) {
			int x = p[i - 1];
			if(x == i - 2) continue; //p[i - 1]Óëi-1ÏàÁÚ 
			if(a[x + 1] == a[i] || a[x - 1] == a[i]) ans++;
		}
	cout << ans << endl;
}

signed main() {
	cin >> T;
	while(T--) solve();
	return 0;
}
