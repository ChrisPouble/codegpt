#include <bits/stdc++.h>
using namespace std;

int n, m, ans, fa[110];
struct edge{
	int u, v, w;
};

vector<edge>linker;
bool cmp(edge x, edge y) {
	return x.w < y.w;
}

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

void tree() {
	for (auto i:linker)
		if(find(i.u) != find(i.v)) {
			merge(i.u, i.v);
			ans += i.w;
		}
	cout << ans << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int w; cin >> w;
			linker.push_back({i, j, w});
		}
	sort(linker.begin(), linker.end(), cmp);
	tree();
	return 0;
}
