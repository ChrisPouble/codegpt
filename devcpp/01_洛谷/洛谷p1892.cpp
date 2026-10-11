#include <bits/stdc++.h>
using namespace std;

int n, m, ans, fa[2010];
bool vis[2010];
int find(int x) { //查询 
    if (x == fa[x]) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merger(int x, int y) { //合并 
    int xx = find(x), yy = find(y);
    if (xx != yy) fa[xx] = yy;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++) //初始化 
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
    	char opt;
        int x, y;
		cin >> opt >> x >> y;
        if(opt == 'F') merger(x, y);
        else {
        	merger(x + n, y);
        	merger(x, y + n);
		}
    }
    for (int i = 1; i <= n; i++)
    	if(vis[find(i)] == 0) vis[find(i)] = 1, ans++;
    cout << ans << endl;
    return 0;
}
