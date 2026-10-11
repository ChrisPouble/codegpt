#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[55][55];
int pre[55][55];
bool flag;
char c;

int main() {
    int t;
    cin >> t;
    while (t--) {
        flag = false;
        cin >> n >> m;

        // 读取矩阵数据（处理输入中的空白字符）
        for (int i = 1; i <= n; i++) {
            while (c != '0' && c != '1') c = getchar();
            for (int j = 1; j <= m; j++) {
                a[i][j] = c - '0';
                c = getchar();
            }
        }

        // 计算二维前缀和
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
            }
        }

        // 检查每个1的位置是否符合条件
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 1) {
                    if (pre[i][j] - pre[i][j - 1] != i && pre[i][j] - pre[i - 1][j] != j) {
                        cout << "NO\n";
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }

        if (flag) continue;
        cout << "YES\n";
    }
    return 0;
}