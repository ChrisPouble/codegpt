#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 13, K = 110, M = 1 << N;
int n, k, ans, cnt[M], f[N][K][M];
vector<int> state;
vector<int> head[M];
bool check(int x) {
    for (int i = 0; i < n; i++)
        if((x >> i & 1) && (x >> i + 1 & 1))
            return false;
    return true;
}

int count(int x) {
    int res = 0;
    for (int i = 0; i < n; i++) res += x >> i & 1;
    return res;
}

signed main() {
    cin >> n >> k;
    for (int i = 0; i < 1 << n; i++)
        if(check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++) {
            int a = state[i], b = state[j];
            if((a & b) == 0 && check(a | b))
                head[a].push_back(b);
        }
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int a = 0; a < state.size(); a++)
                for (auto b:head[state[a]]) {
                    int c = cnt[state[a]];
                    if(j >= c) f[i][j][state[a]] += f[i - 1][j - c][b];
                }
    for (int i = 0; i < 1 << n; i++) ans += f[n][k][i];
    cout << ans << endl;
    return 0;
}
