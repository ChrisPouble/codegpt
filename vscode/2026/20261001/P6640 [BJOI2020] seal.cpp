#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;

int n; string str; // str 是 s#t 拼接串
int sa[N], rk[N], height[N];

// 保留你的 Node + sort 后缀数组模板
struct Node {
    int id;   // 后缀的起始下标
    int rk1;  // 第一关键字排名：rk[i]
    int rk2;  // 第二关键字排名：rk[i + w]

    bool operator<(const Node& other) const {
        if (rk1 != other.rk1) return rk1 < other.rk1;
        return rk2 < other.rk2;
    }
} a[N];

void SA() {
    for (int i = 1; i <= n; i++)
        rk[i] = str[i];

    // 保证模板在长度为 1 时也有正确的排名
    if (n == 1) { rk[1] = sa[1] = 1; return; }

    for (int w = 1; w < n; w <<= 1) {
        for (int i = 1; i <= n; i++) {
            a[i].id = i;
            a[i].rk1 = rk[i];
            a[i].rk2 = (i + w <= n) ? rk[i + w] : 0;
        }

        sort(a + 1, a + n + 1);

        int p = 1;
        rk[a[1].id] = 1;

        for (int i = 2; i <= n; i++) {
            if (a[i].rk1 != a[i - 1].rk1 ||
                a[i].rk2 != a[i - 1].rk2)
                ++p;

            rk[a[i].id] = p;
        }

        if (p == n) break;
    }

    for (int i = 1; i <= n; i++)
        sa[rk[i]] = i;
}

// height[k] = 排名 k 与排名 k-1 的后缀的 LCP
void Init() {
    int h = 0;

    for (int i = 1; i <= n; i++) {
        int k = rk[i], j = sa[k - 1];

        if (k == 1) { h = 0; continue; }

        while (i + h <= n && j + h <= n && str[i + h] == str[j + h])
            h++;

        height[k] = h;
        if (h > 0) --h;
    }
}

struct SparseTable {
    vector <int> lg;
    vector <vector<int> > st;

    SparseTable(const int a[], int m) {
        lg.resize(m + 1);
        for (int i = 2; i <= m; ++i)
            lg[i] = lg[i >> 1] + 1;

        st.assign(lg[m] + 1, vector<int>(m + 1));

        for (int i = 1; i <= m; ++i)
            st[0][i] = a[i];

        for (int k = 1; k <= lg[m]; ++k) {
            int len = 1 << k;
            for (int i = 1; i + len - 1 <= m; ++i) {
                st[k][i] = max(
                    st[k - 1][i],
                    st[k - 1][i + (len >> 1)]
                );
            }
        }
    }

    int query(int l, int r) const {
        if (l > r) return 0;

        int k = lg[r - l + 1];
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int match[N], endpos[N];
// match[i]：从 s 的位置 i 开始，能在 t 中匹配的最长长度
// endpos[i]：从 i 出发的最长匹配，在 s 中结束的位置

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int lenS = (int)s.size();

    str = " " + s + "#" + t;
    n = (int)str.size() - 1;

    SA(), Init();

    // 从左往右：找字典序左侧最近的 t 后缀
    bool seen = 0; int mn = inf;

    for (int k = 1; k <= n; k++) {
        int pos = sa[k];

        if (pos >= lenS + 2) {          // t 的后缀
            seen = true;
            mn = inf;
        } else if (pos <= lenS && seen) { // s 的后缀
            mn = min(mn, height[k]);
            match[pos] = max(match[pos], mn);
        }
        // pos == lenS + 1 是 '#'，跳过
    }

    // 从右往左：找字典序右侧最近的 t 后缀
    seen = 0, mn = inf;

    for (int k = n; k >= 1; k--) {
        int pos = sa[k];

        if (pos >= lenS + 2) {
            seen = true;
            mn = inf;
        } else if (pos <= lenS && seen) {
            mn = min(mn, height[k + 1]);
            match[pos] = max(match[pos], mn);
        }
    }

    for (int i = 1; i <= lenS; i++)
        endpos[i] = i + match[i] - 1;

    SparseTable rmq(match, lenS);

    int q; cin >> q;

    for (int pro = 1; pro <= q; pro++) {
        int l, r; cin >> l >> r;

        // 找 [l, r] 中第一个 endpos[p] > r 的位置；
        // 如果没有，p = r + 1。
        int lo = l, hi = r, p = r + 1;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;

            if (endpos[mid] > r) {
                hi = mid - 1;
                p = mid;
            } else {
                lo = mid + 1;
            }
        }

        int ans = rmq.query(l, p - 1);

        // [p, r]：受右边界截断，最大值出现在最左侧 p
        if (p <= r) ans = max(ans, r - p + 1);

        cout << ans << "\n";
    }

    return 0;
}