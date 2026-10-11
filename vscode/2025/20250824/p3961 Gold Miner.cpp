#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 210;
const int M = 4e4 + 10;
int n, T, cnt, f[M];
struct node {
    int x, y, v, t;
} a[N];

vector<node> ve[N];
bool vis[N];

bool cmp(node x, node y) {
    return x.x < y.x;
}

signed main() {
    cin >> n >> T;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t >> a[i].v;
    }
    
    sort(a + 1, a + 1 + n, cmp);
    
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ve[++cnt].push_back(a[i]);
        
        for (int j = i + 1; j <= n; j++) {
            if (a[i].x * a[j].y == a[i].y * a[j].x) {
                ve[cnt].push_back(a[j]);
                vis[j] = true;
            }
        }
    }
    
    for (int i = 1; i <= cnt; i++) {
        for (int t = T; t >= 0; t--) {
            int st = 0, sv = 0;
            for (auto p : ve[i]) {
                st += p.t;
                sv += p.v;
            }
            
            for (int j = ve[i].size() - 1; j >= 0; j--) {
                if (t >= st) f[t] = max(f[t], f[t - st] + sv);
                st -= ve[i][j].t;
                sv -= ve[i][j].v;
            }
        }
    }
    
    cout << f[T] << endl;

    system("pause");
    return 0;
}
// 19ed77b5c83eef520e2f4cca08feef7ed448e0e0
// 1822435