#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)

const int N = 2005;
int n, p, q, sg[N][N], b[N][N];

void solve() {
    int mx = 0;
    bool ans = 0;
    
    rep (i, 1, n) {
        cin >> p >> q;
        if (b[p][q] > mx) {
            ans = sg[p][q];
            mx = b[p][q];
        }
        
        if (b[p][q] == mx) {
            ans |= sg[p][q];
        }
    }
    
    puts(ans ? "MM" : "GG");
}

int main() {
    cin.tie(0)->ios::sync_with_stdio(false);

    rep (x, 1, 1000) {
    	rep (y, 1, x) {
            if (x % y == 0) {
                sg[x][y] = sg[y][x] = 1;
                b[x][y] = b[y][x] = 1;
            } else if (x / y >= 2) {
                sg[x][y] = sg[y][x] = 1;
                p = x / y;
                rep (i, 1, p)
                    if (!sg[x - i * y][y])
                        b[x][y] = max(b[x][y], b[x - i * y][y] + 1);
                b[y][x] = b[x][y];
            } else {
                p = x - y, q = y;
                sg[x][y] = sg[y][x] = sg[p][q] ^ 1;
                b[x][y] = b[y][x] = b[p][q] + 1;
            }
        }
    }

    while (cin >> n) solve();
    return 0;
} // 