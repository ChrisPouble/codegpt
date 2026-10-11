#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int128 = __int128; // 采用 128 位整数防止分数运算时的溢出

const int N = 1e5 + 10;
const int M = 5e5 + 10;

int n, m;
int head[N], to[M], nxt[M], cnt;
int outd[N], ind[N];
int que[N], hh, tt;

// 求最大公约数
int128 gcd(int128 a, int128 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 分数结构体
struct Frac {
    int128 p, q; // 分子 p，分母 q
    
    Frac() { p = 0; q = 1; }
    
    Frac(int128 _p, int128 _q) {
        p = _p, q = _q;
        simplify();
    }
    
    // 化简分数
    void simplify() {
        if (p == 0) { q = 1; return; }
        int128 g = gcd(p, q);
        p /= g, q /= g;
    }
    
    // 分数加法
    Frac operator+(const Frac& o) const {
        if (p == 0) return o;
        if (o.p == 0) return *this;
        
        int128 g = gcd(q, o.q);
        int128 q_g = q / g;
        int128 oq_g = o.q / g;
        int128 lcm = q_g * o.q; // 最小公倍数作为新的分母
        int128 num = p * oq_g + o.p * q_g;
        
        return Frac(num, lcm);
    }
    
    // 分数除以一个整数（用于水流均分的情况）
    Frac operator/(int x) const {
        if (x == 0) return *this;
        return Frac(p, q * x);
    }
} val[N];

// 邻接表加边函数
void add_edge(int u, int v) {
    to[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    outd[u]++;
    ind[v]++;
}

// 专门为 __int128 编写的输出函数
void print(int128 x) {
    if (x == 0) { cout << 0; return; }

    int stk[50], top = 0;
    while (x) { stk[++top] = x % 10; x /= 10; }
    while (top) cout << stk[top--];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        for (int j = 1; j <= d; j++) {
            int v; cin >> v;
            add_edge(i, v);
        }
    }

    hh = 1; tt = 0;
    for (int i = 1; i <= m; i++)
        val[i] = Frac(1, 1);

    // 拓扑排序初态
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            que[++tt] = i;
        }
    }

    // 开始 BFS 拓扑排序更新水流状态
    while (hh <= tt) {
        int u = que[hh++];
        if (outd[u] > 0) {
            // 当前节点需要向下面分发的水量
            Frac flow = val[u] / outd[u];
            for (int i = head[u]; i; i = nxt[i]) {
                int v = to[i];
                val[v] = val[v] + flow; // 向下游排水结点累加流水
                if (--ind[v] == 0) {
                    que[++tt] = v;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (outd[i] == 0) {
            print(val[i].p), cout << " ";
            print(val[i].q), cout << "\n";
        }
    }

    return 0;
}