#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e5 + 10;
const int inf = (1 << 15);

int n, a[N];
int ST[20][N], lg2[N];

int query(int l, int r) {
    int len = lg2[r - l + 1];
    return max(ST[len][l], ST[len][r - (1 << len) + 1]);
}

bool CheckA() {
    for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1]) return 0;
    return 1;
}

bool CheckB() {
    for (int i = 1; i <= n; i++)
        if (a[i] > (1 << 5)) return 0;
    return 1;
}

bool CheckC() {
    for (int i = 1; i <= n; i++) {
        int tot = 0;
        for (int k = 0; k <= 14; k++)
            if (a[i] & (1 << k)) tot++;
        if (tot > 1) return 0;
    }
    return 1;
}

void SmallWorld() {
    ll ans = 0;
    for (int l = 1; l <= n; l++) {
        int mx = a[l];
        for (int r = l + 1; r <= n; r++) {
            mx = max(mx, a[r]);
            if (((a[l] & a[r]) == a[l]) || ((a[l] & a[r]) == a[r]))
                ans += mx;
            // cerr << l << " " << r << " " << mx << endl;
        }
    }
    cout << ans << endl;
}

int sum[inf]; // a[i] = x 的 a[i] 数量
vector <int> sup[inf];

ll same() {
    ll res = 0;
    for (int i = 1; i <= n; i++)
        sup[a[i]].push_back(i);
    
    for (int k = 0; k < (1 << 14); k++) {
        if (sup[k].empty()) continue;
        for (int i = 1; i < sup[k].size(); i++) {
            int val = query(sup[k][i - 1], sup[k][i]);
            int l1 = 0, r1 = i - 1, canl = i;
            while (l1 <= r1) {
                int mid = (l1 + r1) >> 1;
                if (query(sup[k][mid], sup[k][i]) <= val)
                    canl = mid, r1 = mid - 1;
                else
                    l1 = mid + 1;
            }

            int l2 = i, r2 = sup[k].size() - 1, canr = i;
            while (l2 <= r2) {
                int mid = (l2 + r2) >> 1;
                if (query(sup[k][i], sup[k][mid]) >= val)
                    r2 = mid - 1;
                else
                    canr = mid, l2 = mid + 1;
            }

            // cerr << i << ": " << canl << " " << canr << endl;
            res += 1ll * (i - 1 - canl + 1) * (canr - i + 1) * val;
        }
    }

    // for (int k = 0; k < (1 << 14); k++) {
    //     if (sup[k].empty()) continue;

    //     for (int i = 0; i < sup[k].size(); i++)
    //         for (int j = i + 1; j < sup[k].size(); j++)
    //             res += query(sup[k][i], sup[k][j]);
    // }

    return res;
}

void SuperA() { // 这里 A 分两次统计：a[l] 属于 a[r] 与 a[l] = a[r]
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        sum[a[i]]++;

    for (int state = 0; state < (1 << 14); state++) {
        if (state != 0) ans += 1ll * sum[0] * sum[state] * state;
        for (int k = state; k; k = (k - 1) & state) {
            if (k == state) continue;
            ans += 1ll * sum[k] * sum[state] * state;
        }
    }
    
    cout << ans + same() << endl;
}

struct node { int x, cnt; };
int top[35], huo[35];
node que[35][N]; // 对于每一个 a[i] 都开一个单调栈

void get(int i, ll &ans) {
    for (int k = 0; k <= 32; k++) {
        if ((k | a[i]) != k) continue;
        if (k == a[i]) continue;
        ans += huo[k];
    }

    for (int k = 0; k <= 32; k++) {
        int who = a[i], tot = (a[i] == k);
        while (top[k]) {
            int x = que[k][top[k]].x, cnt = que[k][top[k]].cnt;
            if (x > who) break;
            huo[k] -= x * cnt, tot += cnt, top[k]--;
        }
        que[k][++top[k]] = { who, tot };
        huo[k] += who * tot;
        // cout << huo[k] << " ";
    }
}

void SuperB() { // 将每个点作为左端点与右端点，正反分别跑一遍
    ll ans = 0;

    memset(huo, 0, sizeof(huo));
    memset(top, 0, sizeof(top));
    for (int i = 1; i <= n; i++)
        get(i, ans);
    // cerr << ans << endl;

    memset(huo, 0, sizeof(huo));
    memset(top, 0, sizeof(top));
    for (int i = n; i >= 1; i--)
        get(i, ans);
    
    // cerr << ans << endl;
    cout << ans + same() << endl;
}

int heart[20];

