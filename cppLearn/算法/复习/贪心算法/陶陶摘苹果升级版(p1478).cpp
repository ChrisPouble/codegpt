#include <iostream>
#include <algorithm>
using namespace std;

struct apple {
    int x, y; //苹果到地面的高度、摘这个苹果需要的力气
}ap[5010];

bool p1478(apple a, apple b) {
    return a.y < b.y;
}

//int main() {
//    int sum = 0;
//    int n, s; cin >> n >> s; //苹果总数、陶陶的力气
//    int a, b; cin >> a >> b; //椅子高度、陶陶手伸直的长度
//    for (int i = 1; i <= n; i++)
//        cin >> ap[i].x >> ap[i].y;
//    b += a;
//    sort(ap + 1, ap + n + 1, p1478);
//    for (int i = 1; i <= n; i++)
//        if (b >= ap[i].x && s >= ap[i].y) s -= ap[i].y, sum++;
//    cout << sum << endl;
//    system("pause");
//    return 0;
//}