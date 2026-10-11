#include <bits/stdc++.h>
#define maxn 110
using namespace std;

struct edge {
    int v, len;
};

vector<edge> linker[maxn];
int n, Q, f[maxn][maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

void dfs(int x, int fa) {
    int lc = 0, rc = 0, lv = 0, rv = 0;
    for (auto k:linker[x]) {
        int to = k.v, w = k.len;
        if(to == fa) continue;
        if(lc) rc = to, rv = w;
        else lc = to, lv = w;
        dfs(to, x);
    }
    if(!lc || !rc) return;
    for (int i = 1; i <= Q; i++) {
        for (int j = i; j >= 0; j--) {
            int tmp = 0;
            if(j >= 1) tmp += lv;
            if(i - j >= 1) tmp += rv;
            f[x][i] = max(f[x][i], f[lc][j - 1] + f[rc][i - j - 1] + tmp);
        }
    }
}

int main() {
    cin >> n >> Q;
    for (int i = 1, x, y, w; i < n; i++) {
        cin >> x >> y >> w;
        add(x, y, w), add(y, x, w);
    }
    dfs(1, 0);
    cout << f[1][Q] << endl;
    return 0;
}
