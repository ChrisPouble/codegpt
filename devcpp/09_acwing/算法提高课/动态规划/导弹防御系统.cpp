#include <bits/stdc++.h>
#define maxn 55
using namespace std;

int n, ans, up[maxn], down[maxn], a[maxn];
void dfs(int u, int d, int s) { //选择的上升子序列个数，下降子序列个数和当前的位置
    if (u + d >= ans) return;
    if (s == n + 1) {
        ans = min(ans, u + d);
        return;
    }
    int k = 1;
    while (k <= u && up[k] >= a[s]) k++;
    if (k <= u) {
        int t = up[k];
        up[k] = a[s];
        dfs(u, d, s + 1);
        up[k] = t;
    } else {
        up[k] = a[s];
        dfs(u + 1, d, s + 1);
    }
    
    k = 1;
    while (k <= d && down[k] <= a[s]) k++;
    if (k <= d) {
        int t = down[k];
        down[k] = a[s];
        dfs(u, d, s + 1);
        down[k] = t;
    } else {
        down[k] = a[s];
        dfs(u, d + 1, s + 1);
    }
}

void solve() {
    memset(up, 0, sizeof(up)), memset(down, 0, sizeof(down)), memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = n, dfs(0, 0, 1), cout << ans << endl;
}

signed main() {
    while(cin >> n && n) solve();
    return 0;
}
