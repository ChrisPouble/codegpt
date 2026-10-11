#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
const int mod = 998244353;

int lowbit(int x) { return x & -x; }

int n, m, a[N];
int tree[N];

int get(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

void insert(int x, int d) {
    if (x == 0) return ;
    while (x <= n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

bool check(int x, int now, int k) {
    int res = now + get(n) - get(x - 1);
    return res <= k;
}

int work(int k) {
    for (int i = 1; i <= n; i++)
        tree[i] = 0;

    int l = 1, r = 1;
    int ans = 0, now = 0;

    insert(a[l], 1);
    while (l <= n) {
        if (r < l) r = l, insert(a[r], 1);
        
        while (r + 1 <= n && check(a[r + 1], now, k))
            r++, insert(a[r], 1), now += (r - l + 1) - get(a[r]);

        now -= get(a[l] - 1);
        insert(a[l], -1);
        ans += r - l + 1, l++;

        // cout << ans << endl;
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cout << work(m) - (m ? work(m - 1) : 0) << endl;

    system("pause");
    return 0;
}