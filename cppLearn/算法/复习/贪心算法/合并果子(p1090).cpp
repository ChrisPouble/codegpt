#include <iostream>
#include <algorithm>
using namespace std;

int a1[10005], a2[10005];
//int main() {
//    int n, n2 = 0; cin >> n;
//    long long ans = 0;
//    memset(a1, 127, sizeof(a1));
//    memset(a2, 127, sizeof(a2));
//    for (int i = 0; i < n; i++)
//        cin >> a1[i];
//    sort(a1, a1 + n);
//    int i = 0, j = 0;
//    for (int k = 0; k < n - 1; k++) {
//        int w = a1[i] < a2[j] ? a1[i++] : a2[j++]; //取最小值
//        w += a1[i] < a2[j] ? a1[i++] : a2[j++]; //第二次取最小值
//        a2[n2++] = w; //加入第二个队列
//        ans += w; //计算价值
//    }
//    cout << ans << endl;
//    return 0;
//}