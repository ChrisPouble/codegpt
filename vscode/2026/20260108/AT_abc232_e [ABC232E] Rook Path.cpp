#include <bits/stdc++.h>
#define int long long
#define maxn 1000010
#define mod 998244353
using namespace std;

int n, m, k, xx1, yy1, xx2, yy2;
int f[maxn][4];
/*
f[i][0]在终点
f[i][1]不在坐标轴上
f[i][2]在xx2轴上
f[i][3]在yy2轴上
*/
signed main() {
    cin >> n >> m >> k >> xx1 >> yy1 >> xx2 >> yy2;
    if (xx1 == xx2 && yy1 == yy2)
        f[0][0] = 1;
    else if (xx1 != xx2 && yy1 != yy2)
        f[0][1] = 1;
    else if (xx1 == xx2 && yy1 != yy2)
        f[0][2] = 1;
    else if (xx1 != xx2 && yy1 == yy2)
        f[0][3] = 1;
    for (int i = 1; i <= k; i++) {
        f[i][0] = f[i - 1][2] + f[i - 1][3];
        f[i][1] = f[i - 1][1] * (n + m - 4) + f[i - 1][2] * (n - 1) + f[i - 1][3] * (m - 1);
        f[i][2] = f[i - 1][0] * (m - 1) + f[i - 1][2] * (m - 2) + f[i - 1][1];
        f[i][3] = f[i - 1][0] * (n - 1) + f[i - 1][3] * (n - 2) + f[i - 1][1];
        f[i][0] %= mod, f[i][1] %= mod, f[i][2] %= mod, f[i][3] %= mod;
    }
    cout << f[k][0] << endl;
    return 0;
}