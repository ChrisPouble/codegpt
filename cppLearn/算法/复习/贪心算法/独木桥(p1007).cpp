#include <iostream>
using namespace std;

//本题只要取每个人到0点和到L-1最小值, 再把所有人的最小值取最大值就能求出最小值
//本题只要取每个人到0点和到L-1最大值, 再把所有人的最大值取最大值就能求出最大值
//int main() {
//    int L, n, a, maxt = 0, mint = 0; cin >> L >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a;
//        mint = max(mint, min(a - 0, L + 1 - a));
//        maxt = max(maxt, max(a - 0, L + 1 - a));
//    }
//    cout << mint << " " << maxt << endl;
//    system("pause");
//    return 0;
//}