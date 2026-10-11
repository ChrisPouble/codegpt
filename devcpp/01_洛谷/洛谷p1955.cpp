#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

int T, n, fa[maxn];
map<int, int>ma;
struct node {
	int x, y, e;
}a[maxn];

bool cmp(node x, node y) {
	return x.e > y.e;
}

int find(int x) { //≤È’“ 
	if(x == fa[x]) return x;
	else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}

void merger(int x, int y) { //∫œ≤¢ 
	int xx = find(x), yy = find(y);
	if(xx != yy) fa[xx] = yy;
}

void Judge() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].e);
		if(!ma[a[i].x]) ma[a[i].x] = ++cnt; 
		if(!ma[a[i].y]) ma[a[i].y] = ++cnt;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int x = ma[a[i].x], y = ma[a[i].y];
		if(a[i].e) merger(x, y);
		else {
			if(find(x) == find(y)) {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

int main() {
	scanf("%d", &T);
	while(T--) {
		for (int i = 1; i <= maxn; i++) fa[i] = i;
		Judge();
	}
	return 0;
}
