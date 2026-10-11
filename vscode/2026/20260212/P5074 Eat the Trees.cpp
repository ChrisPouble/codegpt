#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 15;
const int M = (1 << N) + 10;

int n, m;
bool mp[N][N];  //地图

int dp[2][M];  //状态对应的方案数

int query(int S, int k) { //求出四进制数 S 的第 k 位
    return (S >> k) & 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    int now = 0, pre = 1; dp[pre][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < (1 << m + 1); k++) {
                int cur = k, left = query(k, j), up = query(k, j + 1);
                if (mp[i][j] == 0) {
                    if (!left && !up) dp[now][k] += dp[pre][k];
                    continue;
                }

                if (!left && !up) {
                    cur &= ~(1 << j), cur |= (1 << j);
                    cur &= ~(1 << (j + 1)), cur |= (1 << (j + 1));
                    dp[now][cur] += dp[pre][k]; // 情况1
                } else if (left && up) {
                    cur &= ~(1 << j), cur |= (0 << j);
                    cur &= ~(1 << (j + 1)), cur |= (0 << (j + 1));
                    dp[now][cur] += dp[pre][k]; // 情况 2
                } else { // 情况 3，4
                    cur &= ~(1 << j), cur |= (1 << j);
                    cur &= ~(1 << (j + 1)), cur |= (0 << (j + 1));
                    dp[now][cur] += dp[pre][k];
                    
                    cur &= ~(1 << j), cur |= (0 << j);
                    cur &= ~(1 << (j + 1)), cur |= (1 << (j + 1));
                    dp[now][cur] += dp[pre][k];
                }    
            }
            memset(dp[pre], 0, sizeof(dp[pre]));
            swap(now, pre);
        }
        
        for (int j = (1 << m) - 1; j >= 0; j--)
            dp[now][j << 1] = dp[pre][j];
        memset(dp[pre], 0, sizeof(dp[pre]));
        swap(now, pre);
    }
    cout << dp[pre][0] << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}