////分组背包
//#include <iostream>
//using namespace std;
//
//int m, n, sum, S[1001], W[1001], K[102], q[1001];
//void cf(int x) {
//    for (int i = 1; K[i] != 0; i++)
//        if (x == K[i]) return;
//    sum++;
//}
//
//int main() {
//    cin >> m >> n;
//    for (int i = 1; i <= n; i++) {
//        int temp;
//        cin >> S[i] >> W[i] >> temp;
//        K[temp]++;
//        cf(K[i]);
//    }
//    //滚动数组
//    for (int k = 1; k <= sum; k++) //遍历所有组
//        for (int v = m; v >= 0; v--) //从后向前遍历背包承受重量
//            for (int i = 1; i <= K[k]; i++) //遍历第k组的物品
//                if(v >= S[i]) q[v] = max(q[v], q[v - S[i]] + W[i]);
//    cout << q[n] << endl;
//    return 0;
//}
///*
//45 3
//10 10 1
//10 5 1
//50 400 2
//*/