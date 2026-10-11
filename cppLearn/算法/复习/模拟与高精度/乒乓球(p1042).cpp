//#include <iostream>
//using namespace std;
//
//int n;
//bool a[90000];
//int main()
//{
//    while (1) {
//        char temp; cin >> temp;
//        if (temp == 'E') break;
//        else if (temp == 'W') a[++n] = 1; //华华赢
//        else if (temp == 'L') a[++n] = 0; //华华输
//        // 依照题意，若不属于这三种字符，则应忽略
//    }
//    for (int k = 0; k < 2; k++) {
//        int w = 0, l = 0;
//        for (int i = 1; i <= n; i++) {
//            if (a[i]) w++;
//            else l++;
//            if (k == 0) {
//                // 获胜者超过对应分数且超出对手2分
//                if (max(w, l) >= 11 && abs(w - l) >= 2) {
//                    cout << w << ":" << l << endl;
//                    w = l = 0;
//                }
//            } else {
//                if (max(w, l) >= 21 && abs(w - l) >= 2) {
//                    cout << w << ":" << l << endl;
//                    w = l = 0;
//                }
//            }
//        }
//        cout << w << ":" << l << endl;
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}