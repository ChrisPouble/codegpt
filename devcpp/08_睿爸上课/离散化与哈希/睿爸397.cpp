#include <bits/stdc++.h>
#define maxn 20010
using namespace std;

int n, ans;
struct node {
	int l, r, a, b, c;
}w[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d", &w[i].l, &w[i].r, &w[i].a, &w[i].b, &w[i].c);
		w[i].l *= 2, w[i].r *= 2, w[i].a *= 2, w[i].b *= 2, w[i].c *= 2; //扩大两倍 
	}
	for (int i = 0; i <= maxn; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++)
			if(w[j].l <= i && w[j].r >= i) sum += w[j].a; //适宜温度 
			else if(w[j].r < i) sum += w[j].b; //超出上限 
			else if(w[j].l > i) sum += w[j].c; //低处下限 
		ans = max(ans, sum); //找最大值 
	}
	printf("%d\n", ans / 2); //最后要变回原来的数量 
	return 0;
}
