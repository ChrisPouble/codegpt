//#include <iostream>
//using namespace std;
//
//int n, x, lose[1005], win[1005], use[1005];
//int f[1005][1005]; //f[i][j]表示前i个人，嗑j个药，能获得的最大收益
//int main() {
//    cin >> n >> x;
//    for (int i = 1; i <= n; i++)
//        cin >> lose[i] >> win[i] >> use[i];
//    for (int i = 1; i <= n; i++)
//        for (int j = x; j >= 0; j--)
//            if (j >= use[i]) f[i][j] = max(f[i - 1][j - use[i]] + win[i], f[i - 1][j] + lose[i]);
//            else f[i][j] = f[i - 1][j] + lose[i];
//    cout << (long long)f[n][x] * 5 << endl;
//    return 0;
//}
///*
//6 8
//21 52 1
//21 70 5
//21 48 2
//14 38 3
//14 36 1
//14 36 2
//*/