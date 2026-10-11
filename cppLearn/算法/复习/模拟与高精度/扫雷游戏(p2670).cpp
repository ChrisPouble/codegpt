//#include <iostream>
//using namespace std;
//
//char a1[105][105], c1[105][105];
//const int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
//const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//void p2670(int n, int m)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (a1[i][j] == '*')
//            {
//                c1[i][j] = '*';
//                for (int k = 0; k < 8; k++)
//                    if (a1[i + dx[k]][j + dy[k]] != '*') c1[i + dx[k]][j + dy[k]]++;
//            }
//        }
//    }
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> a1[i][j];
//        }
//    }
//    memset(c1, '0', sizeof(c1));
//    p2670(n, m);
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++)
//            cout << c1[i][j];
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}