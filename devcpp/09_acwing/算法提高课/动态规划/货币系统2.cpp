#include <bits/stdc++.h>
#define maxn 110
#define inf 25010
#define endl "\n"
using namespace std;

int T, n, a[maxn], f[inf];
void solve() {
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1); //排序
    f[0] = 1; //初始化
    int maxm = a[n], ans = 0; //maxm是最大的数
    for (int i = 1; i <= n; i++) {
        if(f[a[i]]) continue; //由于已经排好序了，就不用担心后面的数更新自己了。一个数被标记成1了，表示别的数就没有意义了。
        ans++; //边算DP，边记答案
        for (int j = a[i]; j <= maxm; j++)
            if(f[j - a[i]]) f[j] = 1; //f[j - a[i]] 能被表示，f[j] 就能被表示
    }
    cout << ans << endl;
}

int main() {
    cin >> T;
    while(T--) solve();
    return 0;
}
