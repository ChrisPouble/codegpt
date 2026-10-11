#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 10;

int n, q, a[N];
int lg[N], sup[N][20];

void Init() {
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;
    
    for (int i = 1; i <= n; i++)
        sup[i][0] = i;

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            if (a[sup[i][j - 1]] < a[sup[i + (1 << (j - 1))][j - 1]])
                sup[i][j] = sup[i][j - 1];
            else
                sup[i][j] = sup[i + (1 << (j - 1))][j - 1];
        }
    }
}

int get(int l, int r) {
    int len = lg[r - l + 1];
    if (a[sup[l][len]] < a[sup[r - (1 << len) + 1][len]])
        return sup[l][len];
    else
        return sup[r - (1 << len) + 1][len];
}

ll Sl[N], dpl[N], lpos[N];
ll Sr[N], dpr[N], rpos[N];
int stk[N], top;

void build() {
    top = 0;
    for (int i = 1; i <= n; i++) {
        while (top && a[stk[top]] >= a[i]) top--;
        lpos[i] = (top ? stk[top] : 0);
        stk[++top] = i;
    }

    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[stk[top]] > a[i]) top--;
        rpos[i] = (top ? stk[top] : n + 1);
        stk[++top] = i;
    }

    for (int i = 1; i <= n; i++)
        dpl[i] = dpl[lpos[i]] + a[i] * (i - lpos[i]);

    for (int i = n; i >= 1; i--)
        dpr[i] = dpr[rpos[i]] + a[i] * (rpos[i] - i);
    
    for (int i = 1; i <= n; i++) {
        Sl[i] = Sl[i - 1] + dpl[i];
        Sr[i] = Sr[i - 1] + dpr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    Init(), build();

    for (int pro = 1; pro <= q; pro++) {
        int l, r; cin >> l >> r;
        int p = get(l, r);
        
        ll mid = 1ll * a[p] * (p - l + 1) * (r - p + 1);
        ll left = 1ll * (Sr[p - 1] - Sr[l - 1]) - (p - l) * dpr[p];
        ll right = 1ll * (Sl[r] - Sl[p]) - (r - p) * dpl[p];
        
        cout << mid + left + right << "\n";
    }

    return 0;
}