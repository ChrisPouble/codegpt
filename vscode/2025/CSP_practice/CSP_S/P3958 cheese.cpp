#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10;

int n, h, r;
struct Node {
	int x, y, z;
} a[N];

int fa[N], min_h[N], max_h[N];

int dist(int x1, int x2, int yy1, int y2, int z1, int z2) {
	return (x1 - x2) * (x1 - x2) + (yy1 - y2) * (yy1 - y2) + (z1 - z2) * (z1 - z2);
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int xx = find(x), yy = find(y);
    
    fa[yy] = xx;
    min_h[xx] = min(min_h[xx], min_h[yy]);
    max_h[xx] = max(max_h[xx], max_h[yy]);
}

void solve() {
    cin >> n >> h >> r;

    for (int i = 1; i <= n; i++) fa[i] = i;
    
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		min_h[i] = a[i].z - r;
		max_h[i] = a[i].z + r;
	}

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (4 * r * r >= dist(a[i].x, a[j].x, a[i].y, a[j].y, a[i].z, a[j].z))
				merge(i, j);

	for (int i = 1; i <= n; i++) {
		if (fa[i] != i) continue;
		if (min_h[i] <= 0 && max_h[i] >= h) {
			cout << "Yes\n";
            return ;
		}
	}
	
    cout << "No\n";
}

signed main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

    int T;
	cin >> T;

	while (T--) solve();

    system("pause");
	return 0;
}