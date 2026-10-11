//#include <iostream>
//using namespace std;
//
//struct Int {
//    int len, a[1100];
//    void csh(string s) {
//        memset(a, 0, sizeof(a));
//        for (int i = 1; i <= s.size(); i++)
//            a[i] = s[s.size() - i] - 48;
//        len = s.size();
//    }
//    int& operator[](int x) {
//        return a[x];
//    }
//    void Cout() {
//        while (a[len] == 0) len--;
//        for (int i = len; i >= 1; i--)
//            cout << a[i];
//        cout << endl;
//    }
//};
//
//Int operator+(Int a, Int b) {
//    Int c;
//    c.csh("0");
//    c.len = max(a.len, b.len) + 1;
//    for (int i = 1; i <= c.len; i++) {
//        c[i] += a[i] + b[i];
//        c[i + 1] += c[i] / 10;
//        c[i] %= 10;
//    }
//    return c;
//}
//
//Int f[1010];
//int main() {
//    int n, m; cin >> m >> n;
//    f[m].csh("1");
//    f[m + 1].csh("1");
//    for (int i = m + 2; i <= n; i++)
//        f[i] = f[i - 1] + f[i - 2];
//    f[n].Cout();
//    return 0;
//}