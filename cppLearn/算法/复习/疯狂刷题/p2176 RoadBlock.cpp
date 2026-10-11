//#include <iostream>
//#include <queue>
//using namespace std;
//
//int N, M, e, To[80], W[80], Begin[80], Next[1510]; long long dis[80], vis[80];
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//struct LongLong {
//    int id;
//    long long value;
//};
//
//bool operator<(LongLong a, LongLong b) {
//    return dis[a.id] > dis[b.id];
//}
//
//priority_queue<LongLong> q;
//long long dijkstra() {
//    for (int i = 1; i <= N; i++)
//        dis[i] = 1e14;
//    for (int i = 1; i <= N; i++)
//        vis[i] = 0;
//    dis[1] = 0;
//    q.push({ 1, 0 });
//    while (!q.empty()) {
//        LongLong temp = q.top(); q.pop();
//        if (vis[temp.id] == true) continue;
//        vis[temp.id] = true;
//        if(temp.value < dis[temp.id]) dis[temp.id] = temp.value;
//        for (int i = Begin[temp.id]; i != 0; i = Next[i]) {
//            int v = To[i], w = W[i];
//            if (dis[temp.id] + w <= dis[v]) {
//                dis[v] = dis[temp.id] + w;
//                q.push({ v, dis[v] });
//            }
//        }
//    }
//    return dis[N];
//}
//
//int main() {
//    cin >> N >> M;
//    for (int i = 1; i <= M; i++) {
//        int u, v, w; cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//    }
//    long long maxt, ans; maxt = ans = dijkstra();
//    for (int i = 1; i <= M * 2; i += 2) {
//        W[i] *= 2;
//        W[i + 1] *= 2;
//        maxt = max(maxt, dijkstra());
//        memset(dis, 0, sizeof(dis));
//        W[i + 1] /= 2;
//        W[i] /= 2;
//    }
//    cout << maxt - ans << endl;
//    return 0;
//}
///*
//5 7
//2 1 5
//1 3 1
//3 2 8
//3 5 7
//3 4 3
//2 4 7
//4 5 2
//*/