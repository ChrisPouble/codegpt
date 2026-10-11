#include <bits/stdc++.h>
using namespace std;

int n, c, a[100010];
bool P(int d) {
    int cnt = 0, last = -1e9; //last记录上一头牛的安置坐标
    for (int i = 1; i <= n; i++)
        if (a[i] - last >= d) //能安置就立马安置
            last = a[i], cnt++;
    return cnt >= c;
}

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e9 + 10, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if(P(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << endl;
}