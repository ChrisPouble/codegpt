#include <bits/stdc++.h>
using namespace std;

const int N = 110, M = 11;
int n, m, ans, w[N], cnt[1 << M], f[2][1 << M][1 << M];
vector<int>state;
vector<int>head[1 << M];
bool check(int st) {
    for (int i = 0; i < m; i++) {
        int x = (st >> i & 1), y = (st >> (i + 1) & 1), z = (st >> (i + 2) & 1);
        if((x && y) || (x && z) || (y && z)) return false;
    }
    return true;
}

int Count(int st) {
    int res = 0;
    for (int i = 0; i < m; i++) res += st >> i & 1;
    return res;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            w[i] += (c == 'H') * (1 << j);
        }
    for (int i = 0; i < 1 << m; i++)
        if(check(i)) state.push_back(i), cnt[i] = Count(i);
    for (auto cur:state)
        for (auto pre:state)
            if(!(cur & pre))
                head[cur].push_back(pre);
    for (int i = 1; i <= n; i++)
        for (auto st:state)
            if(!(st & w[i]))
                for (auto p1:head[st])
                    for (auto p2:head[p1])
                        if(!(st & p2))
                            f[i & 1][st][p1] = max(f[i & 1][st][p1], f[(i - 1) & 1][p1][p2] + cnt[st]);
    for (auto i:state)
        for (auto j:head[i])
            ans = max(ans, f[n & 1][i][j]);
    cout << ans << endl;
    return 0;
}
