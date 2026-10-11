#include <bits/stdc++.h>
using namespace std;

int n, ans, a[410][410];
int jss(int x1, int y1, int x2, int y2) {
    int sum = 0;
    //for (int i = x1, j = y1; i <= x2 && j <= y2; i++, j++) sum += a[i][j];
    for (int i = x1, j = y2; i <= x2 && j >= y1; i++, j--) sum -= a[i][j];
    return sum;
}

int js(int x, int y) {
    int maxt = 0, zs = a[x][y];
    for (int i = x + 1, j = y + 1; i <= n && j <= n; i++, j++) {
    	zs += a[i][j];
    	int t = zs + jss(x, y, i, j);
		maxt =  t > maxt ? t : maxt;
	}
    return maxt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
			cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) 
			ans = js(i, j) > ans ? js(i, j) : ans;
    printf("%d", ans);
    return 0;
}
