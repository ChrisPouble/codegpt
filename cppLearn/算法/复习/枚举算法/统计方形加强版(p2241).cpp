#include <iostream>
using namespace std;

//int main()
//{
//    long long n = 2, m = 3;
//    long long x1, x2, y1, y2, squ = 0, rel = 0;
//    cin >> m >> n;
//    
//    //方法一：四个参数可以确定一个长方形：左下顶点坐标 (x1,y1) 和右上顶点坐标(x2, y2)
//    //思路：用四重循环，直接枚举4个参数，即两横边两竖边。
//    for (x1 = 1; x1 <= n; x1++)
//    {
//        for (y1 = 1; y1 <= m; y1++)
//        {
//            for (x2 = x1 + 1; x2 <= n; x2++) //x2从x1+1起，不重复不遗漏
//            {
//                for (y2 = y1 + 1; y2 <= m; y2++) //同上
//                {
//                    if (x2 - x1 == y2 - y1) squ++; //正方形，两边长相等
//                    else rel++; //长方形
//                }
//            }
//        }
//    }
//    cout << squ  << " " << rel << endl;
//
//    //方法二：固定其中一个顶点为(x, y)，计算长/正方形个数。
//    //思路：位于同一对角线上所有点均可构成正方形，除自身所在行列外，所有其它点均可与其构成长方
//    //形；故直接得长方形数为 nm – 正方形数。
//    //每一个长 / 正方形均被其 4 个顶点各计算一次。因此，最终答案需要除以 4。
//    for (long long x = 0; x <= n; x++)
//    {
//        for (long long y = 0; y <= m; y++)
//        {
//            long long tmp = min(x, y)
//                + min(y, n - x)
//                + min(n - x, m - y)
//                + min(x, m - y);
//            squ += tmp;
//            rel += n * m - tmp;
//        }
//    }
//    cout << squ / 4 << " " << rel / 4 << endl;
//
//    //方法三：只需考虑右上角为 (x, y) 的情况，因此计算斜线上的顶点时，只需要向左下角一个方向拓展！
//    //（先算 4 个方向，再除以 4，可谓是画蛇添足啊……）
//    for (long long x = 0; x <= n; x++)
//    {
//        for (long long y = 0; y <= m; y++)
//        {
//            long long tmp = min(x, y);
//            squ += tmp;
//            rel += n * m - tmp;
//        }
//    }
//    cout << squ << " " << rel << endl;
//    system("pause");
//    return 0;
//}