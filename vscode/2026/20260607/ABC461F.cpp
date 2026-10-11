#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
const int N = 45; // 选择元素数量
const int M = 2e5 + 10; // 可选择元素数量

int n, fac[N];
int tot, prime[N], cnt[N];
int kid, dvi[M];
unordered_map <int, int> id;

void init() {
    int m = n;
    for (int i = 2; i * i <= m; i++) {
        if (m % i) continue;

        prime[++tot] = i;
        while (m % i == 0) cnt[tot]++, m /= i;
    }

    if (m != 1) prime[++tot] = m, cnt[tot]++;

    dvi[++kid] = 1;
    for (int i = 1; i <= tot; i++) {
        int siz = kid, now = 1;
        for (int j = 1; j <= cnt[i]; j++) {
            now *= prime[i];
            for (int k = 1; k <= siz; k++) {
                dvi[++kid] = dvi[k] * now;
            }
        }
    }

    sort(dvi + 1, dvi + kid + 1);
}

int f[N][M], g[N][M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    // 特判 n = 1
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    init();
    
    for (int i = 1; i <= kid; i++)
        id[dvi[i]] = i;

    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % mod;

    f[0][id[1]] = 1;

    for (int i = 1; i <= kid; i++) {
        int d = dvi[i];
        
        for (int j = kid; j >= 1; j--) {
            int m = dvi[j];
            if (m > n / d) continue;
            
            int newm = m * d;
            if (id.find(newm) == id.end()) continue;
            
            for (int k = N - 2; k >= 0; k--) {
                if (f[k][j] == 0) continue;
                
                f[k + 1][id[newm]] = (f[k + 1][id[newm]] + f[k][j]) % mod;
                g[k + 1][id[newm]] = (g[k + 1][id[newm]] + (g[k][j] + d % mod * f[k][j] % mod) % mod) % mod;
            }
        }
    }

    int ans = 0; 
    for (int k = 1; k < N; k++)
        ans = (ans + g[k][id[n]] * fac[k] % mod) % mod;
    
    cout << ans << "\n";

    return 0;
}