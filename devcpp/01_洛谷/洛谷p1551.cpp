#include <bits/stdc++.h>
using namespace std;

int n, m, p, fa[5010];
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
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) //初始化 
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        merger(x, y); //合并 
    }
    for (int i = 1; i <= p; i++) {
        int x, y; cin >> x >> y;
        if (find(x) != find(y)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
