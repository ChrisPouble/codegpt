//#include <iostream>
//using namespace std;
//
//const int maxN = 1e3 + 5, maxK = 20;
//int n, m, K, f[maxN][maxK], a[maxN];
//int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//        f[i][0] = a[i];
//    }
//    K = log2(n);
//    for (int j = 1; j <= K; j++) {
//        int k = 1 << j;
//        for (int i = 1; i + k - 1 <= n; i++) {
//            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//        }
//    }
//    int i, j, k;
//    while (m--) {
//        cin >> i >> j;
//        k = int(log2(j - i + 1));
//        cout << min(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]) << " ";
//    }
//    return 0;
//}
///*
//10 3
//1 2 6 4 5 6 7 8 9 10
//2 7
//3 9
//1 10
//*/