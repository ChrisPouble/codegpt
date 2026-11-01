#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const int inf = 1e9;

int n, m, a[N][N];
int p[N], q[N];

// 同一列中，候选行 y 从哪一行开始不劣于候选行 x。
// 保证 x < y，只考虑位置 1 ~ n。
int get(int x, int y, int col) {
    int num = a[y][col] + y * y - a[x][col] - x * x;
    int den = 2 * (y - x);

    if (num <= 0) return 1;

    // num > 0，向上取整。
    return (num + den - 1) / den;
}
// 241433214
int main() {
    // freopen("circle.in", "r", stdin);
    // freopen("circle.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 1; j <= m; j++)
            a[i][j] = tmp[j - 1] - '0';
    }

    // a[i][j]：同一行的零点到 (i, j) 的最小距离平方。
    for (int i = 1; i <= n; i++) {
        int last = 0;

        // 考虑左侧零点。
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                last = j;
            } else {
                a[i][j] = last ? (j - last) * (j - last) : inf;
            }
        }

        last = 0;

        // 考虑右侧零点。
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == 0) {
                last = j;
            } else if (last) {
                a[i][j] = min(a[i][j], (last - j) * (last - j));
            }
        }
    }

    int ans = 0;

    for (int j = 1; j <= m; j++) {
        // p[k]：候选行。
        // q[k]：该候选开始最优的位置。
        int top = 0;

        for (int i = 1; i <= n; i++) {
            // 第 i 行没有零点，不能作为候选。
            if (a[i][j] == inf) continue;

            int pos = 1;

            while (top) {
                pos = get(p[top], i, j);

                if (pos <= q[top]) {
                    // 新候选提前取代队尾，队尾已经无用。
                    --top;
                } else {
                    break;
                }
            }

            if (!top) pos = 1;

            // 在矩阵范围内能够成为最优候选，才加入。
            if (pos <= n) {
                p[++top] = i;
                q[top] = pos;
            }
        }

        int head = 1;

        for (int i = 1; i <= n; i++) {
            int dis = inf;

            if (top) {
                while (head < top && q[head + 1] <= i)
                    ++head;

                int x = p[head];
                dis = a[x][j] + (i - x) * (i - x);
            }

            // 圆完全包含在矩阵内。
            int r = min({i - 1, n - i, j - 1, m - j});

            ans = max(ans, min(dis, r * r));
        }
    }

    cout << ans << '\n';

    return 0;
}