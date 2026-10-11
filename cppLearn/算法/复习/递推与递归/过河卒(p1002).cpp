//#include <iostream>
//using namespace std;
//
////马的9个控制点的方向
//int d[9][2] = { {0, 0}, {1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1} };
//long long f[25][25]; //f[i][j]表示从(0, 0)点到(i, j)点的方案数
//int ctrl[25][25]; //马的9个控制点
//int main()
//{
//    int n, m, hx, hy; cin >> n >> m >> hx >> hy;
//    for (int i = 0; i < 9; i++) {
//        int xx = hx + d[i][0], yy = hy + d[i][1];
//        if (xx <= n && xx >= 0 && yy <= m && yy >= 0) ctrl[xx][yy] = 1;
//    }
//    if (ctrl[0][0]) f[0][0] = 0; //如果(0, 0)点也是马的控制点, 那么f[0][0]的方案数为0
//    else f[0][0] = 1; //否则为1
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= m; j++) {
//            if (ctrl[i][j]) continue; //如果是马的控制点，那么就跳过
//            if (i != 0) f[i][j] += f[i - 1][j]; //如果不在横轴上, 那么就加上上面的值
//            if (j != 0) f[i][j] += f[i][j - 1]; //如果不在竖轴上, 那么就加上左边的值
//        }
//    }
//    cout << f[n][m] << endl;
//    system("pause");
//    return 0;
//}