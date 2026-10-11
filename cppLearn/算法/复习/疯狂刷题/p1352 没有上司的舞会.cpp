//#include <iostream>
//using namespace std;
//
//int n, ans, a[6010], f[6010][2];
//int e, To[6010], Begin[6010], Next[6010], Deg[6010], Fa[6010];
//void dfs(int x) {
//    for (int i = Begin[x]; i; i = Next[i]) {
//        int nxt = To[i];
//        dfs(nxt);
//        f[x][0] += max(f[nxt][0], f[nxt][1]);
//        f[x][1] += f[nxt][0];
//    }
//    f[x][1] += a[x];
//}
//
//void add(int u, int v) {
//    e++;
//    To[e] = v;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//    Fa[v] = u;
//    Deg[u]++;
//}
//
//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    for (int i = 1; i < n; i++) {
//        int l, k; cin >> l >> k;
//        add(k, l);
//    }
//    for (int i = 1; i <= n; i++) {
//        if (!Fa[i]) {
//            dfs(i);
//            ans = max(f[i][0], f[i][1]);
//            break;
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
///*
//7
//1
//1
//1
//1
//1
//1
//1
//2 1
//3 1
//4 2
//5 2
//6 3
//7 3
//*/