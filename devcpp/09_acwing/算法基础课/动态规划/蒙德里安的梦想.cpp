#include <bits/stdc++.h>
#define maxn 12
#define int long long
using namespace std;

int n, m, f[maxn][1 << maxn];
bool st[1 << maxn];
void solve() {
    memset(st, 0, sizeof(st));
    memset(f, 0, sizeof(f));
    for (int i = 0; i < 1 << n; i++) { //枚举合法方案
        int cnt = 0;
        st[i] = 1;
        for (int j = 0; j < n; j++) {
            if(i >> j & 1) {
                if(cnt & 1) st[i] = 0;
                cnt = 0;
            }
            else cnt++;
        }
        if(cnt & 1) st[i] = 0;
    }
    f[0][0] = 1; //这里需要回忆状态表示的定义
    //按定义这里是：前第-1列都摆好，且从-1列到第0列伸出来的状态为0的方案数。
    //首先，这里没有-1列，最少也是0列。
    //其次，没有伸出来，即没有横着摆的。即这里第0列只有竖着摆这1种状态。
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 1 << n; j++)
            for (int k = 0; k < 1 << n; k++)
                if ((j & k) == 0 && st[j | k]) f[i][j] += f[i - 1][k];
    cout << f[m][0] << endl;
}

signed main() {
    while(cin >> n >> m, n || m) solve();
    return 0;
}
