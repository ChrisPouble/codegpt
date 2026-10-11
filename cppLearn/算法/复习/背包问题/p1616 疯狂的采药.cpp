////完全背包
//#include <iostream>
//using namespace std;
//
//int T, M, S[10001], W[10001], q[10000001];
//int main() {
//    cin >> T >> M;
//    for (int i = 1; i <= M; i++)
//        cin >> S[i] >> W[i];
//    //滚动数组
//    for (int i = 1; i <= M; i++) //遍历物品
//        for (int v = 0; v <= T; v++) //从前向后遍历背包承受重量
//            if (v >= S[i]) q[v] = max(q[v], q[v - S[i]] + W[i]);
//    cout << q[T] << endl;
//    return 0;
//}
///*
//70 3
//71 100
//69 1
//1 2
//*/