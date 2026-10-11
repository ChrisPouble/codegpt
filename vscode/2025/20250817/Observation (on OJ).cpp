#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) x & -x
#define endl "\n"
const int N = 8e5 + 10;

using namespace std;
int n, q, st[N][25];
int siz[N], dfn[N], cnt, tree[N];
vector<int> linker[N];
bool a[N];
void add(int x, int y) {
    linker[x].push_back(y);
}

void dfs(int x) {
    dfn[x] = ++cnt, siz[x] = 1;
    for (int v : linker[x]) {
        st[v][0] = x;
        for (int i = 1; i <= 20; i++)
            st[v][i] = st[st[v][i - 1]][i - 1];
        dfs(v);
        siz[x] += siz[v];
    }
}

void update(int x, int d) {
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

int get(int x) {
    int sum = 0;
    while (x) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 2, x; i <= n; i++)
        cin >> x, add(x, i);
    
    dfs(1);
    while (q--) {
        int x;
        cin >> x;
        if (x > 0) {
            if (!a[x]) update(dfn[x], 1);
            else update(dfn[x], -1);
            a[x] ^= 1;
        } else {
            x = -x;
            if (get(dfn[x] + siz[x] - 1) > get(dfn[x] - 1)) {
                cout << x << endl;;
                continue;
            }
            for (int i = 20; i >= 0; i--)
                if (st[x][i] && get(dfn[st[x][i]] + siz[st[x][i]] - 1) == get(dfn[st[x][i]] - 1))
                    x = st[x][i];
            cout << st[x][0] << endl;
        }
    }
    return 0;
}