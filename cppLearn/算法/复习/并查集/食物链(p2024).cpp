//#include <iostream>
//using namespace std;
//
//int n, k, ans, fa[150010]; //1 ~ 50000存同类，50001 ~ 100000存猎物，100001 ~ 150000存天敌
//int find(int x) {
//    if (x == fa[x]) return x;
//    else {
//        fa[x] = find(fa[x]);
//        return fa[x];
//    }
//}//寻找
//
//void merger(int x, int y) {
//    int xx = find(x), yy = find(y);
//    fa[xx] = yy;
//}//合并
//
//int main() {
//    cin >> n >> k;
//    for (int i = 1; i <= n * 3; i++)
//        fa[i] = i;
//    for (int i = 1; i <= k; i++) {
//        int d, x, y; cin >> d >> x >> y;
//        if (x > n || y > n) {
//            ans++;
//            continue;
//        }
//        if (d == 1) {
//            if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) { //x的天敌或猎物不能是y
//                ans++;
//                continue;
//            }
//            merger(x, y), merger(x + n, y + n), merger(x + 2 * n, y + 2 * n); //否则x的同类是y的同类，x的天敌是y的天敌，x的猎物是y的猎物
//        } else {
//            if (x == y) {
//                ans++;
//                continue;
//            }
//            if (find(x + n) == find(y) || find(x) == find(y)) { //x的天敌或同类不能是y
//                ans++;
//                continue;
//            }
//            merger(x, y + n), merger(x + n, y + 2 * n), merger(x + 2 * n, y); //否则，x的同类是y的天敌，x的天敌是y的猎物，x的猎物是y的同类
//        }
//    }
//    return 0;
//}
///*
//100 7
//1 101 1
//2 1 2
//2 2 3
//2 3 3
//1 1 3
//2 3 1
//1 5 5
//*/