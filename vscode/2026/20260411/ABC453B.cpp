#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, x, a[N];
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> x;

    int lst = 0;
    for (int i = 0; i <= n; i++)
        cin >> a[i];

    cout << lst << " " << a[0] << endl;

    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - a[lst]) >= x) {
            lst = i;
            cout << i << " " << a[i] << endl;
        }
    }

    system("pause");
    return 0;
}