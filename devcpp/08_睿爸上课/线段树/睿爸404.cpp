#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int H, W, n, a[maxn], maxv[4 * maxn];
void build(int id, int l, int r) {
	if(l == r) {
		maxv[id] = W;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	maxv[id] = W;
}

void update(int id, int l, int r, int x, int v) {
	if(l == r) {
		maxv[id] -= v;
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) update(id * 2, l, mid, x, v);
	else update(id * 2 + 1, mid + 1, r, x, v);
	maxv[id] = max(maxv[id * 2], maxv[id * 2 + 1]);
}

int query_max(int id, int l, int r, int x) {
	if(l == r) return l;
	int mid = (l + r) / 2;
	if(maxv[id * 2] >= x) return query_max(id * 2, l, mid, x);
	else if(maxv[id * 2 + 1] >= x) return query_max(id * 2 + 1, mid + 1, r, x);
}

int main() {
	cin >> H >> W >> n;
	H = min(H, n); 
	build(1, 1, H);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if(maxv[1] < a[i]) cout << -1 << endl;
		else {
			int pos = query_max(1, 1, H, a[i]); 
			cout << pos << endl;
			update(1, 1, H, pos, a[i]);
		}
	}
	return 0;
}
