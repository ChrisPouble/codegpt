//#include <iostream>
//#include <queue>
//using namespace std;
//
//const int maxn = 1e5 * 3 + 5;
//int n, m, e, To[maxn], W[maxn], Begin[maxn], vis[maxn];
//int Next[maxn];
//long long dis[maxn];
//void List(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//class Int {
//public:
//    int id;
//    long long value;
//};
//
//priority_queue<Int>q;
//bool operator<(Int a, Int b) {
//    return dis[a.id] < dis[b.id];
//}
//
//int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w; cin >> u >> v >> w;
//        List(u, v, w);
//    }
//    for (int i = 1; i <= n; i++)
//        dis[i] = 4e14;
//    dis[1] = 0;
//    q.push({ 1, 0 });
//    while (!q.empty()) {
//        Int temp = q.top(); q.pop();
//        if (vis[temp.id] == 1) continue;
//        vis[temp.id] = 1;
//        dis[temp.id] = temp.value;
//        for (int i = Begin[temp.id]; i != 0; i = Next[i]) {
//            int v = To[i], w = W[i];
//            if (dis[temp.id] + w < dis[v]) {
//                dis[v] = dis[temp.id] + w;
//                q.push({ v, dis[v] });
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        if (dis[i] == 4e14) cout << -1 << " ";
//        else cout << dis[i] << " ";
//    }
//    return 0;
//}
///*
//4 5
//1 2 1
//2 3 4
//1 3 3
//4 1 5
//3 1 2
//*/