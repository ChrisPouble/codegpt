//#include <iostream>
//#include <vector>
//using namespace std;
//
//const int maxn = 105;
//int n, m; //n代表有几个点，m代表有几条边
//vector<int> G[maxn], W[maxn];
//bool vis[maxn];
//void add(int x, int y, int z) {
//    G[x].push_back(y);
//    W[x].push_back(z);
//}
//
//void dfs(int x, int dis) {
//    cout << "现在走到点" << x << "用的距离为：" << dis << endl;
//    for (int i = 0; i < G[x].size(); i++) {
//        int u = G[x][i];
//        int v = W[x][i];
//        if (!vis[u]) {
//            vis[u] = true;
//            dfs(u, dis + v);
//            vis[u] = false;
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    int x, y, z;
//    for (int i = 0; i < m; i++) {
//        cin >> x >> y >> z;
//        add(x, y, z);
//    }
//    dfs(1, 0);
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//const int maxn = 105, maxe = 1e6 + 5;
//int n, m; //n代表有几个点，m代表有几条边
//int To[maxe], W[maxe], Next[maxe], e;
//int Begin[maxn];
//bool vis[maxn];
//void add(int x, int y, int z) {
//    e++;
//    To[e] = y;
//    W[e] = z;
//    Next[e] = Begin[x];
//    Begin[x] = e;
//}
//
//void dfs(int x, int dis, int def) {
//    if (def > 1) return;
//    cout << "现在走到点" << x << "用的距离为：" << dis << endl;
//    for (int i = Begin[x]; i; i = Next[i]) {
//        int u = To[i];
//        int v = W[i];
//        if (!vis[u]) {
//            vis[u] = true;
//            dfs(u, dis + v, def + 1);
//            vis[u] = false;
//        }
//    }
//}
//
//int main() {
//    cin >> n >> m;
//    int x, y, z;
//    for (int i = 0; i < m; i++) {
//        cin >> x >> y >> z;
//        add(x, y, z);
//    }
//    dfs(1, 0, 0);
//    return 0;
//}