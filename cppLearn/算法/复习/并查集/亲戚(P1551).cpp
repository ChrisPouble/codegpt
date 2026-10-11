//#include <iostream>
//using namespace std;
//
//int n, m, p, fa[5010];
//int find(int x) {
//    if (x == fa[x]) return x;
//    else {
//        fa[x] = find(fa[x]);
//        return fa[x];
//    }
//}
//
//void merger(int x, int y) {
//    int xx = find(x), yy = find(y);
//    if (fa[xx] != yy) fa[xx] = yy;
//}
//
//int main() {
//    cin >> n >> m >> p;
//    for (int i = 1; i <= n; i++)
//        fa[i] = i;
//    for (int i = 1; i <= m; i++) {
//        int x, y; cin >> x >> y;
//        merger(x, y);
//    }
//    for (int i = 1; i <= p; i++) {
//        int x, y; cin >> x >> y;
//        if (find(x) != find(y)) cout << "No" << endl;
//        else cout << "Yes" << endl;
//    }
//    return 0;
//}