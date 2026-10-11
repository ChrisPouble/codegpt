#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, ans = 1;
struct node {
    int a, b;
}a[maxn];

bool cmp(node x, node y) {
    return x.b < y.b;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].a >> a[i].b;
    sort(a, a + n, cmp);
    int x = a[0].b;
    for (int i = 1; i < n; i++)
        if(x < a[i].a) x = a[i].b, ans++;
    cout << ans << endl;
    return 0;
}
