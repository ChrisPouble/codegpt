#include <bits/stdc++.h>
using namespace std;

int get(int l, int r) {
    return (r - l + 1) % rand() + l;
}

signed main() {
	freopen("text.in", "w", stdout); // 输出返回的信息
    freopen("text.out", "r", stdin); // 输入送过来的信息

    int x;
    int ans = get(1, 1e9);

    while (1) {
        cin >> x;

        if (x == ans) {
            cout << 0 << endl;
            break;
        }
        else if (x < ans) cout << -1 << endl;
        else if (x > ans) cout << 1 << endl;
    }

	return 0;
}