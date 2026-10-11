#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 10;
int n, s[M][M];
double X, f[M][M][M][M][N];
double get(int x1, int y1, int x2, int y2) {
    double sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1] - X;
    return (double)sum * sum / (double)n;
}

double dp(int x1, int y1, int x2, int y2, int w) {
    if(f[x1][y1][x2][y2][w] >= 0) return f[x1][y1][x2][y2][w];
    if(w == 1) return f[x1][y1][x2][y2][w] = get(x1, y1, x2, y2);
    f[x1][y1][x2][y2][w] = 1e9;
    for (int i = x1; i < x2; i++) {
        f[x1][y1][x2][y2][w] = min(f[x1][y1][x2][y2][w], dp(i + 1, y1, x2, y2, w - 1) + get(x1, y1, i, y2));
        f[x1][y1][x2][y2][w] = min(f[x1][y1][x2][y2][w], dp(x1, y1, i, y2, w - 1) + get(i + 1, y1, x2, y2));
    }
    for (int i = y1; i < y2; i++) {
        f[x1][y1][x2][y2][w] = min(f[x1][y1][x2][y2][w], dp(x1, i + 1, x2, y2, w - 1) + get(x1, y1, x2, i));
        f[x1][y1][x2][y2][w] = min(f[x1][y1][x2][y2][w], dp(x1, y1, x2, i, w - 1) + get(x1, i + 1, x2, y2));
    }
    return f[x1][y1][x2][y2][w];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    X = (double)s[8][8] / (double)n;
    memset(f, -1, sizeof(f));
    printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));
    return 0;
}
