#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
const int LOG = 20; // 1e5 的数据范围，LOG 设为 20 足够
const ll inf = 0x3f3f3f3f3f3f3f3f;

int lg[N];

struct ST {
    int n;
    // 删除了内部多余的 p[N] 数组以节省内存
    ll mx[N][LOG], mn[N][LOG], fmx[N][LOG], zmn[N][LOG];
    // 区间最大值，区间最小值，区间负数最大值，区间非负数最小值

    ST(int len, const ll arr[]) {
        n = len;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = mn[i][0] = arr[i];
            fmx[i][0] = (arr[i] < 0 ? arr[i] : -inf);
            zmn[i][0] = (arr[i] >= 0 ? arr[i] : inf);
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                // 修复了偏移量 1 << (j-1) 错误，以及 mn, fmx, zmn 错用 mx 的逻辑
                mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
                fmx[i][j] = max(fmx[i][j - 1], fmx[i + (1 << (j - 1))][j - 1]);
                zmn[i][j] = min(zmn[i][j - 1], zmn[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // 修复了返回值类型，从 int 改为 ll
    ll get(int l, int r, int flag) {
        int len = lg[r - l + 1];
        if (flag == 1) return max(mx[l][len], mx[r - (1 << len) + 1][len]);
        if (flag == 2) return min(mn[l][len], mn[r - (1 << len) + 1][len]);
        if (flag == 3) return max(fmx[l][len], fmx[r - (1 << len) + 1][len]);
        if (flag == 4) return min(zmn[l][len], zmn[r - (1 << len) + 1][len]);
        return 0;
    }
};

int n, m, q;
ll a[N], b[N];

int main() {
    // 提升 I/O 速度，防止超时
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= m; i++)
        cin >> b[i];

    // 初始化对数表
    for (int i = 2; i <= max(n, m); i++)
        lg[i] = lg[i >> 1] + 1;

    // 使用 new 在堆上动态分配，避免局部变量过大导致栈溢出 (Stack Overflow)
    ST* A = new ST(n, a);
    ST* B = new ST(m, b);
    
    while (q--) {
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        ll ans = -inf;

        ll a_max = A->get(la, ra, 1);
        ll a_min = A->get(la, ra, 2);
        ll a_fmx = A->get(la, ra, 3);
        ll a_zmn = A->get(la, ra, 4);

        ll b_max = B->get(lb, rb, 1);
        ll b_min = B->get(lb, rb, 2);

        ans = max(ans, a_max * (a_max >= 0 ? b_min : b_max));
        ans = max(ans, a_min * (a_min >= 0 ? b_min : b_max));

        if (a_fmx != -inf) 
            ans = max(ans, a_fmx * (a_fmx >= 0 ? b_min : b_max));
        
        if (a_zmn != inf)
            ans = max(ans, a_zmn * (a_zmn >= 0 ? b_min : b_max));
        
        cout << ans << "\n";
    }

    delete A;
    delete B;

    return 0;
}