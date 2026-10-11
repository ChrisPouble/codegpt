#include <bits/stdc++.h>
using namespace std;

int n, m, fa[1000010];
int find(int x) { //查询
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) { //合并
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

int main() {
	while(cin >> n) {
		if(n == 0) break;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			fa[i] = i; //初始化
		cin >> m;
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			merge(x, y);
		}
		for (int i = 1; i <= n; i++)
			if(fa[i] == i) ans++;
		cout << ans - 1 << endl; //最后只能有一个联通块 
	}
	return 0;
}
