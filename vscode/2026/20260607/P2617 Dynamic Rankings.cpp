#include <bits/stdc++.h>
#define endl "\n"
#define enld endl
using namespace std;

int lowbit(int x) {
	return x & (-x);
}

const int inf = 1e9;
const int N = 2e5 + 10;

int n, m, tree[N], cnt = 0;
int ans[N], res[N];

void update(int x, int k) {
    while (x <= m) {
        tree[x] += k;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

struct node {
    int x, y, z, opt, i, k;
} a[N], q1[N], q2[N];

bool cmp(node x, node y) {
	if (x.x != y.x) return x.x < y.x;
	if (x.y != y.y) return x.y < y.y;
	if (x.z != y.z) return x.z < y.z;
	return x.opt < y.opt;
}

void solve(int l, int r, int L, int R) {
    if (L >= R || l >= r) return ;
    
    int mid = (l + r) >> 1;
	int tot1 = 0, tot2 = 0;
    for (int i = L; i <= R; i++) {
        if (a[i].opt == 1) {  // 在此处进行上述划分的左区间数值
            if (a[i].y <= mid) {
                update(a[i].z, a[i].k);
                q1[++tot1] = a[i];
            } else q2[++tot2] = a[i];
        } else {  // 在此处进行上述划分的右区间询问
            if (a[i].y >= mid) {
                ans[a[i].i] += get(a[i].z);
                q2[++tot2] = a[i];
            } else q1[++tot1] = a[i];
        }
    }
    
    for (int i = 1; i <= tot1; i++) {
        a[i + L - 1] = q1[i];
        if (q1[i].opt == 1) update(q1[i].z, -q1[i].k);
    }
    
    for (int i = 1; i <= tot2; i++)
        a[i + L + tot1 - 1] = q2[i];
    
    solve(l, mid, L, L + tot1 - 1);
    solve(mid + 1, r, L + tot1, R);
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, z; i <= n; i++) {
        cin >> x >> y >> z; 
        a[i] = node{x, y, z, 1, i, 1};
        a[i + n] = node{x, y, z, 2, i, 1};
    }
    
    sort(a + 1, a + 1 + n + n, cmp);
    solve(1, inf, 1, n + n);
    
    for (int i = 1; i <= n; i++) res[ans[i] - 1]++;
    for (int i = 0; i < n; i++) cout << res[i] << endl;
    return 0;
}