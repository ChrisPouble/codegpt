#include <bits/stdc++.h>
using namespace std;

const int N = 15, M = 1 << N, mod = 1e8;
int n, m, ans, w[N], f[N][M];
vector<int> state;
vector<int> head[M];
bool check(int x) {
    for (int i = 0; i < m; i++)
        if((x >> i & 1) && (x >> i + 1 & 1))
            return false;
    return true;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0, t; j < m; j++) {
            cin >> t;
            w[i] += !t * (1 << j);
        }
    for (int i = 0; i < 1 << m; i++)
        if(check(i)) state.push_back(i);
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if((a & b) == 0) head[a].push_back(b);
        }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < state.size(); j++)
            if (!(state[j] & w[i]))
                for (auto k:head[state[j]])
                    f[i][state[j]] = (f[i][state[j]] + f[i - 1][k]) % mod;
    for (int i = 0; i < 1 << m; i++)
        ans = (ans + f[n][i]) % mod;
    cout << ans << endl;
    return 0;
}
