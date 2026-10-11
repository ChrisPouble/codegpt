#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

struct edge {
    int to, w;
};

int n, ans = -1e9, dis[maxn], f[maxn][2];
vector<edge> linker[maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

void dfs(int x, int fa) {
    for (auto v:linker[x])
        if(v.to != fa) dfs(v.to, x);
    for (auto v:linker[x]) {
        int son = v.to, w = v.w;
        if(son == fa) continue;
        if(f[son][0] + w >= f[x][0]) f[x][1] = f[x][0], f[x][0] = f[son][0] + w;
        else if(f[son][0] + w > f[x][1]) f[x][1] = f[son][0] + w;
    }
    ans = max(ans, f[x][0] + f[x][1]);
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w), add(y, x, w);
    }
    dfs(1, 0);
	cout << ans << endl;
	return 0;
}
