#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 10;

int n, m, a[N];
ll k, tree[N];

int lowbit(int x) { return x & -x; }
void update(int x, int d) { while (x <= n) { tree[x] += d, x += lowbit(x); } }
ll get(int x) { ll res = 0; while (x) { res += tree[x]; x -= lowbit(x); } return res; }

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        int p = max(i - m + 1, 1) - 1;
        if (get(i) + a[i] - get(p) <= k) {
            update(i, a[i]);
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}