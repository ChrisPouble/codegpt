//#include <iostream>
//using namespace std;
//
//void dg(int x) {
//    if (x == 2) {
//        cout << "2";
//        return;
//    } else if (x == 1) {
//        cout << "2(0)";
//        return;
//    }
//    int sum = 0, i;
//    for (i = 1; i * 2 <= x; i *= 2, sum++);
//    if (sum == 1) {
//        cout << 2;
//        if (x - i != 0) {
//            cout << "+";
//            dg(x - i);
//        }
//    } else {
//        cout << "2(";
//        dg(sum);
//        if (x - i == 0) cout << ")";
//        else {
//            cout << ")+";
//            dg(x - i);
//        }
//    }
//}
//
//int main() {
//    int n; cin >> n;
//    if(n != 0) dg(n);
//    return 0;
//}