#include <bits/stdc++.h>
#define maxn 10010
#define N 110
using namespace std;

int n, m, a[maxn], f[N][maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) f[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
    cout << f[n][m] << endl;
	return 0;
}
