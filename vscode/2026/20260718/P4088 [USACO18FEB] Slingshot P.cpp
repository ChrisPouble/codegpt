#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 10;
const int PYG = 1000;

struct Gong {
	ll x, y, t;
} g[N], p[N];

int n, m;

bool cmp1(Gong a, Gong b) { return a.x < b.x; }
bool cmp2(Gong a, Gong b) { return a.y < b.y; }

int lower(ll id, bool flag) {
	int l = 1, r = n, ans = n + 1;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		
		if (!flag) {
			if (g[mid].x >= id) ans = mid, r = mid - 1;
			else l = mid + 1;
		} else {
			if (p[mid].y >= id) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
	}
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    freopen("hackin.in", "r", stdin);
    freopen("hackout.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> g[i].x, p[i].x = g[i].x;
		cin >> g[i].y, p[i].y = g[i].y;
		cin >> g[i].t, p[i].t = g[i].t;
	}
	
	sort(g + 1, g + n + 1, cmp1);
	sort(p + 1, p + n + 1, cmp2);
	
	for (int i = 1; i <= m; i++) {
		ll st, ed; cin >> st >> ed;
		
		ll ans = abs(st - ed);
		int gid = lower(st, 0);
		int pid = lower(ed, 1);
		
        int starting = max(1, (int)(gid - PYG)), ending = min(n, gid + PYG);
		for (int i = starting; i <= ending; i++)
			ans = min(ans, g[i].t + abs(g[i].x - st) + abs(g[i].y - ed));
		
        starting = max(1, (int)(pid - PYG)), ending = min(n, pid + PYG);
		for (int i = starting; i <= ending; i++)
			ans = min(ans, p[i].t + abs(p[i].x - st) + abs(p[i].y - ed));
		
//		for (int k = 1; k <= n; k++) {
//			ans = min(ans, g[k].t + abs(g[k].x - st) + abs(g[k].y - ed));
////			cout << ans << " ";
//		}
		
		cout << ans << "\n";
	}
	
	return 0;
}