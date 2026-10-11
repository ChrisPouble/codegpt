//#include <iostream>
//using namespace std;
//
//int n, a[100010]; string s;
//int main() {
//    cin >> s;
//    for (int i = 0; i < s.size(); i++)
//        if (s[i] == '0') a[i + 1] = 1;
//        else a[i + 1] = -1;
//    int ans = 0, sum = 0;
//    for (int i = 1; i <= s.size(); i++) {
//        sum += a[i];
//        if (sum < 0) {
//            sum = 0;
//            continue;
//        }
//        ans = max(ans, sum);
//    }
//    cout << ans << endl;
//    return 0;
//}
///*
//0111100101
//*/