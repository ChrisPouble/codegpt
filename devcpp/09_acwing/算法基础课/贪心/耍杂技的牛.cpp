#include <bits/stdc++.h>
#define maxn 50010
#define int long long
using namespace std;

int n, qsum, ans = -1e15;
struct node {
    int w, s;
    bool operator<(const node &h) {
        return w + s < h.w + h.s;
    }
} a[maxn];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].w >> a[i].s;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        ans = max(ans, qsum - a[i].s);
        qsum += a[i].w;
    }
    cout << ans << endl;
    return 0;
}
