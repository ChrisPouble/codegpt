//#include <iostream>
//using namespace std;
//
//string s;
//int a[510], b, c[510], d; //被除数、除数、商、余数
//void gaojingchu() {
//    int t = 0;
//    for (int i = 1; i <= s.size(); i++) {
//        t = t * 10 + a[i];
//        c[i] = t / b;
//        t %= b;
//    }
//    d = t;
//    int temp = 1;
//    while (c[temp] == 0) temp++;
//    for (int i = temp; i <= s.size(); i++) cout << c[i];
//    if (d != 0) cout << "......" << d << endl;
//}
//
//int main() {
//    cin >> s >> b;
//    for (int i = 1; i <= s.size(); i++)
//        a[i] = s[i - 1] - 48;
//    gaojingchu();
//    return 0;
//}