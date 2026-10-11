#include <bits/stdc++.h>
using namespace std;

int n, a[110], f[110][110];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n - 1; i++) f[i][i] = a[i - 1] * a[i] * a[i + 1];
    for (int len = 2; len <= n - 2; len++) //枚举区间长度 
        for (int i = 2; i + len - 1 <= n - 1; i++) { //枚举区间起点 
        	int j = i + len - 1; //计算区间终点 
        	f[i][j] = 0x3f3f3f3f; //初始化 
            for (int k = i; k <= j; k++)
				f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j] + a[i - 1] * a[k] * a[j + 1]); //进行计算，因为中间一部分的卡牌已经被抽掉了，所以左右两边分别为a[i - 1]和a[j + 1] 
        }
    cout << f[2][n - 1] << endl; //答案 
    return 0;
}
