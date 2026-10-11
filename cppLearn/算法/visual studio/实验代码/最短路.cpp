//#include <iostream>
//using namespace std;
//
//int n, m, s, t, e, To[100010], W[100010], Next[100010], Begin[100010], vis[100010];
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//int dfs(int x, int sum) {
//    if (x == t) return sum;
//    int ans = 2e8;
//    for (int i = Begin[x]; i; i = Next[i]) {
//        if (!vis[i]) {
//            vis[i] = true;
//            ans = min(ans, dfs(To[i], sum + W[i]));
//            vis[i] = false;
//        }
//    }
//    return ans;
//}
//
//int main() {
//    cin >> n >> m >> s >> t;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w; cin >> u >> v >> w;
//        add(u, v, w);
//    }
//    int ans = dfs(s, 0);
//    if (ans == 200000000) cout << -1 << endl;
//    else cout << ans << endl;
//    return 0;
//}
///*
//7 9 1 7
//1 2 2
//1 3 5
//2 3 6
//2 4 1
//2 5 3
//4 5 4
//3 6 8
//5 7 9
//6 7 7
//
//14
//*/