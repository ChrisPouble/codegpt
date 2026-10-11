// star time：12：38
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;

struct node { int need, val, flag; } a[N];

bool cmp(node x, node y) {
    if (x.flag != y.flag) return x.flag > y.flag;

    if (x.flag != -1) return x.need < y.need;
    return max(x.need, y.need - x.val) < max(y.need, x.need - y.val);
}

int n, tim;

void solve() {
    cin >> n >> tim;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].need >> a[i].val;
        a[i].flag = (a[i].val >= 0 ? 1 : -1);
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        if (tim <= a[i].need || tim <= 0) { cout << "-1s\n"; return ; }
        tim += a[i].val;
    }

    if (tim <= 0) cout << "-1s\n";
    else cout << "+1s\n";
}

signed main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}