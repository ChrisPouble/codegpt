#include <iostream>
#include <algorithm>
using namespace std;

bool pdst(string a, string b) {
    for (int i = 0; i < a.size(); i++)
        if ((int)a[i] > (int)b[i]) return true; //比较每一个字符
        else if ((int)a[i] < (int)b[i]) return false; //比较每一个字符
    return true; //两者相同的情况
}

bool p1012(string a, string b)
{
    string c = a, d = b;
    c += b, d += a; //拼接字符串
    return pdst(c, d);
}

string a[100];
//int main()
//{
//    int n; cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        string t;
//        cin >> t;
//        a[i] = t;
//    }
//
//    sort(a, a + n, p1012);
//    for (int i = 0; i < n; i++)
//        cout << a[i];
//    cout << endl;
//    system("pause");
//    return 0;
//}