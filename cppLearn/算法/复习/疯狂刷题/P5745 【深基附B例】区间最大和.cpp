//#include <iostream>
//using namespace std;
//
//const int maxn = 4e6 + 10;
//int a[maxn];
//long long s[maxn];
//int main() {
//    int n, m; cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    for (int i = 1; i <= n; i++)
//        s[i] = s[i - 1] + a[i];
//    int maxt = 0, maxi = 0, maxj = 0;
//    for (int i = 1; i <= n; i++) {
//        int l = i, r = n, x = 0, ans = 0;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            if (s[mid] - s[i - 1] > m) r = mid - 1;
//            else l = mid + 1;
//        }
//        if (s[r] - s[i - 1] <= m)
//            if(s[r] - s[i - 1] > maxt) maxt = s[r] - s[i - 1], maxi = i, maxj = r;
//    }
//    cout << maxi << " " << maxj << " " << maxt << endl;
//    return 0;
//}
///*
//5 10
//2 3 4 5 6
//*/