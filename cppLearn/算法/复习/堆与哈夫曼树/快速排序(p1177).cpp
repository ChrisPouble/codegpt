#include <iostream>
using namespace std;

int a1[10000], n1, m1;
void Push(int x) {
    a1[++n1] = x;
    int u = n1;
    while (u / 2 > 0) {
        if (a1[u / 2] < x) break;
        swap(a1[u], a1[u / 2]);
        u = u / 2;
    }
}

void Pop() {
    a1[1] = a1[n1--];
    int u = 1, t;
    while (u <= n1) {
        if (2 * u <= n1 && 2 * u + 1 <= n1)
            if (a1[2 * u] < a1[2 * u + 1]) t = 2 * u;
            else t = 2 * u + 1;
        else if (2 * u <= n1 && 2 * u + 1 > n1) t = 2 * u;
        else break;
        if (a1[u] < a1[t]) break;
        else {
            swap(a1[u], a1[t]);
            u = t;
        }
    }
}

//int main() {
//    int x; cin >> m1;
//    for (int i = 1; i <= m1; i++) {
//        cin >> x;
//        Push(x);
//    }
//
//    for (int i = 1; i <= m1; i++) {
//        cout << a1[1] << " ";
//        Pop();
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}