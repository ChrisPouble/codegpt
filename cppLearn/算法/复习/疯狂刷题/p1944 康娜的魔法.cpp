//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int p[3];
//void output(int x) {
//    if (x == 0) cout << "QAQ" << endl;
//    else cout << x << endl;
//}
//
//int main() {
//    while (cin >> p[0] >> p[1] >> p[2]) {
//        sort(p, p + 3);
//
//        //如果p[1] == 0, 那么p[0]也肯定 == 0, 此时只需要输出QAQ既可
//        if (p[1] == 0) output(0);
//
//        //p[0]和p[1]出现次数奇偶性相同, 存在一种方案只需要p[1]次操作, 并且最优
//        else if (p[1] % 2 == p[0] % 2) output(p[1]);
//
//        //p[0]和p[1]出现次数奇偶性不同, 存在一种方案只需要p[2]次操作, 并且最优
//        else output(p[2]);
//    }
//    return 0;
//}
///*
//3 5 5
//*/