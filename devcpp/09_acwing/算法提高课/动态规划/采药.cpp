#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int T, m, ans, f[maxn][maxn];
struct node {
	int t, w;
} a[maxn];

int main() {
	cin >> T >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].t >> a[i].w;
	for (int i = 1; i <= m; i++)
		f[i][0] = 0; //初始化 
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= T; j++)
			if(j >= a[i].t) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].t] + a[i].w); //找到最大值 
			else f[i][j] = f[i - 1][j];
	cout << f[m][T] << endl;
    return 0;
}
