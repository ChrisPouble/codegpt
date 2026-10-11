#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int K = 35;

int n, x;
int t[N], c[N];
int dp[K][N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> x;
    
    for (int i = 0; i <= 30; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        
        for (int j = 0; j <= 30; ++j) {
            dp[j][i][0] = dp[j][i - 1][0];
            dp[j][i][1] = dp[j][i - 1][1];
            
            if (t[i] == 1) {
                dp[j][i][0] &= (c[i] >> j & 1);
                dp[j][i][1] &= (c[i] >> j & 1);
            } else if (t[i] == 2) {
                dp[j][i][0] |= (c[i] >> j & 1);
                dp[j][i][1] |= (c[i] >> j & 1);
            } else {
                dp[j][i][0] ^= (c[i] >> j & 1);
                dp[j][i][1] ^= (c[i] >> j & 1);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 30; ++j) {
            int b = (x >> j & 1);
            x -= (b << j);
            x += (dp[j][i][b] << j);
        }
        cout << x << '\n';
    }
    
    return 0;
}