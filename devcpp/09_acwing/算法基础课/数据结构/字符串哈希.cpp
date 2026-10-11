#include <bits/stdc++.h>
#define maxn 100010
#define mod 200003
#define int unsigned long long //相当于% 2^64 
using namespace std;

const int P = 131;
int n, m, p[maxn], h[maxn];
char C[maxn];
int get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1]; //哈希 
}

signed main() {
    cin >> n >> m >> (C + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + C[i]; //转换为P进制 
    }
    while(m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (get(l1, r1) == get(l2, r2) ? "Yes" : "No") << "\n";
    }
    return 0;
}
