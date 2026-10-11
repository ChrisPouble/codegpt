//#include <iostream>
//using namespace std;
//
//int n, m, fa[10010];
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
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        fa[i] = i;
//    for (int i = 1; i <= m; i++) {
//        int z, x, y; cin >> z >> x >> y;
//        if (z == 1) merger(x, y);
//        else if(z == 2) {
//            if (find(x) == find(y)) cout << "Y" << endl;
//            else cout << "N" << endl;
//        }
//    }
//    return 0;
//}