//#include <iostream>
//#include <queue>
//using namespace std;
//
//int e, To[1000001], W[1000001], Next[1000001];
//int Begin[1000001];
//int n, m; 
//long long ans;
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//struct node{
//    int id;
//    long long value;
//};
//
//struct edge {
//    int u, v;
//    long long w;
//}E[1000001];
//
//priority_queue<node>Q;
//long long dis[100001];
//bool vis[100001];
//
//bool operator<(node A, node B) {
//    return A.value > B.value;
//}
//
//int Dijkstra(int s) {
//    memset(vis, false, sizeof(vis));
//    long long answer = 0;
//    for (int i = 1; i <= n; i++)
//        dis[i] = 2e9;
//    dis[s] = 0;
//    Q.push({ s, 0 });
//
//    while (!Q.empty()) {
//        node temp = Q.top(); Q.pop();
//        int min_id = temp.id;
//        long long v = temp.value;
//        if (vis[min_id]) continue;
//        vis[min_id] = true;
//
//        for (int i = Begin[min_id]; i; i = Next[i]) {
//            int v = To[i]; long long w = W[i];
//            if (dis[v] > dis[min_id] + w) {
//                dis[v] = dis[min_id] + w;
//                Q.push({ v, dis[v] });
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++)
//        answer += dis[i];
//    return answer;
//}
//
//int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        add(u, v, w);
//        E[i].u = u, E[i].v = v, E[i].w = w;
//    }
//    ans += Dijkstra(1);
//    e = 0;
//    memset(Begin, 0, sizeof(Begin));
//    memset(Next, 0, sizeof(Next));
//    memset(To, 0, sizeof(To));
//    memset(W, 0, sizeof(W));
//    memset(dis, 0, sizeof(dis));
//    for (int i = 1; i <= m; i++) {
//        long long u = E[i].u, v = E[i].v, w = E[i].w;
//        add(v, u, w); //µßµ¹·½Ïò
//    }
//    ans += Dijkstra(1);
//    cout << ans << endl;
//    return 0;
//}
///*
//4 6
//1 2 10
//2 1 60
//1 3 20
//3 4 10
//2 4 5
//4 1 50
//*/