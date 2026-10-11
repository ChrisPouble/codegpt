//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int a[25], n = 4 * 4, ans = 0;
//int b1[5][5], b2[5][5], b3[5][5];
//void sum(int x)
//{
//    //方法一
//        int ans = 0;
//    for (int a = 1; a <= 4; a++)
//        for (int b = 1; b <= 4; b++)
//            for (int c = 1; c <= 4; c++)
//                for (int d = 1; d <= 4; d++)
//                    for (int e = 1; e <= 4; e++)
//                        for (int f = 1; f <= 4; f++)
//                            for (int g = 1; g <= 4; g++)
//                                for (int h = 1; h <= 4; h++)
//                                    for (int i = 1; i <= 4; i++)
//                                        for (int j = 1; j <= 4; j++)
//                                            for (int k = 1; k <= 4; k++)
//                                                for (int l = 1; l <= 4; l++)
//                                                    for (int m = 1; m <= 4; m++)
//                                                        for (int n = 1; n <= 4; n++)
//                                                            for (int o = 1; o <= 4; o++)
//                                                                for (int p = 1; p <= 4; p++)
//                                                                    if (a != b && b != c && c != d && a != c && b != d && a != d
//                                                                        && e != f && f != g && g != h && e != g && f != h && e != h
//                                                                        && i != j && j != k && k != l && i != k && j != l && i != l
//                                                                        && m != n && n != o && o != p && m != o && n != p && m != p
//                                                                        && a != e && e != i && i != m && a != i && e != m && a != m
//                                                                        && b != f && f != j && j != n && b != j && f != n && b != n
//                                                                        && c != g && g != k && k != o && c != k && g != o && c != o
//                                                                        && d != h && h != l && l != p && d != l && h != p && d != p
//                                                                        && a != f && b != e && c != h && d != g && i != n && j != m
//                                                                        && k != p && l != o)
//                                                                        ans++;
//
//    //方法二
//        int c1[5], c2[5], c3[5], c4[5];
//    for (int i = 1; i <= 4; i++)
//    {
//        c1[i] = i;
//        c2[i] = i;
//        c3[i] = i;
//        c4[i] = i;
//    }
//
//    int i, j, k, l;
//    for (i = 1; i <= 24; i++)
//    {
//        next_permutation(c1 + 1, c1 + 5);
//        for (j = 1; j <= 24; j++)
//        {
//            next_permutation(c2 + 1, c2 + 5);
//            for (k = 1; k <= 24; k++)
//            {
//                next_permutation(c3 + 1, c3 + 5);
//                for (l = 1; l <= 24; l++)
//                {
//                    next_permutation(c4 + 1, c4 + 5);
//                    if (c1[1] != c2[1] && c2[1] != c3[1] &&
//                        c3[1] != c4[1] && c1[1] != c3[1] &&
//                        c2[1] != c4[1] && c1[1] != c4[1] &&
//                        c1[2] != c2[2] && c2[2] != c3[2] &&
//                        c3[2] != c4[2] && c1[2] != c3[2] &&
//                        c2[2] != c4[2] && c1[2] != c4[2] &&
//                        c1[3] != c2[3] && c2[3] != c3[3] &&
//                        c3[3] != c4[3] && c1[3] != c3[3] &&
//                        c2[3] != c4[3] && c1[3] != c4[3] &&
//                        c1[4] != c2[4] && c2[4] != c3[4] &&
//                        c3[4] != c4[4] && c1[4] != c3[4] &&
//                        c2[4] != c4[4] && c1[4] != c4[4] &&
//                        c1[1] != c2[2] && c1[2] != c2[1] &&
//                        c1[3] != c2[4] && c1[4] != c2[3] &&
//                        c3[1] != c4[2] && c3[2] != c4[1] &&
//                        c3[3] != c4[4] && c3[4] != c4[3])
//                        ans++;
//                }
//            }
//        }
//    }
//
//    //方法三
//        if (x > n)
//        {
//            ans++;
//            for (int i = 1; i <= n; i++)
//            {
//                cout << a[i] << " ";
//                if (i % 4 == 0) cout << endl;
//            }
//            cout << endl;
//            return;
//        }
//
//    int row = (x - 1) / 4 + 1;
//    int col = (x - 1) % 4 + 1;
//    int block = (row - 1) / 2 * 2 + (col - 1) / 2 + 1;
//
//    for (int i = 1; i <= 4; i++)
//        if (b1[row][i] == 0 && b2[col][i] == 0 && b3[block][i] == 0)
//        {
//            a[x] = i;
//            b1[row][i] = 1; b2[col][i] = 1; b3[block][i] = 1;
//            sum(x + 1);
//            b1[row][i] = 0; b2[col][i] = 0; b3[block][i] = 0;
//        }
//}
//
//int main()
//{
//    sum(1);
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}