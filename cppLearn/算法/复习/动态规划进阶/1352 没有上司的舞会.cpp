//关于树的动态规划
#include <iostream>
using namespace std;

const int maxn = 6e3 + 5;
int n, m, ans, e, Begin[maxn], To[maxn], Next[maxn], r[maxn];
int f[maxn][2], deg[maxn], fa[maxn];
void dfs(int x) {
    int nxt;
    for (int i = Begin[x]; i; i = Next[i]) {
        nxt = To[i];
        dfs(nxt);
        f[x][0] += max(f[nxt][0], f[nxt][1]); //如果绝对上司没来，那么比较员工是来好一点还是不来好一点
        f[x][1] += f[nxt][0]; //如果绝对上司来了，那么员工一定不能来
    }
    f[x][1] += r[x]; //如果来了，那么自己的快乐指数也要加上
}

void add(int u, int v) {
    e++;
    To[e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
    fa[v] = u;
    deg[u]++;
}  

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        add(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!fa[i]) {
            dfs(i);
            ans = max(f[i][0], f[i][1]);
            break;
        }
    cout << ans << endl;
    return 0;
}