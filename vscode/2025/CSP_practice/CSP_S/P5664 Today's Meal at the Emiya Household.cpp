#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 110; // 烹饪方案
const int M = 2e3 + 10; // 食材
const int mod = 998244353;

int n, m;
int a[N][M];

int s[N];
int f[N][N], dp[N][2 * N];
// f[i][j] 表示前 i 个烹饪方法中，做 j 个菜的方案数
// dp[i][j][k] 表示前 i 个烹饪方法中，越界食材占用的菜的数量为 j，其它食材占用的菜的数量为 k 的方案数

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i] = (s[i] + a[i][j]) % mod;

    int ans = 0;

    f[0][0] = 1;
    for (int i = 1; i <= n; i++) { // 枚举前 i 个烹饪方法
        f[i][0] = 1;
        for (int j = 1; j <= i; j++) { // 枚举做了多少个菜
            f[i][j] += f[i - 1][j];
            f[i][j] += f[i - 1][j - 1] * s[i];
            f[i][j] %= mod;
        }
    }

    for (int i = 1; i <= n; i++)
        ans += f[n][i];

    for (int c = 1; c <= m; c++) { // 枚举越界食材
        memset(dp, 0, sizeof(dp));
        dp[0][n] = 1;
        for (int i = 1; i <= n; i++) { // 枚举前 i 个烹饪方法
            for (int j = 0; j <= n + i; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j) dp[i][j] += dp[i - 1][j - 1] * a[i][c];
                dp[i][j] += dp[i - 1][j + 1] * (s[i] - a[i][c]);
                dp[i][j] %= mod;
            }
        }

        for (int j = n + 1; j <= n + n; j++)
            ans = (ans - dp[n][j] + mod) % mod;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}