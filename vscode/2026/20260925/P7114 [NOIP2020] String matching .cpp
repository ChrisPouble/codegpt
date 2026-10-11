#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned ll;
const int N = (1 << 20) + 10;

string str; int len;
ull fac[N], pre[N];

int lowbit(int x) { return x & -x; }
int convert(char c) { return c - 'a' + 1; }
ull get(int l, int r) { return pre[r] - pre[l - 1] * fac[r - l + 1]; }

void Init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * 27;
    }
}

int sup[N], rep[N];

void OurInit() {
    cin >> str, len = str.size(), str = " " + str;

    pre[0] = 0;
    for (int i = 1; i <= len; i++)
        pre[i] = pre[i - 1] * 27 + convert(str[i]);

    for (int i = 1, mask = 0; i <= len; i++) {
        mask ^= (1 << convert(str[i]));
        sup[i] = __builtin_popcount(mask);
    }

    for (int i = len, mask = 0; i >= 1; i--) {
        mask ^= (1 << convert(str[i]));
        rep[i] = __builtin_popcount(mask);
    }
}

int tree[N];

void add(int x, int d) {
    for (x++; x <= 30; tree[x] += d, x += lowbit(x)) ;
}

int query(int x) {
    x++;
    for (int res = 0; ; res += tree[x], x -= lowbit(x))
        if (!x) return res;
}

void solve() {
    OurInit(); ll ans = 0;
    
    for (int L = 2; L < len; L++) {
        add(sup[L - 1], 1);
        
        ull base = get(1, L);

        for (int k = 1; k * L < len; k++) {
            if (k > 1 && get((k - 1) * L + 1, k * L) != base)
                break;

            ans += query(rep[k * L + 1]);
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= 30; i++)
        tree[i] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Init();

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}