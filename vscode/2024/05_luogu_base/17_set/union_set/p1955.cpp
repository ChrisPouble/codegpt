#include<bits/stdc++.h>

#define MAXN 200005
using namespace std;

int T, n, fa[MAXN];
map<int, int> ma;
struct node {
	int x, y, e;
}a[100005];

bool cmp(node x, node y) {
	return x.e > y.e;
}

int find(int x) { //查找 
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) { //合并 
    fa[find(x)] = find(y);
}

void Judge() {
	scanf("%d", &n);
	int cnt = 1;

	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].e);
		if(!ma[a[i].x]) ma[a[i].x] = ++cnt; 
		if(!ma[a[i].y]) ma[a[i].y] = ++cnt;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int x = ma[a[i].x], y = ma[a[i].y];
		if(a[i].e) merge(x, y);
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
		for (int i = 1; i <= MAXN; i++) fa[i] = i;
		Judge();
		ma.clear();
	}
	return 0;
}