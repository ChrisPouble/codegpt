#include <bits/stdc++.h>
using namespace std;

#define int long long

int x;
set<int> s;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> x;

    int siz = sqrt(abs(x)) + 10;
    for (int d = -siz; d <= siz; d++) {
        if ((x - d * d) % (2 * d - 1) == 0) {
            s.insert((x - d * d) / (2 * d - 1));
        }
    }

    cout << s.size() << endl;
    for (int v : s)
        cout << v << " ";
    
    system("pause");
    return 0;
}