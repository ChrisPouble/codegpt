//#include <iostream>
//using namespace std;
//
//int a2[2002] = { 0 }, b2[2002] = { 0 }, c2[4005] = { 0 };
//void p1303(string s, string t)
//{
//    int len;
//    len = s.size() + t.size();
//    for (int i = 1; i <= s.size(); i++)
//    {
//        for (int j = 1; j <= t.size(); j++)
//        {
//            c2[i + j - 1] += a2[i] * b2[j];
//        }
//    }
//
//    for (int i = 1; i <= len; i++)
//    {
//        c2[i + 1] += c2[i] / 10;
//        c2[i] %= 10;
//    }
//
//    for (; !c2[len];) //È¥µôÇ°µ¼Áã
//        len--;
//    for (int i = max(1, len); i >= 1; i--)
//        cout << c2[i];
//}
//
//int main()
//{
//    string s, t;
//    cin >> s >> t;
//    for (int i = s.size() - 1; i >= 0; i--)
//        a2[s.size() - i] = s[i] - '0';
//    for (int i = t.size() - 1; i >= 0; i--)
//        b2[t.size() - i] = t[i] - '0';
//    p1303(s, t);
//    cout << endl;
//    system("pause");
//    return 0;
//}