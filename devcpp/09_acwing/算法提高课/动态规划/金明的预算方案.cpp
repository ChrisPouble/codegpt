#include <bits/stdc++.h>
#define maxn 70
#define maxm 32010
using namespace std;

int n, m, f[maxm];
struct node {
    int v, w;
} master[maxn];
vector<node>linker[maxn];
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        p *= v;
        if(!q) master[i] = {v, p};
        else linker[q].push_back({v, p});
    }
    for (int i = 1; i <= n; i++) {
        int siz = linker[i].size();
        for (int u = m; u >= 0; u--)
            for (int j = 0; j < (1 << siz); j++) {
                int v = master[i].v, w = master[i].w;
                for (int k = 0; k < siz; k++)
                    if(j >> k & 1) {
                        v += linker[i][k].v;
                        w += linker[i][k].w;
                    }
                if(u >= v) f[u] = max(f[u], f[u - v] + w);
            }
    }
    cout << f[m] << endl;
    return 0;
}
