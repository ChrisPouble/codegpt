#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5005;

// 树的邻接表表示
vector<int> adj[MAXN];
// dp[u][c] 表示在以 u 为根的子树内，划分为 c 条合法链的方案数
vector<int> dp[MAXN];
// sz[u] 表示子树 u 的节点个数
int sz[MAXN];

// 阶乘与阶乘逆元
int fact[MAXN], invFact[MAXN];

// 快速幂求解逆元
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// 预处理阶乘及逆元
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (1LL * invFact[i + 1] * (i + 1)) % MOD;
    }
}

// 组合数 C(n, k)
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return 1LL * fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

// 树形 DP
void dfs(int u, int p) {
    // 初始时子树为空（为了方便计算先当做只有常数项 1 的多项式）
    dp[u] = {1}; 
    sz[u] = 0;
    
    // 1. 合并所有子节点的多项式 (树上背包/多项式乘法)
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        
        // sz[u] + sz[v] + 1 是合并后的最大可能链数
        vector<int> next_dp(sz[u] + sz[v] + 1, 0);
        for (int i = 0; i <= sz[u]; i++) {
            if (!dp[u][i]) continue;
            for (int j = 0; j <= sz[v]; j++) {
                next_dp[i + j] = (next_dp[i + j] + 1LL * dp[u][i] * dp[v][j]) % MOD;
            }
        }
        dp[u] = next_dp;
        sz[u] += sz[v];
    }
    
    // 2. 将当前节点 u 加入到子树的链中
    // 此时已经遍历完了所有的子树，链的最大数量是 sz[u]。
    // 加入 u 后，最大链数量会变成 sz[u] + 1
    vector<int> next_dp(sz[u] + 2, 0);
    for (int k = 1; k <= sz[u] + 1; k++) {
        // 决策 1：节点 u 自己单独作为一条新的链，链数由 k-1 变为 k 
        long long val1 = dp[u][k - 1];
        
        // 决策 2：节点 u 连在已有 k 条链中某一条的顶端（形成向北的移动），链数仍为 k
        long long val2 = (k < dp[u].size()) ? (1LL * k * dp[u][k]) % MOD : 0;
        
        next_dp[k] = (val1 + val2) % MOD;
    }
    
    dp[u] = next_dp;
    sz[u]++; // 加上节点 u 自身的体积
}

int main() {
    // 优化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int n, q;
    if (!(cin >> n >> q)) return 0;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 以 1 为根进行 DFS
    dfs(1, 0);
    
    // 处理独立询问
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        int S = sz[x]; // 子树大小
        
        // 显然“向北移动（即下降）”的次数不可能大于等于节点总数 S
        if (y >= S) {
            cout << 0 << "\n";
            continue;
        }
        
        long long ans = 0;
        // k 是枚举“钦定的下降(向北移动)次数”
        for (int k = y; k <= S - 1; k++) {
            int chains = S - k; // 钦定 k 次下降，相当于组成了 S - k 条链
            // g(k) = (S-k)! * DP[x][S-k]
            long long gk = 1LL * dp[x][chains] * fact[chains] % MOD;
            
            // term = C(k, y) * g(k)
            long long term = 1LL * C(k, y) * gk % MOD;
            
            // 容斥系数 (-1)^{k-y}
            if ((k - y) % 2 == 1) {
                ans = (ans - term + MOD) % MOD;
            } else {
                ans = (ans + term) % MOD;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}