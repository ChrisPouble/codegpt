#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long

ld f[25][1 << 18], ans = 1e18;
int n, m, x[25], y[25];

ld get(int x1, int yy1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (yy1 - y2) * (yy1 - y2));
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n + m; i++)
        cin >> x[i] >> y[i];

    int mst = (1 << (n + m));
    for (int i = 0; i < n + m; i++)
           for (int s = 0; s < mst; s++)
            f[i][s] = 1e18;

    for (int i = 0; i < n + m; i++)
        f[i][1 << i] = get(0, 0, x[i], y[i]);

    for (int s = 1; s < mst; s++) {
        ld v = (1ll << (__builtin_popcount(s >> n)));
        for (int i = 0; i < n + m; i++) {
            if (!(s & (1 << i))) continue;
            for (int j = 1; j <= n + m; j++) {
                if (!(s & (1 << j))) {
                    f[j][s | (1 << j)] = min(f[j][s | (1<< j)], f[i][s] + dis(x[i], y[i], x[j], y[j]) / v);
                }
            }
        }
    }

    for (int i = 0; i < n + m; i++) {
        for (int s = (1 << n) - 1; s < mst; s += (1 << n)) {
		    ld v = (1ll << (__builtin_popcount(s >> n)));
		    ans = min(ans, f[i][s] + dis(0, 0, x[i], y[i]) / v);
	    }
    }

    printf("%.7Lf", ans);

    return 0;
}