#include <bits/stdc++.h>
#define maxn 2000010
#define N 2000010
#define int long long
using namespace std;

int n, m, c, cnt;
int a[maxn], ans[maxn], tree[maxn], lst[maxn], temp[N];
struct node {
	int type, pre_pre, pre, now, id;
} act[maxn * 2];

int lowbit(int x) { return x & -x; }

void update(int x, int d) {
	while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

int getsum(int x) {
	int res = 0;
	while (x >= 1) {
        res += tree[x];
        x -= lowbit(x);
    }
	return res;
}

bool cmp(node x, node y) {
	if (x.now == y.now) return x.type < y.type;
	return x.now < y.now;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	cin >> n >> c >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        act[++cnt] = { 2, 0, l, r, i };
    }
	
    for (int i = 1; i <= n; i++) lst[i] = temp[a[i]], temp[a[i]] = i;
	for (int i = 1; i <= n; i++) act[++cnt] = { 1, lst[lst[i]], lst[i], i, 0 };

	sort(act + 1, act + cnt + 1, cmp);
	
    for (int i = 1; i <= cnt; i++) {
		if (act[i].type == 1) {
  		    if (act[i].pre) update(act[i].pre, 1);
			if (act[i].pre_pre) update(act[i].pre_pre, -1);
		}
		else ans[act[i].id] = getsum(act[i].now) - getsum(act[i].pre - 1);
	}

	for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
	return 0;
}