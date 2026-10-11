//#include "对拍问题代码.h"
//#include "对拍正确代码.h"
//using namespace std;
//
//int sx, sy, ex, ey;
//void bijiao() {
//	int a1 = bfs(sx, sy, ex, ey);
//	int a2 = me(sx, sy);
//	if (a1 != a2) {
//		cout << "错误！  " << "正确答案：" << a1 << "  错误答案：" << a2 << endl;
//	}
//}
//
//int main() {
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++) {
//			cin >> g[i][j];
//			if (g[i][j] == 'S') sx = i, sy = j;
//			else if (g[i][j] == 'T') ex = i, ey = j;
//		}
//	  bijiao();
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n, m, ans = 2e8, dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//char c[110][110];
//bool a[110][110];
//int h = 1, t = 0, q1[11000], q2[11000], q3[11000];
//int main() {
//    cin >> n >> m;
//    int dx, dy;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++) {
//            cin >> c[i][j];
//            if (c[i][j] == 'S') dx = i, dy = j;
//        }
//    q1[++t] = dx, q2[t] = dy, q3[t] = 0;
//    a[dx][dy] = true;
//    while (h <= t) {
//        int x = q1[h], y = q2[h], sum = q3[h];
//        h++;
//        for (int i = 0; i < 4; i++) {
//            int tx = x + dxy[i][0], ty = y + dxy[i][1];
//            if (tx < 0 || tx >= n || ty < 0 || ty >= m || c[tx][ty] == '#' || a[tx][ty]) continue;
//            if (c[tx][ty] == 'T') ans = min(ans, sum + 1);
//            if (c[tx][ty] == '.') {
//                q1[++t] = tx, q2[t] = ty, q3[t] = sum + 1;
//                a[tx][ty] = true;
//            }
//        }
//    }
//    if (ans == 200000000) cout << 0 << endl;
//    else cout << ans << endl;
//    return 0;
//}