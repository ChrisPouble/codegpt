#include <iostream>
using namespace std;

//int s[40], top = 0, a, x, n, m;
//string cb1;
//int main() {
//    cin >> n >> cb1;
//    int N = 1;
//    for (int i = cb1.size(); i > 0; i--) {
//        if ('0' <= cb1[i] && '9' >= cb1[i]) 
//            a += (cb1[i] - '0') * n;
//        else a += (cb1[i] - 'A' + 10) * n;
//        N *= n;
//    }
//
//    cin >> m;
//    while (a) {
//        s[++top] = a % m;
//        a = a / m;
//    }
//
//    while (top) {
//        x = s[top];
//        top--;
//        if (x <= 9) cout << (char)(x + 48);
//        else cout << (char)(x + 55);
//    }
//    system ("pause");
//    return 0;
//}