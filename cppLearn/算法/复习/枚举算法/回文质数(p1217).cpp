#include <iostream>
using namespace std;

bool prime(int x) { //判断质数
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

bool same(int x) { //判断回文数
    if (x / 1000 == 0)
    {
        if (x / 100 == x % 10) return true;
    }
    else if (x / 100000 == 0)
    {
        if (x / 10000 == x % 10 && x / 1000 % 10 == x / 10 % 10) return true;
    }
    else
    {
        if (x / 1000000 == x % 10 && x / 100000 % 10 == x / 10 % 10 && x / 10000 % 10 == x / 100 % 10)
            return true;
    }
    return false;
}

//int main()
//{
//    int a, b, t, u;
//    cin >> a >> b;
//    if (a <= 5 && b >= 5) cout << 5 << endl;
//    if (a <= 7 && b >= 7) cout << 7 << endl;
//    if (a <= 11 && b >= 11) cout << 11 << endl;
//    if (a <= 101) u = 101;
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 999) t = 999;
//    else t = b;
//    for (int i = u; i <= t; i++)
//        if (prime(i) && same(i)) cout << i << endl;
//
//    if (a <= 10001) u = 10001;
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 99999) t = 99999;
//    else t = b;
//    for (int i = u; i <= t; i++)
//        if (prime(i) && same(i)) cout << i << endl;
//    
//    if (a <= 1000001) u = 1000001; //一系列写到手软的剪枝
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 1999991) t = 1999991;
//    else t = b;
//    for (int i = u; i <= t; i += 2) //两个两个跳着判断会减少一半的时间
//        if (same(i) && prime(i)) cout << i << endl; //先判断回文数再判断质数，因为回文数少
//    
//    if (a <= 3000003) u = 3000003; //一系列写到手软的剪枝
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 3999993) t = 3999993;
//    else t = b;
//    for (int i = u; i <= t; i += 2) //两个两个跳着判断会减少一半的时间
//        if (same(i) && prime(i)) cout << i << endl; //先判断回文数再判断质数，因为回文数少
//
//    if (a <= 7000007) u = 7000007; //一系列写到手软的剪枝
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 7999997) t = 7999997;
//    else t = b;
//    for (int i = u; i <= t; i += 2) //两个两个跳着判断会减少一半的时间
//        if (same(i) && prime(i)) cout << i << endl; //先判断回文数再判断质数，因为回文数少
//    
//    if (a <= 9000009) u = 9000009; //一系列写到手软的剪枝
//    else {
//        if (a % 2 == 1) u = a;
//        else u = a + 1;
//    }
//    if (b > 9999999) t = 9999999;
//    else t = b;
//    for (int i = u; i <= t; i += 2) //两个两个跳着判断会减少一半的时间
//        if (same(i) && prime(i)) cout << i << endl; //先判断回文数再判断质数，因为回文数少
//        
//    system("pause");
//    return 0;
//}