#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, ans, fa[maxn], siz[maxn];
int find(int x) { //查询 
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

void merger(int x, int y) { //合并 
    int xx = find(x), yy = find(y);
    if (xx != yy) fa[xx] = yy, siz[yy] += siz[xx];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) //初始化 
        fa[i] = i, siz[i] = 1;
    for (int i = 1; i <= m; i++) {
    	string opt;
        int x, y;
		cin >> opt;
        if(opt == "C") cin >> x >> y, merger(x, y);
        else if(opt == "Q1") cin >> x >> y, cout << (find(x) == find(y) ? "Yes" : "No") << "\n";
        else cin >> x, cout << siz[find(x)] << "\n";
    }
    return 0;
}
