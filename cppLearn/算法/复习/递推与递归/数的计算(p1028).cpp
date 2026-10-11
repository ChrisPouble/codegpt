//#include <iostream>
//using namespace std;
//
//int n, t[1010];
//int sol(int sum)
//{
//    int ans = 1;
//    for (int i = 1; i <= sum / 2; i++) {
//        if (t[i] != -1) ans += t[i];
//        else {
//            t[i] = sol(i);
//            ans += t[i];
//        }
//    }
//    return ans;
//}
//
//int main()
//{
//    cin >> n;
//    memset(t, -1, sizeof(t));
//    cout << sol(n) << endl;
//    system("pause");
//    return 0;
//}