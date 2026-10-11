#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i128 __int128

const int N = 25;

ll n, m;
ll f[N][N][3], dp[N][N][3];

vector<pair<ll, int> > ops;
map<int, int> comb;
i128 ans[3] = { 0, 0, 0 };

void dfs(int idx, ll lcm, int a, int b) {
    if (idx == ops.size()) {
        ll cnt = n / lcm;
        ans[0] += (i128)f[a][b][0] * cnt;
        ans[1] += (i128)f[a][b][1] * cnt;
        ans[2] += (i128)f[a][b][2] * cnt;
        return;
    }
    
    dfs(idx + 1, lcm, a, b);
    
    ll g = __gcd(lcm, ops[idx].first);
    i128 ncm = (i128)lcm / g * ops[idx].first;
    
    if (ncm <= n) {
        if (ops[idx].second == 1) dfs(idx + 1, (ll)ncm, a + 1, b);
        else dfs(idx + 1, (ll)ncm, a, b + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        ll x, c; cin >> x >> c;

        if (x == 0) continue;
        comb[x] = (comb[x] + c) % 3;
    }
    
    for (auto v : comb)
        if (v.second != 0) ops.push_back(v);
    
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][0][2] = 0;
    
    for (int a = 0; a <= 20; a++) {
        for (int b = 0; b <= 20; b++) {
            if (a == 0 && b == 0) continue;
            for (int c = 0; c < 3; c++) {
                if (a > 0) dp[a][b][c] = dp[a-1][b][c] - dp[a-1][b][(c + 2) % 3];
                else dp[a][b][c] = dp[a][b-1][c] - dp[a][b-1][(c + 1) % 3];
            }
        }
    }
    
    for (int a = 0; a <= 20; a++) {
        for (int b = 0; b <= 20; b++) {
            for (int c = 0; c < 3; c++) {
                if ((a + b) & 1) f[a][b][c] = -dp[a][b][c];
                else f[a][b][c] = dp[a][b][c];
            }
        }
    }
    
    dfs(0, 1, 0, 0);
    
    cout << (ll)ans[0] << " " << (ll)ans[1] << " " << (ll)ans[2] << "\n";
    
    return 0;
}