#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int h, a;
}a2[105];

int n2, k, f1[100][105];
bool p1103(node a, node b) {
    return a.h < b.h;
}

//int main() {
//    int i, j, l;
//    cin >> n2 >> k;
//    for (i = 1; i <= n2; i++)
//        scanf ("%d%d", &a2[i].h, &a2[i].a);
//
//    sort(a2 + 1, a2 + n2 + 1, p1103);
//    for (i = 2; i <= n2; i++)
//        for (j = 0; j <= k; j++)
//            f1[i][j] = 1e9;
//
//    for (i = 2; i <= n2; i++) {
//        f1[i][0] = f1[i - 1][0] + abs(a2[i].a - a2[i - 1].a);
//        f1[i][i - 1] = 0;
//        for (l = 1; l < i; l++)
//            for (j = 0; j <= l && j <= k; j++)
//                f1[i][j + (i - l - 1)] = min
//                (f1[i][j + (i - l - 1)],
//                    f1[l][j] + abs(a2[i].a - a2[l].a));
//    }
//
//    for (i = 1; i <= n2; i++)
//        for (j = 0; j <= i; j++)
//            printf("f1[%d][%d]=%d\n", i, j, f1[i][j]);
//
//    int ans = 1e9;
//    for (i = 1; i <= n2; i++)
//        if (k - n2 + i >= 0) ans = min(ans, f1[i][k - n2 + i]);
//
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}