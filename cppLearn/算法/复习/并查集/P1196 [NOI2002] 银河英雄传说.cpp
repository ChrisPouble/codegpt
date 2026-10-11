//#include <iostream>
//using namespace std;
//
//int T, fa[500010], front[30010], sum[30010];//front[i]表示飞船i与其所在列队头的距离
//                                            //sum[i]表示第i列的飞船数量
//int fin(int x) {
//    if (x == fa[x]) return x;
//    else {
//        int t = fin(fa[x]);
//        front[x] += front[fa[x]];//更新front[x]到队头的距离
//        return fa[x] = t;
//    }
//}
//
//int main() {
//    cin >> T;
//    for (int i = 1; i <= 30005; i++) {
//        fa[i] = i;
//        front[i] = 0;
//        sum[i] = 1;
//    }
//    for (int i = 1; i <= T; i++) {
//        int x, y; char z; cin >> z >> x >> y;
//        int xx = fin(x);
//        int yy = fin(y);
//        if (z == 'M') {
//            front[xx] += sum[yy]; //xx到队头的距离加上yy所在列的飞船数
//            fa[xx] = yy; //把xx放到yy队列
//            sum[yy] += sum[xx]; //更新yy所在队列的飞船数
//            sum[xx] = 0; //把xx原来所在队列飞船更新为0
//        }
//        else {
//            if (xx != yy) cout << -1 << endl;//若x和y的祖先不相同，则不在同一列
//            else cout << abs(front[x] - front[y]) - 1 << endl;//否则利用x和y离队头的距离算出它们的距离
//        }
//    }
//    return 0;
//}
///*
//4
//M 2 3
//C 1 2
//M 2 4
//C 4 2
//*/