//#include <iostream>
//using namespace std;
//
//int a[510], b[510], c[512], n1, n2, n3; string s;
//int main() {
//    cin >> s; n1 = s.size();
//    for (int i = 0; i < n1; i++)
//        a[i + 1] = s[n1 - i - 1] - 48;
//    cin >> s; n2 = s.size();
//    for (int i = 0; i < n2; i++)
//        b[i + 1] = s[n2 - i - 1] - 48;
//    n3 = max(n1, n2);
//    for (int i = 1; i <= n3 + 1; i++) {
//        int x = a[i] + b[i];
//        c[i] += x;
//        if (c[i] >= 10) c[i + 1] += 1, c[i] -= 10;
//    }
//    bool vi = false;
//    for (int i = n3 + 1; i >= 1; i--) {
//        if (c[i] != 0) vi = true;
//        if (vi) cout << c[i];
//    }
//    return 0;
//}
///*
//1001
//9099
//*/