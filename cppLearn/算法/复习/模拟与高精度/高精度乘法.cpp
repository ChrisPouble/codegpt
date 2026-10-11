//#include <iostream>
//using namespace std;
//
//string s, t;
//int a[2010], b[2010], c[4010];
//void gaojingcheng() {
//    int len = s.size() + t.size();
//    for (int i = 1; i <= s.size(); i++)
//        for (int j = 1; j <= t.size(); j++)
//            c[i + j - 1] += a[i] * b[j];
//    for (int i = 1; i <= len; i++) {
//        c[i + 1] += c[i] / 10;
//        c[i] %= 10;
//    }
//    while (c[len] == 0) len--;
//    for (int i = max(len, 1); i >= 1; i--) cout << c[i]; //如果得数是0，上面会去掉前导零，要变为1
//}
//
//int main() {
//    cin >> s >> t;
//    for (int i = 1; i <= s.size(); i++)
//        a[i] = s[s.size() - i] - 48;
//    for (int i = 1; i <= t.size(); i++)
//        b[i] = t[t.size() - i] - 48;
//    gaojingcheng();
//    return 0;
//}