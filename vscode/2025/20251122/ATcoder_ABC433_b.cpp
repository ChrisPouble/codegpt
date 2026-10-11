#include <bits/stdc++.h>
using namespace std;

int n, a[110];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int is = 0, id = 1e9;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] > a[i]) {
                is = 1, id = j;
                break;
            }
        }

        if (!is) cout << -1 << "\n";
        else cout << id << endl;
    }    

    return 0;
}
