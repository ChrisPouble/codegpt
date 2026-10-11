#include <bits/stdc++.h>
#define maxn 110
#define inf 0x3f3f3f3f
using namespace std;

int n, m, a[maxn][maxn], f[maxn][maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[maxn][maxn];
struct node {
	int x, y, now, pts, is;
};

void dfs(int x, int y, int sum, bool is) {
	if(sum >= f[x][y]) return; //记忆化搜索 
	f[x][y] = sum; //更新
	if(x == n && y == n) return; //走到终点了，回去 
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && !vis[tx][ty]) { //不能越界，且没有标记过 
			if(a[x][y] == a[tx][ty]) vis[tx][ty] = 1, dfs(tx, ty, sum, 0); //如果两个格子的颜色相同
			else if(a[x][y] != a[tx][ty] && a[tx][ty] != 0) vis[tx][ty] = 1, dfs(tx, ty, sum + 1, 0); //如果两个格子的颜色不同
			else if(a[tx][ty] == 0 && is == 0) vis[tx][ty] = 1, a[tx][ty] = a[x][y], dfs(tx, ty, sum + 2, 1), a[tx][ty] = 0; //如果新格子的颜色为白色，且没有连续使用魔法 
			vis[tx][ty] = 0; //回溯 
		}
	}
}

signed main() {
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, color;
		scanf("%d%d%d", &x, &y, &color);
		a[x][y] = color + 1;
	}
	vis[1][1] = 1; //起始点进行标记 
	dfs(1, 1, 0, 0);
	if(f[n][n] < inf) printf("%d\n", f[n][n]);
	else puts("-1"); //没有答案的情况 
	return 0;
}