void got(int i, ll &ans) {
    for (int k = 0; k <= 14; k++) {
        if ((heart[k] | a[i]) != heart[k]) continue;
        if (heart[k] == a[i]) continue;
        ans += huo[k];
    }

    for (int k = 0; k <= 14; k++) {
        int who = a[i], tot = 1;
        while (top[k]) {
            int x = que[k][top[k]].x, cnt = que[k][top[k]].cnt;
            if (x > a[i]) break;
            huo[k] -= x * cnt, tot += cnt, top[k]--;
        }
        que[k][++top[k]] = { who, tot };
        huo[k] += who * tot;
    }
}

void SuperC() { // 将每个点作为左端点与右端点，正反分别跑一遍
    ll ans = 0;

    memset(huo, 0, sizeof(huo));
    memset(top, 0, sizeof(top));
    for (int i = 1; i <= n; i++)
        got(i, ans);
    
    memset(huo, 0, sizeof(huo));
    memset(top, 0, sizeof(top));
    for (int i = n; i >= 1; i--)
        got(i, ans);
    
    cout << ans + same() << endl;
}

void init() {
    for (int i = 1; i <= n; i++)
        ST[0][i] = a[i];

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            ST[j][i] = max(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
    
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i >> 1] + 1;
    
    heart[0] = 1;
    for (int i = 1; i <= 14; i++)
        heart[i] = heart[i - 1] * 2;
}

int stk[N], L[N], R[N];

void QuiteInit() {
    int top = 0;
    for (int i = 1; i <= n; i++) {
        while (top && a[i] >= a[stk[top]])
            top--;
        L[i] = (top ? stk[top] : 0);
        stk[++top] = i;
    }

    top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[i] > a[stk[top]])
            top--;
        R[i] = (top ? stk[top] : n + 1);
        stk[++top] = i;
    }
}

const int HB = 5, LB = 9; // 表示高低位分位
const int H = 1 << HB; // 1 << 5
const int V = 1 << LB; // 1 << 9
const int A = H * V;

// 当前前缀的计数表
// cntSub[h][s]：高位恰为 h，低位为 s 的子集的数的个数
// cntSup[h][s]：高位恰为 h，低位为 s 的超集的数的个数
int cntSub[H][V], cntSup[H][V], exact[A];

struct Event {
    int pos;   // 用 a[pos] 进行查询
    int coef;  // 查询结果乘上的系数，可以为负
};

vector <Event> events[N];

void insert(int x) {
    int h = (x >> LB);
    int l = (x & (V - 1));

    exact[x]++;

    for (int t = l; ; t = (t - 1) & l) {
        cntSup[h][t]++; // 我是“我的子集的超集”，所以用超集数组记录
        if (t == 0) break;
    }

    for (int t = l; ; t = (t + 1) | l) {
        cntSub[h][t]++; // 我是“我的超集的子集”，所以用子集数组记录
        if (t == V - 1) break;
    }
}

int query(int x) {
    int h = (x >> LB);
    int l = (x & (V - 1));

    int res = 0;
    for (int t = h; ; t = (t - 1) & h) {
        res += cntSub[t][l];
        if (t == 0) break;
    }

    for (int t = h; ; t = (t + 1) | h) {
        res += cntSup[t][l];
        if (t == H - 1) break;
    }

    // 等于 x 的数被分别统计了一次，因此这里取个重
    return res - exact[x];
}

void addQuery(int l, int r, int pos, int coef) {
    events[r].push_back({ pos, coef });
    if (l > 1) events[l - 1].push_back({ pos, -coef });
}

void buildEvents() {
    for (int p = 1; p <= n; p++) {
        int l = L[p] + 1;
        int r = R[p] - 1;

        if (p - l <= r - p) {
            // 枚举左端点，查询右端点区间 [p, r]。
            for (int x = l; x <= p; x++)
                addQuery(p, r, x, a[p]);
        } else {
            // 枚举右端点，查询左端点区间 [l, p]。
            for (int x = p; x <= r; x++)
                addQuery(l, p, x, a[p]);
        }
    }
}

int main() {
    // freopen("score.in", "r", stdin);
	// freopen("score.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    init();
    
    if (n <= 1000) { SmallWorld(); return 0; }
    if (CheckA()) { SuperA(); return 0; }
    if (CheckB()) { SuperB(); return 0; }
    if (CheckC()) { SuperC(); return 0; }

    QuiteInit(), buildEvents();

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        insert(a[i]);

        for (auto e : events[i]){
            ans += 1ll * e.coef * query(a[e.pos]);
        }
    }

    // 由于 [l, p] 与 [r, p] 都统计了一次 (p, p)
    // 因此去重
    for (int i = 1; i <= n; i++)
        ans -= a[i];

    cout << ans << endl;

    return 0;
}