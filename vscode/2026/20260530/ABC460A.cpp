#include <bits/stdc++.h>
using namespace std;

int n, m;
int main() {
    cin >> n >> m;

    int ans = 0;
    while (m) {
        ans++;
        m = n % m;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}