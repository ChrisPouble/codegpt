//#include <iostream>
//#include <queue>
//using namespace std;
//
//struct node
//{
//    int x, y;
//};
//int n, m, ans[405][405];
//int go[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1} };
//queue<node> Q;
//
//bool check(int x, int y) {
//    if (x >= 1 && x <= n && y >= 1 && y <= m && ans[x][y] == -1) return true;
//    return false;
//}
//
//int main()
//{
//    int sx, sy; cin >> n >> m >> sx >> sy;
//    memset(ans, -1, sizeof(ans));
//    ans[sx][sy] = 0;
//    Q.push({ sx, sy });
//    while (!Q.empty()) {
//        node t = Q.front(); //取出队头元素
//        int tx = t.x, ty = t.y;
//        Q.pop(); //删除队头元素
//        for (int i = 0; i < 8; i++) { //遍历马的8个方向
//            int x = tx + go[i][0], y = ty + go[i][1];
//            if (check(x, y)) { //检查是否超出边界和是否已经被检查过了
//                ans[x][y] = ans[tx][ty] + 1; //更新
//                Q.push({ x, y }); //加入元素
//            }
//        }
//    }
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++)
//            cout << ans[i][j] << "\t";
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}