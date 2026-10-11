#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, cnt, a[N], q[N];
int find(int x) {
    int l = 1, r = cnt, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if(q[mid] < x) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int x = find(a[i]);
        if(q[x + 1]) q[x + 1] = min(q[x + 1], a[i]);
        else q[x + 1] = a[i];
        if(x + 1 > cnt) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
