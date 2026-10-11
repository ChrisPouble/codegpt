#include <iostream>
using namespace std;

int mc[10001];
//int main() {
//    int n, sum; cin >> n;
//    for (int i = 1; i <= n; i++)
//        cin >> mc[i];
//
//    sum = mc[1];
//    /*
//      ----------  如果mc[i] > mc[i - 1], 那么sum += mc[i] - mc[i - 1]
//        | | | |
//        | | | |
//        | | | |
//        | | | |
//            | |
//            | |
//
//      ----------  如果mc[i] <= mc[i - 1], 那么啥事不干
//        | | | |
//        | | | |
//        | | | |
//        | | | |
//        | |
//        | |
//    */
//    for (int i = 2; i <= n; i++)
//        if (mc[i] > mc[i - 1]) sum += mc[i] - mc[i - 1];
//    cout << sum << endl;
//    system("pause");
//    return 0;
//}