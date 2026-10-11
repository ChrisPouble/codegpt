#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, q, w, x, a[maxn], work[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000}; //由于怕计算数量过多，直接打表 
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	while(q--) {
		scanf("%d%d", &w, &x);
		int ans = 20000000;
		for (int i = 1; i <= n; i++)
			if(a[i] - a[i] / work[w] * work[w] == x) ans = min(ans, a[i]); //求答案 
		if(ans == 20000000) puts("-1"); //如果没有答案，输出-1 
		else printf("%d\n", ans);
	}
	return 0;
}
