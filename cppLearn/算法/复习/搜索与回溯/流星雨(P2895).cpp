//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct node {
//    int x, y;
//};
//int ans[310][310], death[310][310]; //death表示该点被流星雨砸中的时间
//queue<node>q;
//int wk[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
//
//int main()
//{
//    int M, Ans = 100000; cin >> M;
//    memset(ans, -1, sizeof(ans));
//    memset(death, 0x7f, sizeof(death)); //0x3f是一个很大的数，大约2e10
//    for (int i = 1; i <= M; i++) {
//        int x, y, t; cin >> x >> y >> t;
//        if (x >= 0 && y >= 0) death[x][y] = min(death[x][y], t); //流星雨砸中的时间要取最早的值
//        for (int j = 0; j < 4; j++) {
//            int nx = x + wk[j][0], ny = y + wk[j][1];
//            if (nx >= 0 && ny >= 0) death[nx][ny] = min(death[nx][ny], t); //更新焦土
//        }
//    }
//    q.push({ 0, 0 }); //原点加入队列
//    ans[0][0] = 0;
//    while (!q.empty()) {
//        node t = q.front();
//        int tx = t.x, ty = t.y;
//        q.pop();
//        for (int i = 0; i < 4; i++) {
//            int x = tx + wk[i][0], y = ty + wk[i][1];
//            if (x >= 0 && y >= 0 && ans[x][y] == -1 && ans[tx][ty] + 1 < death[x][y]) {
//                ans[x][y] = ans[tx][ty] + 1; //当目标格子的最早到达时间已经被破坏时不能更新
//                q.push({ x, y });
//            }
//        }
//    }
//    for (int i = 0; i <= 305; i++)
//        for (int j = 0; j <= 305; j++)
//            if (death[i][j] > 1000 && ans[i][j] != -1)
//                Ans = min(ans[i][j], Ans); //统计答案：在所有安全区域且能达到的点中找到达最早的
//    if (Ans == 100000) cout << -1 << endl;
//    else cout << Ans << endl;
//    system("pause");
//    return 0;
//}