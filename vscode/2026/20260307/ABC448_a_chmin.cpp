#include <bits/stdc++.h>
using namespace std;

int n, x;
int main() {
    cin >> n >> x;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (x > a) cout << 1 << endl, x = a;
        else cout << 0 << endl;
    }

    return 0;
}