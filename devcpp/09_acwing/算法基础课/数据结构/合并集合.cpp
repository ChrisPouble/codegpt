#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, ans, fa[maxn];
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
    for (int i = 1; i <= n; i++) //初始化 
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
    	string opt;
        int x, y;
		cin >> opt >> x >> y;
        if(opt == "M") merger(x, y);
        else cout << (find(x) == find(y) ? "Yes" : "No") << "\n";
    }
    return 0;
}
