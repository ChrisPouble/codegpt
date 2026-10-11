//#include <iostream>
//using namespace std;
//
//string s, t;
//int a[510], b[510], c[510];
//void gaojingjia() {
//    int len = max(s.size(), t.size()) + 1;
//    for (int i = 1; i <= len; i++) {
//        c[i] += a[i] + b[i];
//        c[i + 1] += c[i] / 10;
//        c[i] %= 10;
//    }
//    while (c[len] == 0) len--;
//    for (int i = max(len, 1); i >= 1; i--) cout << c[i];
//}
//
//int main() {
//    cin >> s >> t;
//    for (int i = 1; i <= s.size(); i++)
//        a[i] = s[s.size() - i] - 48;
//    for (int i = 1; i <= t.size(); i++)
//        b[i] = t[t.size() - i] - 48;
//    gaojingjia();
//    return 0;
//}