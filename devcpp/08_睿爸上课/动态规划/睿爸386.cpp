#include <bits/stdc++.h>
using namespace std;

int n, r, pre[1010], f[1010][1010][2]; //f[i][j][0]表示当徐老师送完i~j之间的所有外卖后，他所在的点在i点上所需要的最短时间，f[i][j][1]则表示它所在的点在j点上所需要的最短时间
struct people{
	int x, angry; //坐标和不满系数 
}a[1010];

bool cmp(people x, people y) {
	return x.x < y.x;
}

int main() {
	cin >> n >> r;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].angry;
	a[++n] = {r, 0}; //别人不点外卖，我点！直接在徐老师的出发点点一个外卖，那么就不用担心待会数组全为 0x3f3f3f3f 的情况了 
	sort(a + 1, a + n + 1, cmp); //按坐标排序 
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].angry; //求出不满系数的前缀和 
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++)
		if(a[i].x == r) f[i][i][0] = f[i][i][1] = 0; //如果就在起点点了外卖，那么只需要 
	for (int len = 2; len <= n; len++) //枚举区间长度 
		for (int i = 1; i + len - 1 <= n; i++) { //枚举区间起点 
			int j = i + len - 1; //计算终点
			//下面自己慢慢理解加消化一下...... 
			f[i][j][0] = min(f[i + 1][j][0] + (a[i + 1].x - a[i].x) * (pre[i] + pre[n] - pre[j]), f[i + 1][j][1] + (a[j].x - a[i].x) * (pre[i] + pre[n] - pre[j]));
			f[i][j][1] = min(f[i][j - 1][0] + (a[j].x - a[i].x) * (pre[i - 1] + pre[n] - pre[j - 1]), f[i][j - 1][1] + (a[j].x - a[j - 1].x) * (pre[i - 1] + pre[n] - pre[j - 1]));
		}
	cout << min(f[1][n][0], f[1][n][1]) << endl; //答案 
	return 0;
}
