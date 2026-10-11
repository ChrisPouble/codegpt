#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bool v[5010];
struct node{
	int l, r, w;
}a[3010];

bool cmp(node x, node y) {
	if(x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].l >> a[i].r >> a[i].w;
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = a[i].l; j <= a[i].r; j++)
			if(v[j]) a[i].w--;
		if(a[i].w > 0)
			for (int j = a[i].r; j >= a[i].l && a[i].w > 0; j--)
				if(!v[j]) v[j] = true, a[i].w--;
	}
	for (int i = 1; i <= n; i++)
		if(v[i]) ans++;
	cout << ans << endl;
	return 0;
}
