#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct node {
    int l, r, id;
} a[N * 2];

int n, m, ans[N];
int f[N][20];

bool cmp(node x, node y) {
    return x.l < y.l;
}

int get(int x) {
    int end = a[x].l + m, res = 0;
    for (int i = 18; i >= 0; i--)
        if (a[f[x][i]].r < end)
            x = f[x][i], res += (1 << i);
    return res + 2;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        if (a[i].r < a[i].l) a[i].r += m;
        a[i + n] = { a[i].l + m, a[i].r + m, i + n };
        a[i].id = i;
    }

    int nn = 2 * n;
    sort(a + 1, a + nn + 1, cmp);

    for (int i = 1, j = 1; i <= nn; i++) {
        while (j <= nn && a[j].l <= a[i].r) j++;
        f[i][0] = j - 1;
    }

    for (int j = 1; j <= 18; j++)
        for (int i = 1; i <= nn; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];

    for (int i = 1; i <= n; i++) ans[a[i].id] = get(i);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    system("pause");
    return 0;
}