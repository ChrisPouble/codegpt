#include <iostream>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], n, m;
void push(int x) {
    a[++n] = x;
    int u = n;
    while (u / 2 > 0) {
        if (a[u / 2] < x) break;
        swap(a[u / 2], a[u]);
        u /= 2;
    }
}

void pop() {
    a[1] = a[n--];
    int u = 1, t;
    while (u <= n) {
        if (2 * u <= n && 2 * u + 1 <= n)
            if (a[2 * u] < a[2 * u + 1]) t = 2 * u;
            else t = 2 * u + 1;
        else if (2 * u <= n && 2 * u + 1 > n) t = 2 * u;
        else break;
        if (a[u] < a[t]) break;
        else {
            swap(a[u], a[t]);
            u = t;
        }
    }
}

//int main() {
//    int op, x; cin >> m;
//    for (int i = 1; i <= m; i++) {
//        cin >> op;
//        switch (op) {
//            case 1:
//                cin >> x;
//                push(x);
//                break;
//            case 2:
//                cout << a[1] << endl;
//                break;
//            case 3:
//                pop();
//                break;
//            default:
//                break;
//        }
//    }
//    system("pause");
//    return 0;
//}