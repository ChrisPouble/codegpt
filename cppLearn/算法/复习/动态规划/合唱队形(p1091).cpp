#include <iostream>
#include <algorithm>
using namespace std;

#define t 105
int a1[t], t1[t], g1[t];
//int main() {
//    int n; cin >> n;
//    for (int i = 1; i <= n; i++)
//        cin >> a1[i];
//    
//    for (int i = 1; i <= n; i++)
//        t1[i] = g1[i] = 1;
// 
//    for (int i = 2; i <= n; i++)
//        for (int j = 1; j < i; j++)
//            if (a1[j] < a1[i]) t1[i] = max(t1[i], t1[j] + 1);
//
//    for (int i = 2; i <= n; i++)
//        for (int j = 1; j < i; j++)
//            if (a1[j] > a1[i]) g1[i] = max(g1[i], g1[j] + 1);
//
//    int ans = 0;
//    for (int i = 1; i <= n; i++)
//        ans = max(ans, t1[i] + g1[i] - 1);
//
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}