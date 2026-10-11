////01背包
//#include <iostream>
//using namespace std;
//
//int T, M, S[101], W[101], q[1001];
//int main() {
//    cin >> T >> M;
//    for (int i = 1; i <= M; i++)
//        cin >> S[i] >> W[i];
//    //滚动数组
//    for (int i = 1; i <= M; i++) //遍历所有物品
//        for (int v = T; v >= 0; v--) //从后向前遍历背包承受重量
//            if(v >= S[i]) q[v] = max(q[v], q[v - S[i]] + W[i]);
//    cout << q[T] << endl;
//    return 0;
//}
///*
//70 3
//71 100
//69 1
//1 2
//*/