#include <bits/stdc++.h>
using namespace std;

const int N = 25;

int n, a[N];
int ans;

int get(double x) {
    return x > 0 ? 1 : -1;
}

void dfs(int x, double now, int sum) {
    if (x > n) {
        ans = max(ans, sum);
        return ;
    }

    dfs(x + 1, now + a[x], sum + (get(now) + get(now + a[x]) == 0));
    dfs(x + 1, now - a[x], sum + (get(now) + get(now - a[x]) == 0));
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dfs(1, 0.5, 0);

    cout << ans << endl;

    system("pause");
    return 0;
}