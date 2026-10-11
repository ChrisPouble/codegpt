#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define int long long

const int N = 5e5 + 10;
const int mod = 1e9 + 9;
const int D = 5; // 偏移量，防边界

int n, bl[N], wh[N], tl[N], tr[N];
ll f[N], tree[N];

vector<int> linker[N];

int lowbit(int x) {
    return x & -x;
}

void insert(int x, int v) {
    x += D;

    while (x <= n + D) {
        tree[x] = (tree[x] + v + mod) % mod;
        x += lowbit(x);
    }
}

int query(int x) {
    x += D;

    ll res = 0;
    while (x) res += tree[x], x -= lowbit(x);
    return (int)(res % mod);
}

string s;
signed main() {
    cin >> s;
    
    n = s.size(), s = ' ' + s;
    
    for (int i = n; i >= 1; i--) {
        if (s[i] == 'W') bl[i] = 0;
        else bl[i] = bl[i + 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B') wh[i] = 0;
        else wh[i] = wh[i - 1] + 1;
    }

    for (int i = 0; i <= n; i += 2) {
        if (s[i] != 'B' && s[i + 1] != 'W') {
            tl[i] = i + 2;
            tr[i] = min(i + bl[i + 1] * 2 + 2, n + 1);
            linker[tl[i]].push_back(i);
            linker[tr[i]].push_back(i);
        }
    }

    f[0] = 1;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 0; j < linker[i].size(); j++) {
            if (tl[linker[i][j]] == i) insert(linker[i][j], f[linker[i][j]]);
            else insert(linker[i][j], -f[linker[i][j]]);
        }

        if (s[i] != 'B') {
            int wl = max(i - wh[i] * 2 - 2, -1), wr = i - 2;
            f[i] = (query(wr) - query(wl) + mod) % mod;
        }
    }

    cout << f[n] << endl;
    return 0;
}