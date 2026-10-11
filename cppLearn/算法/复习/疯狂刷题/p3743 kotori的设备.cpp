//#include <iostream>
//using namespace std;
//
//int n, p, a[100010], b[100010];
//int main() {
//    cin >> n >> p;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i] >> b[i];
//    //ºÙ÷¶
//    double sum = 0;
//    for (int i = 1; i <= n; i++)
//        sum += a[i];
//    if (sum <= p) {
//        cout << -1 << endl;
//        return 0;
//    }
//    //∂˛∑÷
//    double l = 0, r = 1e10, ans = -1;
//    while (fabs(l - r) >= 1e-5) {
//        double mid = (l + r  ) / 2;
//        double t = 0;
//        for (int i = 1; i <= n; i++)
//            if (a[i] * mid > b[i]) t += a[i] * mid - b[i];
//        if (mid * p >= t) l = mid, ans = mid;
//        else r = mid;
//    }
//    printf("%.10f\n", ans);
//    return 0;
//}
///*
//2 1
//2 2
//2 1000
//
//1 100
//1 1
//
//3 5
//4 3
//5 2
//6 1
//*/