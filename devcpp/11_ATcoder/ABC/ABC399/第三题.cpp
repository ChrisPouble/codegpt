#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int n, m, ans, fa[maxn];
struct Edge {
	int x, y;
} edge[maxn];

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1, x, y; i <= m; i++)
		cin >> edge[i].x >> edge[i].y;
	for (int i = 1; i <= m; i++) {
		int x = edge[i].x, y = edge[i].y;
		if(find(x) != find(y)) merge(x, y);
		else ans++;
	}
	cout << ans << endl;
	return 0;
}
