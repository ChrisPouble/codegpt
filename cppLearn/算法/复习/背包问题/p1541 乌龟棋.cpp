//#include<iostream>
//using namespace std;
//
//long long dp[41][41][41][41];
//int N, M, a[1001], b[5], c;
//int main() {
//    cin >> N >> M;
//    for (int i = 1; i <= N; i++)
//        cin >> a[i];
//    for (int i = 1; i <= M; i++) {
//        cin >> c; b[c]++;
//    }
//    for (int i = 0; i <= b[1]; i++) //遍历卡牌1
//        for (int j = 0; j <= b[2]; j++) //遍历卡牌2
//            for (int k = 0; k <= b[3]; k++) //遍历卡牌3
//                for (int l = 0; l <= b[4]; l++) { //遍历卡牌4
//                    int temp = a[i + 2 * j + 3 * k + 4 * l + 1]; //表示现在所到达地方的数值
//                    if (i) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l]);
//                    if (j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l]);
//                    if (k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l]);
//                    if (l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1]);
//                    dp[i][j][k][l] += temp;
//                }
//    cout << dp[b[1]][b[2]][b[3]][b[4]] << endl;
//    return 0;
//}
///*
//9 5
//6 10 14 2 8 8 18 5 17
//1 3 1 2 1
//*/