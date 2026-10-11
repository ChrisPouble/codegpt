//#include <iostream>
//using namespace std;
//
//int a1[510] = { 0 }, b1[510] = { 0 }, c1[510] = { 0 };
//void p1601(string s, string t)
//{
//    int len;
//    if (s.size() >= t.size()) len = s.size();
//    else len = t.size();
//
//    for (int i = 1; i <= len; i++)
//    {
//        c1[i] += a1[i] + b1[i];
//        c1[i + 1] = c1[i] / 10;
//        c1[i] %= 10;
//    }
//
//    if (c1[len + 1])
//        len++;
//    for (int i = len; i >= 1; i--)
//        cout << c1[i];
//}
//
//int main()
//{
//    string s, t;
//    cin >> s >> t;
//    for (int i = s.size() - 1, j = 1; i >= 0; i--, j++)
//        a1[j] = s[i] - 48;
//    for (int i = t.size() - 1, j = 1; i >= 0; i--, j++)
//        b1[j] = t[i] - 48;
//    p1601(s, t);
//    cout << endl;
//    system("pause");
//    return 0;
//}