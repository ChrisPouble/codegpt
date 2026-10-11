#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int K;
string S;

void solve() {
    cin >> S >> K;
    int N = S.length();
    
    vector<int> Z(N + 1, 0);
    for (int i = 3; i <= N; ++i)
        if (S[i - 3] == 'A' && S[i - 2] == 'B' && S[i - 1] == 'C')
            Z[i] = 1;
    
    vector<int> X(N + 1, 0);
    for (int i = 3; i <= N; ++i)
        X[i] = Z[i - 2] + Z[i - 1] + Z[i];
    
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, INF));
    
    for (int i = 0; i <= N; ++i)
        dp[i][0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            int ans = INF;
            
            int prev2 = j + Z[i];
            if (prev2 <= K) {
                ans = min(ans, dp[i - 1][prev2]);
            }
            
            if (i >= 3) {
                int yi = (S[i - 3] != 'A') + (S[i - 2] != 'B') + (S[i - 1] != 'C');
                
                int prev1 = j - 1 + X[i];
                if (prev1 < 0) prev1 = 0;
                
                if (prev1 <= K) {
                    ans = min(ans, dp[i - 3][prev1] + yi);
                }
            }
            
            dp[i][j] = ans;
        }
    }
    
    int result = dp[N][K];
    if (result >= INF) cout << -1 << "\n";
    else cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    while (T--) solve();
    return 0;
}