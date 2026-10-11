#include <bits/stdc++.h>
using namespace std;

int T, m, ans, f[110][1010]; //f[i][j]表示前i种草药时间为j时能采摘到达最大价值 
struct node {
	int t, w; //一个草药需要花费时间和得到价值 
}a[110];

int main() {
	cin >> T >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].t >> a[i].w;
	for (int i = 1; i <= m; i++)
		f[i][0] = 0; //初始化 
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= T; j++)
			if(j >= a[i].t) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].t] + a[i].w); //如果时间充足，则需要考虑选或不选 
			else f[i][j] = f[i - 1][j]; //否则不选 
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[i][T]); //找最佳答案 
	cout << ans << endl;
    return 0;
}
