#include <bits/stdc++.h>
using namespace std;

const int N = 1510;
int n, f[N][3], w[N];
vector<int>linker[N];
bool st[N];
void add(int a, int b) {
    linker[a].push_back(b);
}

void dfs(int u) {
    f[u][0] = 0;
    f[u][1] = 1e9; //f[u][1]求最小值，初始化为最大值
    f[u][2] = w[u]; //初始化放置自己的代价
    for (auto i:linker[u]) {
        dfs(i);
        f[u][0] += min(f[i][1], f[i][2]);
        f[u][2] += min(min(f[i][0], f[i][1]), f[i][2]);
    }
    for (auto i:linker[u])
        f[u][1] = min(f[u][1], f[u][0] + f[i][2] - min(f[i][1], f[i][2]));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id, cnt, cost;
        cin >> id >> cost >> cnt;
        w[id] = cost;
        while (cnt--) {
            int ver;
            cin >> ver;
            add(id, ver);
            st[ver] = true;
        }
    }
    int root = 1;
    while (st[root]) root++;
    dfs(root);
    printf("%d\n", min(f[root][1], f[root][2]));
    return 0;
}
