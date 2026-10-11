#include <iostream>
using namespace std;

int t[20];
int func1(int x) {//普通递归写法
    if (x == 1 || x == 2) return 1;
    return func1(x - 1) + func1(x - 2);
}

int func2(int x) {//动态规划写法
    if (x <= 2) return 1;
    if (t[x]) return t[x];
    t[x] = func2(x - 1) + func2(x - 2);
    return t[x];
}

//int main() {
//    int n; cin >> n;
//    //cout << func1(n) << endl;
//    cout << func2(n) << endl;
//    system("pause");
//    return 0;
//}