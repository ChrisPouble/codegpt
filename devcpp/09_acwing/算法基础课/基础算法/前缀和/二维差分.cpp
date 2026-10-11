#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m, q, s[maxn][maxn], a[maxn][maxn];
void insert(int x1, int y1, int x2, int y2, int c) {
	s[x1][y1] += c; //这里加上 
	s[x2 + 1][y1] -= c; //进行补丁 
	s[x1][y2 + 1] -= c; //进行补丁 
	s[x2 + 1][y2 + 1] += c; //由于上面减了两次，这里要加回来 
}

int main() { 
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);
	while(q--) {
		int x1, x2, y1, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
	for (int i = 1; i <= n; i++, puts(""))
		for (int j = 1; j <= m; j++)
			cout << s[i][j] << " ";
	return 0;
}
