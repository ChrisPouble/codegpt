#include <bits/stdc++.h>
using namespace std;

int n, val;

int main() {
    cin >> n;

    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (int i = 1; i <= n; i++) {
        cin >> val; val = (1000 - (val % 1000)) % 1000;
        ans1 += val / 100, val -= (val / 100) * 100;
        ans2 += val / 10, val -= (val / 10) * 10;
        ans3 += val;
    }

    cout << ans3 << " " << ans2 << " " << ans1 << endl;

    return 0;
}