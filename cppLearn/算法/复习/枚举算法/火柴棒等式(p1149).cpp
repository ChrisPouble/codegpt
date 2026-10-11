#include <iostream>
using namespace std;

int s[25] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//int main()
//{
//    int n, ans = 0; cin >> n;
//    for (int i = 10; i <= 24; i++)
//        s[i] = s[i / 10 % 10] + s[i % 10];
//    
//    for (int i = 0; i <= n; i++)
//        for (int j = 0; j <= n; j++)
//        {
//            int sum = i + j;
//            if (sum > 24) continue;
//            if (s[i] + s[j] + s[sum] + 4 == n) ans++;
//        }
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}