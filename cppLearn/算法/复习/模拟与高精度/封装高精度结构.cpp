//#include <iostream>
//using namespace std;
//
//struct Int
//{
//    int len, a[510]; //高精数的长度和数字
//    Int(string s) { //构造函数
//        memset(a, 0, sizeof(a)); //归零
//        for (int i = 1; i <= s.size(); i++) //加入数字
//            a[i] = s[s.size() - i] - 48;
//        len = s.size(); //加入长度
//    }
//    int &operator[](int i) { //可以把x.a[i]变成x[i]，写起来更简便，注意要加&号
//        return a[i];
//    }
//    void Cout() { //完结输出
//        if (a[len + 1] != 0) len++; //去掉前导零
//        for (int i = max(this->len, 1); i >= 1; i--) cout << this->a[i];
//        cout << endl;
//    }
//};
//
//Int operator+(Int a, Int b) //高精度加法
//{
//    Int c("0");
//    c.len = max(a.len, b.len);
//    for (int i = 1; i <= c.len; i++) {
//        c[i] += a[i] + b[i];
//        c[i + 1] = c[i] / 10;
//        c[i] %= 10;
//    }
//    return c;
//}
//
//Int operator*(Int a, int b) //高精度乘法
//{
//    Int c("0");
//    c.len = a.len + 10;
//    for (int i = 1; i <= a.len; i++)
//            c[i] += a[i] * b;
//    for (int i = 1; i <= c.len; i++) {
//        c[i + 1] += c[i] / 10;
//        c[i] %= 10;
//    }
//    while (c[c.len] == 0) c.len--;
//    return c;
//}
//
//int main()
//{
//    Int ans("0"), fun("1"); //初始化
//    int m;
//    cin >> m;
//    for (int i = 1; i <= m; i++) //跟int一样丝滑的阶乘之和代码
//    {
//        fun = fun * i; //主要讲高精，这里是算阶乘的代码
//        ans = ans + fun; //把原来的ans和fun相加凑成新的ans
//    }
//    ans.Cout(); //大完输出
//    system("pause");
//    return 0;
//}