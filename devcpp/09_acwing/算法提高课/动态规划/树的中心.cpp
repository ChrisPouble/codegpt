#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

struct edge {
    int to, w;
};

int n, ans = 1e9, d1[maxn], d2[maxn], p1[maxn], p2[maxn], up[maxn];
vector<edge> linker[maxn];
int dfs(int x, int fa) {
	d1[x] = d2[x] = -1e9;
    for (auto i:linker[x]) {
        int son = i.to, w = i.w;
        if(son == fa) continue;
        int dist = dfs(son, x) + w;
        if(dist > d1[x]) { //更新一下最长和第二长的路径，并记录下从该路径是从哪一个点下去的
            d2[x] = d1[x], d1[x] = dist;
            p2[x] = p1[x], p1[x] = son;
        } else if(dist > d2[x]) {
            d2[x] = dist;
            p2[x] = son;
        }
    }
    if(d1[x] == -1e9) d1[x] = d2[x] = 0; //如果没有改变过该点的距离，就证明这个点是叶节点
    return d1[x];
}

void dep(int x, int fa) {
	for (auto i:linker[x]) {
        int son = i.to, w = i.w;
        if(son == fa) continue;
        if(p1[x] == son) up[son] = max(up[x], d2[x]) + w; //这条路径上已经走过了 
        else up[son] = max(up[x], d1[x]) + w; //这个没有 
        dep(son, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1, x, y, w; i < n; i++) cin >> x >> y >> w, linker[x].push_back({y, w}), linker[y].push_back({x, w});
	dfs(1, 0), dep(1, 0);
	for (int i = 1; i <= n; i++) ans = min(ans, max(d1[i], up[i]));
    cout << ans << endl;
    return 0;
}
