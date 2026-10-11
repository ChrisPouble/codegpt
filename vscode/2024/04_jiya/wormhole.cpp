#include <bits/stdc++.h>
using namespace std;

int fa[100010];
char q[100010];
int find(int x) {
	if(x == fa[x]) return x;
	else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}

void hb(int x, int y) {
	int xx = find(x);
	int yy = find(y);
	fa[xx] = yy;
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
	    cin >> q[i];
	for (int i = 1; i <= n; i++)
	    fa[i] = i;
	for (int i = 1; i <= n - 1; i++) {
		int x, y; cin >> x >> y;
		if(find(x) != find(y) && q[x] == q[y]) hb(x, y);
	}
	for (int i = 1; i <= m; i++) {
		int x, y; char p; cin >> x >> y >> p;
		int xx = find(x);
		int yy = find(y);
		if(xx == yy && q[xx] != p) cout << 0;
		else cout << 1;
	}
	return 0;
}