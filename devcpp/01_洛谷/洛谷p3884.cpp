#include <bits/stdc++.h>
using namespace std;

int n, num[110];
bool vis[110];
struct node {
	int left, right, val, father, cs;
}ecs[140];

int dfs1(int x) {
	if(!x) return 0; //这个点不存在就return 0 
	return max(dfs1(ecs[x].right), dfs1(ecs[x].left)) + 1; //遍历左子树和右子树 
}

int bfs2() {
	int ans = 0;
	queue<node>q;
	q.push({ecs[1].left, ecs[1].right, 1, 0, 1}); //初始化 
	ecs[1].cs = 1;
	while(!q.empty()) {
		int l = q.front().left;
		int r = q.front().right;
		int v = q.front().val;
		int c = q.front().cs;
		q.pop();
		if(l) { //把左节点加入队列 
			q.push({ecs[l].left, ecs[l].right, l, v, c + 1});
			ecs[l].cs = c + 1;
		}
		if(r) { //把右节点加入队列
			q.push({ecs[r].left, ecs[r].right, r, v, c + 1});
			ecs[r].cs = c + 1;
		}
	}
	for (int i = 1; i <= n; i++)
		num[ecs[i].cs]++; //记录层数 
	for (int i = 1; i <= n; i++)
		ans = max(ans, num[i]); //寻找答案 
	return ans;
} 

int dfs3(int x, int y, int sum) {
	if(!x || vis[x]) return 0; //如果此节点不存在或者已经被访问过就return 0 
	vis[x] = 1; //标记 
	if(x == y) return sum; //找到了 
	return max(max(dfs3(ecs[x].left, y, sum + 1), dfs3(ecs[x].right, y, sum + 1)), dfs3(ecs[x].father, y, sum + 2)); 
	//遍历左子树、右子树、父节点 
}

int main() {
	int x, y;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		ecs[v].father = u;
		if(ecs[u].left) ecs[u].right = v;
		else ecs[u].left = v;
		ecs[u].val = u;
	}
	cin >> x >> y;
	cout << dfs1(1) << endl;
	cout << bfs2() << endl;
	cout << dfs3(x, y, 0) << endl;
	return 0;
}
