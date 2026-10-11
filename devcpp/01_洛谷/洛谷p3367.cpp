#include <bits/stdc++.h>
using namespace std;

int n, m, fa[10010], rnk[10010];
int find(int x) { //查找 
    if (x == fa[x]) return x;
    else return find(fa[x]);
}

void merger(int x, int y) {
    int xx = find(x), yy = find(y);
    if (fa[xx] == yy) return;
    if (rnk[xx] > rnk[yy]) swap(xx, yy); //安置合并 
    fa[xx] = yy;
    if(rnk[xx] == rnk[yy]) rnk[yy]++; //高度增加 
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int z, x, y; cin >> z >> x >> y;
        if (z == 1) merger(x, y);
        else if(z == 2) {
            if (find(x) == find(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return 0;
}
