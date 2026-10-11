//#include <iostream>
//using namespace std;
//
//struct Begin
//{
//    int len, a[5000];
//    Begin(int x = 0)
//    {
//        memset(a, 0, sizeof(a));
//        for (len = 1; x; len++)
//            a[len] = x % 10, x /= 10;
//        len--;
//    }
//
//    void Cout()
//    {
//        cout << "最大乘积为: ";
//        for (int i = max(1, len); i >= 1; i--)
//            cout << a[i];
//    }
//};
//
//Begin operator*(Begin a, Begin b)
//{
//    Begin c;
//    int len = a.len;
//    for (int i = 1; i <= len; i++)
//        c.a[i] += a.a[i] * b.a[i];
//
//    for (int i = 1; i <= len; i++)
//    {
//        c.a[i + 1] += c.a[i] / 10;
//        c.a[i] %= 10;
//    }
//
//    for (; !c.a[len];) //去掉前导零
//        len--;
//    return c;
//}
//
//int main()
//{
//    int i = 0, n = 20, x1, x2, sum3, sum2, a7[3345] = { 0 };
//    //cin >> n;
//
//    if (n % 3 == 0) x1 = n / 3;
//
//    if (n % 3 == 1)
//    {  
//        x1 = (n - 4) / 3;
//        sum3 = x1;
//        x2 = 2;
//        sum2 = 2;
//    }
//
//    if (n % 3 == 2)
//    {
//        x1 = (n - 2) / 3;
//        sum3 = x1;
//        x2 = 1;
//        sum3 = x2;
//    }
//
//    for (; i <= x1; i++)
//        a7[i] = 3;
//    if (x2 == 2)
//        a7[i + 1] = 2, a7[i + 2] = 2;
//    if (x2 == 1)
//        a7[i + 1] = 2;
//
//    Begin fuc(1);
//    for (int i = 1; i <= x1; i++)
//    {
//        fuc = fuc * 3;
//    }
//
//    if (x2 == 1)
//        fuc = fuc * 4;
//    if (x2 == 2)
//        fuc = fuc * 2;
//    fuc.Cout();
//    cout << "分解成了" << sum3 << "个3" << "和"
//        << sum2 << "个2";
//    system("pause");
//    return 0;
//}