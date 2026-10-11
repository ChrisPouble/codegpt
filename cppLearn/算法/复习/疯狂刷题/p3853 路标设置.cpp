//#include <iostream>
//#include <cmath>
//#include <algorithm>
//using namespace std;
//
//int L, N, K, a[100001];
//int main() {
//    cin >> L >> N >> K;
//    for (int i = 1; i <= N; i++)
//        cin >> a[i];
//    sort(a + 1, a + N + 1);
//    int l = 0, r = L + 1, ans = 0;
//    while (l <= r) {
//        int mid = (r + l) / 2, cnt = 0;
//        for (int i = 1; i <= N - 1; i++)
//            if (a[i + 1] - a[i] > mid) cnt += ceil((double)((a[i + 1] - a[i]) / mid)) - 1;
//        if (K >= cnt) r = mid - 1, ans = mid;
//        else l = mid + 1;
//    }
//    cout << ans << endl;
//    return 0;
//}
///*
//101 2 1
//0 101
//*/