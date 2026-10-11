#include <bits/stdc++.h>
#define int long long
#define maxn 200010 
using namespace std;

int n, ans;
struct node{
	int x, y;
	int xx, yy;
} a[maxn];

bool cmp(node x, node y) {
	return x.yy * y.xx < y.yy * x.xx; 
}

signed main() {
	cin >> n;
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		a[i] = {x, y - 1, x - 1, y}; //存储两个点的坐标 
	}
	sort(a + 1, a + 1 + n, cmp); //排序
	for (int i = 1, l = 0; i <= n; i++)
		if (a[i].y * a[l].xx >= a[l].yy * a[i].x) {
			ans++;
			l = i;
		}
	cout << ans << endl;
	return 0;
}