#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 510;
const int mod = 1e9 + 7;

int n, k; string s;
ll f[N][N][5];
/*
    状态 1 (...)：整个区间刚好被一对括号包裹，且内部合法。（例如 ()、(*)、(()) 等）。
    状态 2 AS：左边是一个完整的合法序列，右边紧接着一段 *。（例如 ()*、(())**）。
    状态 3 A：任意合法的超级括号序列。（例如 ()、()()、()*()）。这是我们最终要求的答案状态。
    状态 4 SA：左边是一段 *，右边紧接着一个完整的合法序列。（例如 *()、**(())）。
*/
int cnt[N];

bool CAS(int l, int r) { // check all star
    if (l > r || r - l + 1 > k) return 0;
    // cnt[r] - cnt[l - 1] == 0 说明区间内没有 '(' 或 ')' 
    return (cnt[r] - cnt[l - 1] == 0); 
}

bool CM(int l, int r) { // can match
    if (l >= r) return 0;
    return (s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?');
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;
    s = " " + s;

    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        if (s[i] == '(' || s[i] == ')')
            cnt[i]++;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;

            if (CM(l, r)) {
                if (len == 2) {
                    f[l][r][1] = 1; // 仅为 () 的情况
                } else {
                    f[l][r][1] = (CAS(l + 1, r - 1) + 
                                  f[l + 1][r - 1][2] + 
                                  f[l + 1][r - 1][3] + 
                                  f[l + 1][r - 1][4]) % mod;
                }
            }

            f[l][r][3] = f[l][r][1]; // 本身就是一个不可分割的块 (...)
            for (int i = l + 1; i <= r - 2; i++) {
                // 形如 A = (...) 拼接 B
                f[l][r][3] = (f[l][r][3] + f[l][i][1] * f[i + 1][r][3]) % mod;
                // 形如 A = (...) 拼接 S 拼接 B (S 拼接 B 等价于状态 4)
                f[l][r][3] = (f[l][r][3] + f[l][i][1] * f[i + 1][r][4]) % mod;
            }

            for (int i = max(l + 1, r - k); i <= r - 1; ++i) {
                if (!CAS(i + 1, r)) continue;
                f[l][r][2] = (f[l][r][2] + f[l][i][3]) % mod;
            }

            for (int i = l; i <= min(r - 2, l + k - 1); ++i) {
                if (!CAS(l, i)) continue;
                f[l][r][4] = (f[l][r][4] + f[i + 1][r][3]) % mod;
            }
        }
    }
    
    cout << f[1][n][3] << "\n";
    return 0;
}