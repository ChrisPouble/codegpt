#include <iostream>
using namespace std;

int a2[10005], n2, m2, sum;
void pushin(int x) {
    a2[++n2] = x;
    int u = n2;
    while (u / 2 > 0) {
        if (a2[u / 2] < x) break;
        swap(a2[u], a2[u / 2]);
        u = u / 2;
    }
}

void popout() {
    a2[1] = a2[n2--];
    int u = 1, t;
    while (u <= n2) {
        if (2 * u <= n2 && 2 * u + 1 <= n2)
            if (a2[2 * u] < a2[2 * u + 1]) t = 2 * u;
            else t = 2 * u + 1;
        else if (2 * u <= n2 && 2 * u + 1 > n2) t = 2 * u;
        else break;
        if (a2[u] < a2[t]) break;
        else {
            swap(a2[u], a2[t]);
            u = t;
        }
    }
}

//int main() {
//    int x; cin >> m2;
//    for (int i = 1; i <= m2; i++) {
//        cin >> x;
//        pushin(x);
//    }
//
//    for (int i = 1; i < m2; i++) {
//        int t1 = a2[1]; popout();
//        int t2 = a2[1]; popout();
//        sum += t1 + t2;
//        pushin(t1 + t2);
//    }
//    cout << sum << endl;
//    system("pause");
//    return 0;
//}