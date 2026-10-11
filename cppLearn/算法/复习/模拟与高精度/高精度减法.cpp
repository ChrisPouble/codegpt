//#include <iostream>
//using namespace std;
//
//string s, t;
//int a[510], b[510], c[510];
//void gaojingjian() {
//    int len = max(s.size(), t.size());
//    for (int i = 1; i <= len; i++) {
//        if (a[i] < b[i]) a[i] += 10, a[i + 1]--;
//        c[i] = a[i] - b[i];
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
//    gaojingjian();
//    return 0;
//}