#include <bits/stdc++.h>
using namespace std;

#define xx first
#define yy second

const int N = 1e6 + 10;

int a[N], c[N];
int st[N], rk[N], cnt[N], F[N], tr[N];
int ans[N], pf[N], pb[N];
bool ch[N];

pair<int, int> g[N];

int n, m;
long long res;

void Add(int x, int v) {
    for (; x <= m; x += x & -x)
        tr[x] += v;
}

int Query(int x) {
    int sum = 0;
    for (; x > 0; x -= x & -x)
        sum += tr[x];
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (!st[a[i]]) {
            st[a[i]] = i;
            g[++m] = {i, a[i]};
        }
    }

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    sort(g + 1, g + 1 + m);
    for (int i = 1; i <= m; i++) {
        rk[g[i].yy] = i;
    }

    for (int i = 1; i <= n; i++) {
        int id = c[i], r = rk[id];
        
        int L = Query(r - 1);
        int R = (i - 1) - Query(r);
        int k = cnt[id];

        int c0 = min(L, R + k);
        int ck = min(L + k, R);

        if (c0 <= ck) {
            ch[i] = 0;
            F[id]++;
            res += c0;
        } else {
            ch[i] = 1;
            res += ck;
        }

        Add(r, 1);
        cnt[id]++;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i]) {
            pf[i] = st[i] + F[i] - 1;
            pb[i] = st[i] + F[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        int id = c[i];
        if (ch[i] == 0) ans[i] = pf[id]--;
        else ans[i] = pb[id]++;
    }

    cout << res << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}