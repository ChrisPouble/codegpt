//#include <iostream>
//using namespace std;
//
////const int maxn = 10001;
////bool isp[maxn];
////int p[maxn], tot, n;
////void Prime1() {
////    for (int i = 0; i <= n; i++)
////        isp[i] = true;
////    isp[0] = isp[1] = false;
////    for (int i = 2; i <= n; i++) {
////        if (isp[i]) p[++tot] = i;
////        for (int j = i * 2; j <= n; j += i)
////            isp[j] = false;
////    }
////}
//
//const int maxn = 10001;
//bool notp[maxn];
//int p[maxn], tot, n;
//void Prime2() {
//    memset(notp, false, sizeof(notp));
//    notp[0] = notp[1] = 1;
//    for (int i = 2; i <= n; i++) { //遍历倍数
//        if (!notp[i]) p[++tot] = i;
//        for (int j = 1; j <= tot; j++) { //遍历质数
//            if (p[j] * i > n) break;
//            notp[p[j] * i] = true; //质数的倍数是合数
//            if (i % p[j] == 0) break; //发现i是合数直接退出循环
//        }
//    }
//}
//
//int main() {
//    cin >> n;
//    Prime2();
//    for (int i = 1; p[i] != 0; i++)
//        cout << p[i] << " ";
//    return 0;
//}