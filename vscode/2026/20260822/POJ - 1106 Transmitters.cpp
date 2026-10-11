#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const double eps = 1e-6;

struct Point { double x, y; };
double r; Point o, P[N], Q[N];

double cross(Point p, Point q) {
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}

double dis(Point p, Point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while (cin >> o.x >> o.y >> r) {
        if (r < 0) return 0;

        int m; cin >> m; int cnt = 0;
        for (int i = 1; i <= m; i++) {
            cin >> P[i].x >> P[i].y;
            if (dis(o, P[i]) - r < eps) Q[++cnt] = P[i];
        }

        int ans = 0;
        for (int i = 1; i <= cnt; i++) {
            int res = 0;
            for (int j = 1; j <= cnt; j++)
                if (cross(Q[i], Q[j]) >= -eps)
                    res++;
            ans = max(ans, res);
        }
        cout << ans << endl;
    }

    return 0;
}