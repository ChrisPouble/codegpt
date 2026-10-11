#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int r, a[maxn][maxn], f[maxn][maxn];
int main() {
    cin >> r;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    for (int i = 1; i <= r; i++)
        f[r][i] = a[r][i];
    for (int i = r - 1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
    cout << f[1][1];
    return 0;
}
