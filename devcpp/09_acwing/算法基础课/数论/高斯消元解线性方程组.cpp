#include <bits/stdc++.h>
#define int long long
#define maxn 110
#define eps 1e-6
using namespace std;

int n;
double a[maxn][maxn];
int solve() {
	int c = 1, r = 1;
	for (; c <= n; c++) {
		int t = r;
		for (int i = r; i <= n; i++)
			if(fabs(a[i][c]) > fabs(a[t][c])) t = i; //寻找绝对值最大 
		if(fabs(a[t][c]) < eps) continue; //代表这一列已经被处理过了 
		for (int i = c; i <= n + 1; i++) swap(a[t][i], a[r][i]); //换到上面 
		for (int i = n + 1; i >= c; i--) a[r][i] /= a[r][c]; //这行置为1 
		for (int i = r + 1; i <= n; i++)
			if(fabs(a[i][c]) > eps) {
				for (int j = n + 1; j >= c; j--) //必须从后往前，否则a[i][c]会改变 
					a[i][j] -= a[r][j] * a[i][c]; //置零过程，结合图片思考 
			}
		r++; //下一行 
	}
// 	for (int i = 1; i <= n; i++, puts(""))
// 		for (int j = 1; j <= n + 1; j++)
// 			printf("%.2f ", a[i][j]);
	if(r <= n) { //没有唯一解
		for (int i = r; i <= n; i++)
			if(fabs(a[i][n + 1]) > eps) return 1; //如果左边为0，右边不为0，说明无解 
		return 2; //否则说明有无数解 
	}
	for (int i = n; i >= 1; i--) //从下往上回代 
        for (int j = i + 1; j <= n; j++) //这一行和下一行是为了把i+1~n的所有项之和算出来，且让等号右边减去这一项 
            a[i][n + 1] -= a[j][n + 1] * a[i][j]; //由于系数已经化为1了，因此可以直接得到解
    return 0;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			cin >> a[i][j];
	int ans = solve();
	if(ans == 1) cout << "No solution" << endl;
	else if(ans == 2) cout << "Infinite group solutions" << endl;
	else for (int i = 1; i <= n; i++) printf("%.2f\n", a[i][n + 1]);
	return 0;
}
