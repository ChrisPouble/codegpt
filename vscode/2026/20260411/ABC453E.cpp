#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
const int mod = 998244353;

int n;
ll fac[N], infac[N];

int bing[N]; // 并集：能去 A 或能去 B
int jiao[N]; // 交集：既能去 A 也能去 B
int dana[N]; // 专门统计能去 A 队的人数

ll ksm(ll x, int y) {
    ll res = 1ll;
    while (y) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod, y >>= 1;
    }
    return res;
}

ll get(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fac[n] * infac[m] % mod * infac[n - m] % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    fac[0] = infac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;

    infac[n] = ksm(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--)
        infac[i] = infac[i + 1] * (i + 1) % mod;

    for (int i = 1; i <= n; i++) {
        int L, R;
        cin >> L >> R;

        int l1 = L, r1 = R;
        int l2 = n - R, r2 = n - L;

        dana[l1]++, dana[r1 + 1]--;

        int tl1 = l1, tr1 = r1, tl2 = l2, tr2 = r2;
        if (tl1 > tl2) swap(tl1, tl2), swap(tr1, tr2);

        if (tl2 <= tr1) {
            bing[tl1]++;
            bing[max(tr1, tr2) + 1]--;
        } else {
            bing[tl1]++; bing[tr1 + 1]--;
            bing[tl2]++; bing[tr2 + 1]--;
        }

        int il = max(l1, l2), ir = min(r1, r2);
        if (il <= ir) {
            jiao[il]++;
            jiao[ir + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        bing[i] += bing[i - 1];
        jiao[i] += jiao[i - 1];
        dana[i] += dana[i - 1];
    }

    ll ans = 0;
    for (int x = 1; x < n; x++) {
        if (bing[x] != n) continue;

        int k = x - (dana[x] - jiao[x]);
        
        ans = (ans + get(jiao[x], k)) % mod;
    }

    cout << ans << endl;

    return 0;
}