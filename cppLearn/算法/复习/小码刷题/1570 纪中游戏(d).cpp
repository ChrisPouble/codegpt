//#include <iostream>
//using namespace std;
//
//int a[7] = { -1, 1, 6, 4, 3, 2, 5 }; //上、下、左、右、前、后
//void left() {
//    int temp = a[4];
//    a[4] = a[1];
//    a[1] = a[3];
//    a[3] = a[2];
//    a[2] = temp;
//}
//
//void right() {
//    int temp = a[3];
//    a[3] = a[1];
//    a[1] = a[4];
//    a[4] = a[2];
//    a[2] = temp;
//}
//
//
//void down() {
//    int temp = a[5];
//    a[5] = a[1];
//    a[1] = a[6];
//    a[6] = a[2];
//    a[2] = temp;
//}
//
//int main() {
//    int R, C; long long sum = 0; cin >> R >> C;
//    for (int i = 1; i <= R; i++) {
//        sum += (C / 4) * 14;
//        for (int j = 1; j <= C % 4; j++) {
//            sum += a[1];
//            if (i % 2 == 1) {
//                if (j < C % 4) left();
//            }
//            else {
//                if (j < C % 4) right();
//            }
//        }
//        down();
//    }
//    cout << sum << endl;
//    return 0;
//}
///*
//89995 89989
//28344960194
//*/