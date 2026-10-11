#include <bits/stdc++.h>
using namespace std;

int n, ans = 100000010;
bool vis[110];
struct node{
	int left, right, father, val;
}t[110];

int dfs(int x, int d) { //x表示节点坐标，d表示离指定节点的距离 
	if(!x || vis[x]) return 0; //如果不存在x或x已经访问过就返回 
	vis[x] = 1;
	return dfs(t[x].left, d + 1) + dfs(t[x].right, d + 1) + dfs(t[x].father, d + 1) + t[x].val * d;
	//一个节点的值等于左子树的值加右子树的值加父亲节点的值加自己 
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int w, u, v; cin >> w >> u >> v;
		t[i].left = u;
		t[i].right = v;
		t[i].val = w;
		t[t[i].left].father = i;
		t[t[i].right].father = i;
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		ans = min(ans, dfs(i, 0));
	}
	cout << ans << endl;
    return 0;
}
