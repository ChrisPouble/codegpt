#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

const int inf = 2e9;
int n, s, t, ans;
bool is = false;
struct node {
    int l, r;
} a[maxn];

bool cmp(node x, node y) {
    return x.l < y.l;
}

int main() {
    cin >> s >> t >> n;
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) {
        int j = i, cnt = -inf;
        while (j < n && a[j].l <= s) cnt = max(cnt, a[j].r), j++;
        if (cnt < s) break;
        ans++;
        if (cnt >= t) {
            is = 1;
            break;
        }
        i = j - 1, s = cnt;
    }
    if (!is) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
