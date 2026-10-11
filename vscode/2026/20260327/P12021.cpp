#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
const int N = 1e5 + 10;

int n, k;
int dp[N];

vector<int> linker;

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> k;

    linker.clear();
    linker.push_back(0);
    // linker[x] 表示 k ^ (x - 1) 的倍数有多少个

    int tmp = n;
    while (tmp) {
        linker.push_back(tmp - tmp / k);
        tmp /= k;
    }
    
    for (int i = 1; i < (int)linker.size() - 1; i++)
        linker[i] -= linker[i + 1];
    
    int ans = 1;
    for (int i = 1; i < (int)linker.size(); i++)
        ans = ans * qpow(dp[i], linker[i]) % mod;
    
    cout << ans << "\n";
}

signed main() {
    dp[0] = 1, dp[1] = 2;
    for (int i = 2; i < N; i++)
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    
    int T;
    cin >> T;
    
    while (T--) solve();
    
    return 0;
}