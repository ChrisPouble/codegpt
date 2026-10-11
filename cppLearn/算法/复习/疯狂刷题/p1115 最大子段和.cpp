//#include <iostream>
//using namespace std;
//
//int a[200010], f[200010]; //f[i]表示以a[i]结尾的最大子段和是多少
//int main() {
//    int n, ans = -2e9; cin >> n;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    f[1] = a[1];
//    for (int i = 2; i <= n; i++) {
//        f[i] = a[i] + max(f[i - 1], 0);
//        ans = max(ans, f[i]);
//    }
//    cout << ans << endl; //不能输出f[n]，因为f[n]不一定为最大值
//    return 0;
//}
/*
7
2 -4 3 -1 2 -4 3
*/