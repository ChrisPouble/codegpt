#include <bits/stdc++.h>
#define maxn 210
using namespace std;

int n, a[maxn * 2], w[maxn * 2][maxn * 2], f[maxn * 2][maxn * 2], g[maxn * 2][maxn * 2], maxans, minans = 1e9;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n - 1; i++)
        if (i % n != 0) a[i] = a[i % n];
        else a[i] = a[n];
    int len = n;
    n = 2 * n + 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
			w[i][j] = w[i][j - 1] + a[j];
    memset(f, 0x3f, sizeof(f));
    for (int i = n; i >= 1; i--) {
        f[i][i] = 0;
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += w[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++)
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j]);
            g[i][j] += w[i][j];
        }
    for (int i = 1; i <= len; i++) {
    	minans = min(minans, f[i][i + len - 1]);
		maxans = max(maxans, g[i][i + len - 1]);
    }
    printf("%d\n%d", minans, maxans);
    return 0;
}
