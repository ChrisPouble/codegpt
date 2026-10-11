//#include <iostream>
//using namespace std;
//
//const int maxn = 100001;
//int dp[maxn] = { 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 7, 7, 7, 7, 7, 9, 9, 12 };
//int max(int a, int b, int c) {
//    return max(max(a, b), c);
//}
//
//int main() {
//    int T, n; cin >> T;
//    for (int j = 18; j <= 100001; j++)
//        dp[j] = max(dp[j - 5] + 2, dp[j - 10] + 7, dp[j - 17] + 12);
//    for (int i = 1; i <= T; i++) {
//        cin >> n;
//        int ans = 0;
//        while (n >= 100000) n -= 17, ans += 12;
//        cout << ans + dp[n] << endl;
//    }
//    return 0;
//}
///*
//3
//20
//21
//22
//*/