#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1 << N;
const double eps = 1e-8;
int n, m, T;
struct node {
    double x, y;
} ver[N];
int path[N][N], f[M];
int cmp(double a, double b) {
    if (fabs(a - b) < eps) return 0;
    if (a > b) return 1;
    return -1;
}

void init() {
    memset(path, 0, sizeof(path));
    for (int i = 0; i < n; i++) {
        path[i][i] = 1 << i;
        for (int j = 0; j < n; j++) {
            double x1 = ver[i].x, y1 = ver[i].y;
            double x2 = ver[j].x, y2 = ver[j].y;
            if (!cmp(x1, x2)) continue;  //单独一个点无法生成参数a,b的抛物线
            double a = (y1 / x1 - y2 / x2) / (x1 - x2);
            double b = (y1 / x1) - a * x1;
            if (cmp(a, 0.0) >= 0) continue;
            //参数a,b的抛物线已生成，枚举他经过的所有点
            for (int k = 0; k < n; k++) {
                double x = ver[k].x, y = ver[k].y;
                if (!cmp(y, a * x * x + b * x)) path[i][j] += 1 << k;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ver[i].x >> ver[i].y;
    init();
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int cur_st = 0; cur_st + 1 < (1 << n); cur_st++) {
        int t = -1;
        for (int i = 0; i < n; i++)
            if (!(cur_st >> i & 1))
                t = i;
        for (int i = 0; i < n; i++) {
            int ne_st = path[t][i] | cur_st;
            f[ne_st] = min(f[ne_st], f[cur_st] + 1);
        }
    }
    cout << f[(1 << n) - 1] << endl;
}

int main() {
    cin >> T;
    while (T--) solve();
    return 0;
}
