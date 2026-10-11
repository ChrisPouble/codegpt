//#include <iostream>
//#include <queue>
//using namespace std;
//
//int e, To[1501], W[1501], Next[1501];
//int Begin[1501];
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//struct node {
//    int id, value;
//};
//
//bool operator<(node A, node B) {
//    return A.value < B.value;
//}
//
//int dis[1501];
//priority_queue<node> Q;
//bool vis[1501];
//int main() {
//    int n, m; cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w; cin >> u >> v >> w;
//        add(u, v, w);
//    }
//    for (int i = 1; i <= n; i++)
//        dis[i] = -2e8;
//    dis[1] = 0;
//    Q.push({ 1, 0 });
//    while (!Q.empty()) {
//        node temp = Q.top(); Q.pop();
//        int max_id = temp.id;
//        int v = temp.value;
//        if (vis[max_id]) continue;
//        vis[max_id] = true;
//        for (int i = Begin[max_id]; i; i = Next[i]) {
//            int v = To[i], w = W[i];
//            if (dis[v] < dis[max_id] + w) {
//                dis[v] = dis[max_id] + w;
//                Q.push({ v, dis[v] });
//            }
//        }
//    }
//    if (dis[n] == -2e8) cout << -1 << endl;
//    else cout << dis[n] << endl;
//    return 0;
//}