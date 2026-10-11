#include <bits/stdc++.h>
using namespace std;

int n, m, fa[20010], b[20010]; //b数组标记敌人 
struct node{
	int x, y, w;
}a[100010];

bool cmp(node x, node y) {
	return x.w > y.w;
}

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merger(int x, int y) {
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

bool check(int x, int y) {
	return find(x) == find(y);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    	fa[i] = i;
    for (int i = 1; i <= m; i++)
    	cin >> a[i].x >> a[i].y >> a[i].w;
    sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if(check(a[i].x, a[i].y)) {
			cout << a[i].w << endl;
			return 0;
		}
		if(!b[a[i].x]) b[a[i].x] = a[i].y; //标记敌人 
		else merger(b[a[i].x], a[i].y); //敌人的敌人是朋友 
		if(!b[a[i].y]) b[a[i].y] = a[i].x;
		else merger(b[a[i].y], a[i].x);
	}
	cout << 0 << endl;	
	return 0;
}
