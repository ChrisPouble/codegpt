#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9 + 10;
struct food{
    int suan, ku;
}a[15];

void dfs(int x, int s, int k) {
    if(x > n) {
        ans = min(ans, abs(s - k));
        return;
    }
    dfs(x + 1, s * a[x].suan, k + a[x].ku);
    dfs(x + 1, s, k);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].suan >> a[i].ku;
    for (int i = 1; i <= n; i++)
        dfs(i + 1, a[i].suan, a[i].ku);
    cout << ans << endl;
    return 0;
}