//#include <iostream>
//using namespace std;
//
//const int maxn = 1e5 + 10;
//long long n, k, a[maxn] = {1, 1};
//int main() {
//    cin >> n >> k;
//    for (int i = 2; i <= k; i++)
//        for (int j = 0; j < i; j++)
//            a[i] += a[j] % 100003;
//    for (int i = k + 1; i <= n; i++)
//        for (int j = 1; j <= k; j++)
//            a[i] += a[i - j] % 100003;
//    cout << a[n] % 100003 << endl;
//    return 0;
//}
///*
//5 2
//*/