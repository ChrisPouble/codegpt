//#include <iostream>
//using namespace std;
//
//int a[151][151];
//int main() {
//    int n, m, s, t; cin >> n >> m >> s >> t;
//    for (int i = 1; i <= n; i++)
//        a[i][i] = 0;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            a[i][j] = 1e6;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        a[u][v] = w;
//    }
//    for (int k = 1; k <= n; k++)
//        for (int i = 1; i <= n; i++)
//            for (int j = 1; j <= n; j++)
//                if (a[i][j] > a[i][k] + a[k][j])
//                    a[i][j] = a[i][k] + a[k][j];
//    cout << a[s][t] << endl;
//    return 0;
//}