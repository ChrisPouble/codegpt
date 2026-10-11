#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 310;

int n, m;
int w[N], l[N], r[N];
int p[N][N][N], f[N][N];
// p[k][i][j] 表示当 k 还没有被吃掉时，[i, j] 中最大的能吃掉 k 的 w（i, j, k 均表示派的下标）
// f[i][j] 表示吃掉 [i, j] 的那些奶牛的最大可能体重（i, j 均表示派的下标）

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> w[i] >> l[i] >> r[i];
        for (int k = l[i]; k <= r[i]; k++)
            p[k][l[i]][r[i]] = w[i];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = k; i >= 1; i--) {
            for (int j = k; j <= n; j++) {
                if (i != 1) p[k][i - 1][j] = max(p[k][i - 1][j], p[k][i][j]);
                if (j != n) p[k][i][j + 1] = max(p[k][i][j + 1], p[k][i][j]);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                int val1 = (k != i ? f[i][k - 1] : 0);
                int val2 = (k != j ? f[k + 1][j] : 0);
                f[i][j] = max(f[i][j], val1 + val2 + p[k][i][j]);
                // 如果存在能吃掉 k，但是会吃掉 [i, j] 以外的奶牛，也不能选，不然会影响到后面的状态
            }
        }
    }

    cout << f[1][n] << endl;

    system("pause");
	return 0;
}