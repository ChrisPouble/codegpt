//#include <iostream>
//using namespace std;
//
//struct Int
//{
//    int len, a[10010]; //高精数的长度和数字
//    Int(string s) { //构造函数
//        memset(a, 0, sizeof(a)); //归零
//        for (int i = 1; i <= s.size(); i++) //加入数字
//            a[i] = s[s.size() - i] - 48;
//        len = s.size(); //加入长度
//    }
//    int& operator[](int i) { //可以把x.a[i]变成x[i]，写起来更简便，注意要加&号
//        return a[i];
//    }
//    void Cout() { //完结输出
//        while (a[len] == 0) len--; //去掉前导零
//        for (int i = max(this->len, 1); i >= 1; i--) cout << this->a[i];
//        cout << endl;
//    }
//};
//
//Int operator+(Int a, Int b) //高精度加法
//{
//    Int c("0");
//    c.len = max(a.len, b.len) + 1;
//    for (int i = 1; i <= c.len; i++) {
//        c[i] += a[i] + b[i];
//        c[i + 1] += c[i] / 10;
//        c[i] %= 10;
//    }
//    return c;
//}
//
//int baoli(int n) { //暴力代码
//    int a = 0, b = 1, c = 0;
//    for (int i = 1; i <= n; i++)
//        c = a + b, a = b, b = c;
//    return c;
//}
//
//Int zhengque(int n) { //正确代码
//    Int a("0");
//    Int b("1");
//    Int c("0");
//    for (int i = 1; i <= n; i++)
//        c = a + b, a = b, b = c;
//    return c;
//}
//
//bool same(int x, Int y) { //比较暴力代码和正确代码
//    int xx = 0, tx = x;
//    while (tx) {
//        tx /= 10;
//        xx++;
//    }
//    while (y[y.len] == 0) y.len--;
//    if (xx != y.len) return false;
//    for (int i = 1; i <= xx; i++) {
//        if (y[i] != x % 10) return false;
//        x /= 10;
//    }
//    return true;
//}
//
//void pd(int a, int b) { //判断a~b所有的数是否可以过
//    for (int i = a; i <= b; i++) {
//        Int z = zhengque(i);
//        int b = baoli(i);
//        if (!same(b, z)) {
//            cout << "数据错在：" << i << "  错误答案：";
//            z.Cout();
//            cout << "  正确答案：" << b << endl;
//            return;
//        }
//    }
//    cout << "完全真确" << endl;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    Int a("0");
//    Int b("1");
//    Int c("0");
//    for (int i = 1; i <= n; i++)
//        c = a + b, a = b, b = c;
//    c.Cout();
//    cout << endl;
//    //(1, 30); //对拍
//    system("pause");
//    return 0;
//}