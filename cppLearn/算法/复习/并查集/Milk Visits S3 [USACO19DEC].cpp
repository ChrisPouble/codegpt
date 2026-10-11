//#include <iostream>
//using namespace std;
//
//int n, m, fa[100010];
//string s;
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
//    cin >> s;
//    for (int i = 1; i <= n; i++)
//        fa[i] = i;
//    for (int i = 1; i <= n - 1; i++) {
//        int x, y; cin >> x >> y;
//        if (s[x - 1] == s[y - 1]) merger(x, y);
//    }
//    for (int i = 1; i <= m; i++) {
//        int x, y; char z; cin >> x >> y >> z;
//        if (find(x) == find(y) && s[x - 1] != z) cout << 0;
//        else cout << 1;
//    }
//    return 0;
//}