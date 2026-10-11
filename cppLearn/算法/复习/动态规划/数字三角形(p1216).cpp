#include <iostream>
using namespace std;

int n, a4[1005][1005], f[1005][1005];
//int dfs(int x, int y) {
//    if (f[x][y] != -1) return f[x][y];
//    if (y == 1) return f[x][y] = dfs(x - 1, y) + a4[x][y];
//    else if (x == y) return f[x][y] = dfs(x - 1, y - 1) + a4[x][y];
//    return f[x][y] = max(dfs(x - 1, y), dfs(x - 1, y - 1)) + a4[x][y];
//}
//
//int main() {
//    memset(f, -1, sizeof(f));
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= i; j++)
//            cin >> a4[i][j];
//    int ans = -1;
//    f[1][1] = a4[1][1];
//    for (int i = 1; i <= n; i++)
//        ans = max(ans, dfs(n, i));
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}
//int main() {
//    cin >> n;
//    memset(f, -1, sizeof(f));
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= i; j++)
//            cin >> a4[i][j];
//    
//    f[1][1] = a4[1][1];
//    for (int i = 1; i < n; i++)
//        for (int j = 1; j <= i; j++) {
//            f[i + 1][j] = max(f[i + 1][j], f[i][j] + a4[i + 1][j]);
//            f[i + 1][j + 1] = max(f[i + 1][j + 1],
//                f[i][j] + a4[i + 1][j + 1]);
//        }
//
//    int ans = -1;
//    for (int i = 1; i <= n; i++)
//        ans = max(ans, f[n][i]);
//    
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}