//#include <iostream>
//using namespace std;
//
//int nowtime, maxtime, sum;
//int ans, maxdeep;
//int a[5], temp[21];
//void p2392(int x)
//{
//    if (x > maxdeep) {
//        maxtime = max(maxtime, nowtime);
//        return;
//    }
//    if (nowtime + temp[x] <= sum / 2) {
//        nowtime += temp[x];
//        p2392(x + 1);
//        nowtime -= temp[x];
//    }
//    p2392(x + 1);
//}
//
//int main()
//{
//    cin >> a[1] >> a[2] >> a[3] >> a[4];
//    for (int i = 1; i <= 4; i++) {
//        nowtime = 0;
//        maxdeep = a[i];
//        sum = 0;
//        for (int j = 1; j <= a[i]; j++) {
//            cin >> temp[j];
//            sum += temp[j];
//        }
//        maxtime = 0;
//        p2392(1);
//        ans += (sum - maxtime);
//    }
//
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}