//#include <iostream>
//#include <map>
//using namespace std;
//
//int a[2001];
//int main() {
//    map<int, int>cnt;
//    int n, m; long long ans = 0; cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    for (int i = 1; i <= n; i++) {
//        cnt[i - a[i]]++;
//        cnt[i + a[i]]++;
//    }
//    for (int i = 1; i <= n; i++) {
//        ans += cnt[i - a[i]];
//        ans += cnt[i + a[i]];
//    }
//    ans -= n * 2;
//    ans /= 2;
//    cout << ans << endl;
//    return 0;
//}
///*
//5 5
//2 3 3 3 2
//*/