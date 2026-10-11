#include <iostream>
using namespace std;

long long a3[100005] = { 0 };
//int main() {
//    long long n, x, ans = 0; //此处要开long long
//    cin >> n >> x;
//    for (int i = 1; i <= n; i++)
//        cin >> a3[i];
//    if (a3[1] > x) ans += a3[1] - x, a3[1] = x; //如果开头大了，就减到x
//    for (int i = 2; i <= n; i++) {
//        if (a3[i] + a3[i - 1] > x) { //两数相加大于x
//            int temp = a3[i] + a3[i - 1] - x;
//            ans += temp;
//            a3[i] -= temp; //后面的数减掉temp
//        }
//    }
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}