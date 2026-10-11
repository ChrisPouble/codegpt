#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << 1 << " ";
        for (int i = 2; i <= m - 1; i++)
            cout << 2 << " ";
        cout << 1 << " ";
        return 0;
    }

    if (m == 1) {
        cout << 1 << "\n";
        for (int i = 2; i <= n - 1; i++)
            cout << 2 << "\n";
        cout << 1 << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++, puts("")) {
        for (int j = 1; j <= m; j++) {
            int ki = (i == 1 || i == n);
            int kj = (j == 1 || j == m);
            if (ki + kj == 2) cout << "2 ";
            if (ki + kj == 1) cout << "3 ";
            if (ki + kj == 0) cout << "4 "; 
        }
    }

    system("pause");
    return 0;
}