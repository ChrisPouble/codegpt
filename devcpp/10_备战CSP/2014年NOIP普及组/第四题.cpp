#include <bits/stdc++.h>
#define maxn 20
#define min(x, y) x < y ? x : y //三目运算符更快
#define inf 1e8
using namespace std;

int n, m, r, c, ans = 1e9, cnthang, a[maxn][maxn], hang[maxn], f[maxn][maxn], h[maxn], l[maxn][maxn];
void mems() {
	memset(h, 0, sizeof(h)); //初始化 
	memset(l, 0, sizeof(l)); //初始化 
	for (int i = 1; i <= m; i++)
		for (int j = 1; j < r; j++)
			h[i] += abs(a[hang[j]][i] - a[hang[j + 1]][i]); //算出这一列所有元素的分值 
	for (int i = 1; i <= m; i++)
		for (int j = i + 1; j <= m; j++) //这里i < j 
			for (int k = 1; k <= r; k++)
				l[i][j] += abs(a[hang[k]][i] - a[hang[k]][j]); //求出第i列与第j列之间, 所有同行元素的差的绝对值的和
}

void dp() {
	mems();
	for (int i = 1; i <= m; i++)
		for (int j = 1, minc = min(i, c); j <= minc; j++) { //先求出j的上限 
			if(j == 1) f[i][j] = h[i]; //边界条件1
			else if(i == j) f[i][j] = f[i - 1][j - 1] + h[i] + l[j - 1][i]; //边界条件2 
			else { //正常情况 
				f[i][j] = inf; //赋上inf 
				for (int k = j - 1; k <= i - 1; k++) //注意k的边界
					f[i][j] = min(f[i][j], f[k][j - 1] + h[i] + l[k][i]);//取最小值
			}
			if(j == c) ans = min(ans, f[i][c]); //存在此状态，则更新最小值 
		}
}

void dfs(int x) { //这里就是枚举行的取法 
	if(cnthang == r) { //取完了
		dp();
		return;
	}
	if(n - h + 1 + cnthang < r) return; //剪枝，如果即使剩下的行全都取了也不能达到r，则return
	hang[++cnthang] = h; //加入行取法数组
	dfs1(h + 1); //下一轮搜索
	hang[cnthang--] = 0; //回溯
	dfs1(h + 1); //不加入
}

signed main() {
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
