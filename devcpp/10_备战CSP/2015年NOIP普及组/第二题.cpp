#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, m, ans[maxn][maxn]; //最后的答案
char a[maxn][maxn]; //输入的矩阵 
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}; //方位数组 
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '*') //如果这个地方是雷
                for (int k = 0; k < 8; k++) { //遍历八个方向 
                	int x = i + dx[k], y = j + dy[k]; //找到附近的位置 
                	if (a[x][y] != '*') ans[x][y]++; //如果附近不是雷，则答案+1 
				}
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            if(a[i][j] != '*') cout << ans[i][j]; //注意这个地方不能有雷 
            else cout << '*';
    return 0;
}
