//#include <iostream>
//using namespace std;
//
//int y, sum, a[100][100]; bool vi[30][30]; string s, t;
//int main() {
//    cin >> y;
//    cin >> s >> t;
//    //初始化弗洛伊德算法数组
//    for (int i = 1; i <= 26; i++)
//        for (int j = 1; j <= 26; j++)
//            a[i][j] = 2e8;
//
//    for (int i = 1; i <= 26; i++)
//        for (int j = 1; j <= y; j++)
//            if (i + j > 26) a[i][(i + j) % 26] = j, vi[i][i + j] = true;
//            else a[i][i + j] = j, vi[i][i + j] = true;
//
//    for (int i = 1; i <= 26; i++)
//        a[i][i] = 0;
//
//    //弗洛伊德算法过程
//    for (int k = 1; k <= 26; k++)
//        for (int i = 1; i <= 26; i++)
//            for (int j = 1; j < 26; j++)
//                if (a[i][j] > a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
//
//    //输出
//    for (int i = 0; i < s.size(); i++)
//        if (a[s[i] - 65 + 1][t[i] - 65 + 1] % y == 0) sum += (a[s[i] - 65 + 1][t[i] - 65 + 1]) / y;
//        else sum += ((a[s[i] - 65 + 1][t[i] - 65 + 1]) / y) + 1;
//    cout << sum << endl;
//    return 0;
//}
///*
//3
//X
//E
//*/