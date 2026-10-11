#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5, M = 7e6 + 5;
int n, m, q, u, v, t, Add;
int Q[5][M], qt[5], qw[5];

inline int get() {
    char ch; int res;
    while ((ch = getchar()) < '0' || ch > '9');
    res = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') res = (res << 3) + (res << 1) + ch - '0';
    return res;
}

inline void put(int x) {
    if (x > 9) put(x / 10);
    putchar(x % 10 + 48); 
}

inline bool cmp(const int &x, const int &y) { return x > y; }

inline int GetMax() {
    int res = -1e9, k;
    for (int i = 1; i <= 3; i++)
        if (qt[i] <= qw[i] && res < Q[i][qt[i]])
            res = Q[i][qt[i]], k = i;
    qt[k]++;
    return res;
}
 
signed main() {
    // 读入
    n = get(); m = get(); q = get(); 
    u = get(); v = get(); t = get();
    for (int i = 1; i <= n; i++) Q[1][++qw[1]] = get();

    qt[1] = qt[2] = qt[3] = 1;

    // 处理蚯蚓的变化
    sort(Q[1] + 1, Q[1] + qw[1] + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int x = GetMax() + Add;

        // 输出蚯蚓切断前的长度
        if (i % t == 0) put(x), putchar(i + t > m ? '\n' : ' '); 
        int l = x * u / v, r = x - l;
        
        // 切断一条蚯蚓
        Add += q;
        Q[2][++qw[2]] = l - Add;
        Q[3][++qw[3]] = r - Add;
    }

    if (t > m) putchar('\n');

    // 输出每条蚯蚓长度
    int tmp = n + m;
    for (int i = 1; i <= tmp; i++) {
        int x = GetMax() + Add;
        if (i % t == 0) {
            put(x);
            if (i + t <= tmp) putchar(' '); 
        }
    }

    system("pause");
    return 0;
}