//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int e, q, a[40003], To[40003], W[40003], Next[40003], Begin[10001];
//int n, m, s, t;
//bool vis[10001], vi[40003];
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//bool dfs(int x, int h) {
//    if (x == t) return true;
//    vi[x] = true;
//    for (int i = Begin[x]; i; i = Next[i]) {
//        if (!vi[To[i]]) {
//            if (W[i] <= h) {
//                if (dfs(To[i], h)) return true;
//            }
//        }
//    }
//    return false;
//}
//
//int main() {
//    cin >> n >> m >> s >> t;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//        if (!vis[w]) {
//            vis[w] = true;
//            a[++q] = w;
//        }
//    }
//    sort(a + 1, a + m + 1);
//    int l = 1, r = m, mid;
//    int flagf = 0;
//    while (l <= r) {
//        memset(vi, false, sizeof(vi));
//        mid = (l + r) / 2;
//        if (dfs(s, a[mid])) {
//            flagf = a[mid];
//            r = mid - 1;
//        }
//        else l = mid + 1;
//    }
//    cout << flagf << endl;
//    return 0;
//}