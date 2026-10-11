#include <iostream>
#include <iomanip>
using namespace std;

int n2, r, a4[30];
//int main()
//{
//    cin >> n2 >> r;
//    int U = (1 << n2) - 1;
//    for (int s = U; s >= 0; s--) { //从全集枚举到0
//        int cnt = 0;
//        for (int i = 0; i < n2; i++)
//            if (s & (1 << i)) a4[cnt++] = i; //记录每一位
//        if (cnt == r) {
//            for (int i = r - 1; i >= 0; i--)
//                cout << setw(3) << n2 - a4[i]; //因为用高位表示1，所以要反过来输出
//            cout << endl;
//        }
//    }
//    system("pause");
//    return 0;
//}