#include <bits/stdc++.h>
#define maxn 100010
#define mod 10007
#define int long long //改成long long,这样只需要在最后 % mod就好了 
using namespace std;

int n, m, ans, cnt[maxn][2], sum[maxn][2]; //cnt[i][j]表示颜色为i,下标[%2=j]的数的数量,sum[i][j]表示颜色为i,下标[%2=j]的数的总和 
struct node {
	int number, color;
}a[maxn];

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].number;
	for (int i = 1; i <= n; i++) cin >> a[i].color;
	for (int i = 1; i <= n; i++) {
		cnt[a[i].color][i & 1]++; //计算数量 
		sum[a[i].color][i & 1] += a[i].number; //计算总和 
	}
	for (int x = 1; x <= n; x++)
		ans += x * ((cnt[a[x].color][x & 1] - 2) * a[x].number + sum[a[x].color][x & 1]); //计算公式 
	cout << ans % mod << endl; //最后答案 % mod 
	return 0;
}
