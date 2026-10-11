#include <bits/stdc++.h>
#define maxn 5010
using namespace std;

int n, ans, k, f[maxn];
struct node {
    int x, y;
} a[maxn];

bool cmp(node x, node y) { return x.x < y.x; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i].y > a[j].y && f[j] + 1 > f[i])
                f[i] = f[j] + 1;
    }
	for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << endl;
    return 0;
}
