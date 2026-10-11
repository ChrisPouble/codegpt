#include <bits/stdc++.h>
// #define int int
#define maxn 3010
using namespace std;

int n, ans = -INT_MAX, a[maxn], b[maxn], f[maxn][maxn];
signed main() {
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            f[i][j] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            f[i][j] = f[i - 1][j]; //先考虑不包含a[i]
//            if(a[i] == b[j]) {
//                for (int k = 0; k < j; k++)
//                    if(b[j] > b[k]) f[i][j] = max(f[i][j], f[i - 1][k] + 1);
//            }
//        }
//    }
    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j]) f[i][j] = max(f[i][j], maxv); //在前面的循环中，已经使用maxv算出了f[i-1][k]+1的最大值 
            if(a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1); //在这里，a[i] > b[j]，表示着可以用来更新后面的f值 
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}
