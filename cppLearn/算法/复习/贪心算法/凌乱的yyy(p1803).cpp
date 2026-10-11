#include <iostream>
#include <algorithm>
using namespace std;

struct contest {
    int a, b;
};

contest hash1[1000010];
bool p1803(contest a, contest b) {
    return a.b <= b.b;
}

//int main() {
//    int n, ans = 0, last;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> hash1[i].a >> hash1[i].b;
//
//    sort(hash1, hash1 + n, p1803);
//    ans = 1, last = hash1[0].b;
//    for (int i = 1; i < n; i++)
//        if (hash1[i].a >= last) ans++, last = hash1[i].b;
//    
//    cout << ans << endl;
//    system("pause");
//    return 0;
//}