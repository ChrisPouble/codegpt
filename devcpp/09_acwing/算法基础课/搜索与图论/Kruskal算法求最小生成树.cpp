#include <bits/stdc++.h>
#define maxn 200010 
using namespace std;

int n, m, ans, fa[maxn];
struct Edge {
	int a, b, w;
} edge[maxn];

bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int find(int x) { //²éÑ¯ 
    if (x == fa[x]) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merge(int x, int y) { //ºÏ²¢ 
    int xx = find(x), yy = find(y);
    if (xx != yy) fa[xx] = yy;
}

void Kruskal() {
	int res = 0;
	for (int i = 1; i <= m; i++) {
		int u = edge[i].a, v = edge[i].b, w = edge[i].w;
		if(find(u) != find(v)) res++, ans += w, merge(u, v);
	}
	if(res != n - 1) {
		cout << "impossible" << endl;
		exit(0);
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w, edge[i] = {x, y, w};
	}
	sort(edge + 1, edge + m + 1, cmp);
	Kruskal();
	cout << ans << endl;
	return 0;
}
