#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m, u, v, w, S, s[10010], dis[10010];
bool inQueue[10010]; // 记录节点是否在队列中
struct rake {
    int to, w;
};

vector<rake> linker[10010];
void spfa(int sx) {
    memset(dis, 0x3f, sizeof(dis));
    memset(inQueue, 0, sizeof(inQueue)); // 初始化队列状态
    queue<int> q;
    q.push(sx);
    dis[sx] = 0;
    inQueue[sx] = 1; // 标记初始节点已在队列中
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        inQueue[now] = 0; // 当前节点出队
        for (int i = 0; i < linker[now].size(); i++) {
            int v = linker[now][i].to;
            int w = linker[now][i].w;
            if (dis[v] > dis[now] + w) {
                dis[v] = dis[now] + w;
                if (!inQueue[v]) { // 只有不在队列中的节点才入队
                    q.push(v);
                    inQueue[v] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> S;
    if (n == 0 || m == 0) return 0; // 边界情况处理
    for (int i = 1; i <= S; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        linker[u].push_back({v, w});
    }
    for (int i = 1; i <= S; i++, puts(" ")) {
        spfa(s[i]);
        for (int j = 1; j <= n; j++)
            if (dis[j] == INF) cout << -1 << " ";
            else cout << dis[j] << " ";
    }
    return 0;
}
