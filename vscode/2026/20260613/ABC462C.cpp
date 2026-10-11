#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, ans[N], tree[N];
struct node { int x, y, id; } a[N] ;

int lowbit(int x) { return x & -x; }

int query(int x) {
    int res = 0;
    while (x) { res += tree[x], x -= lowbit(x); }
    return res;
}

void add(int x, int c) {
    while (x <= n) { tree[x] += c, x += lowbit(x); }
}

bool cmp(node p, node q) { return p.x < q.x; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        // cout << a[i].x << " ";
        ans[a[i].id] = query(a[i].y - 1);
        add(a[i].y, 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (!ans[i]) res++;
    cout << res << endl;

    return 0;
}