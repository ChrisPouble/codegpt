#include <iostream>
#include <vector>

using namespace std;

// 完全容纳 2.5 * 10^6 的极限数据范围
const int N_MAX = 2500005;

int n;
int M_val, F_val;
unsigned long long seed_val;

// 图形结构
int p_arr[N_MAX], c_arr[N_MAX];
int head_child[N_MAX], next_sibling[N_MAX];
int sz[N_MAX], heavy[N_MAX];
int in_arr[N_MAX], out_arr[N_MAX], dfn[N_MAX];

// DSU 统计信息
int cnt[N_MAX], freq_cnt[N_MAX];
int ans_m[N_MAX], ans_k[N_MAX];
int max_freq = 0;

int path_buf[N_MAX];

inline void add_color(int c) {
    int &f = cnt[c];
    freq_cnt[f]--;
    f++;
    freq_cnt[f]++;
    if (f > max_freq) {
        max_freq = f;
    }
}

inline void remove_color(int c) {
    int &f = cnt[c];
    freq_cnt[f]--;
    f--;
    freq_cnt[f]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> seed_val >> M_val >> F_val)) return 0;

    vector<int> q_arr(M_val + 1, 0);
    for (int i = 2; i <= M_val; i++) cin >> q_arr[i];

    vector<int> d_arr(M_val + 1, 0);
    for (int i = 1; i <= M_val; i++) cin >> d_arr[i];

    unsigned long long state = seed_val;
    unsigned long long mmod = 2147483648ULL; 

    for (int i = 2; i <= n; i++) {
        if (i <= M_val) {
            p_arr[i] = q_arr[i];
        } else {
            p_arr[i] = (state % (i - 1)) + 1;
            state = (state * 1103515245ULL + 12345ULL) % mmod;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i <= M_val) {
            c_arr[i] = d_arr[i];
        } else {
            c_arr[i] = (state % F_val) + 1;
            state = (state * 1103515245ULL + 12345ULL) % mmod;
        }
    }

    for (int i = 1; i <= n; i++) sz[i] = 1;
    sz[0] = 0; 
    for (int i = n; i >= 2; i--) {
        int p_i = p_arr[i];
        sz[p_i] += sz[i];
        if (sz[i] > sz[heavy[p_i]]) {
            heavy[p_i] = i;
        }
    }

    for (int i = n; i >= 2; i--) {
        next_sibling[i] = head_child[p_arr[i]];
        head_child[p_arr[i]] = i;
    }

    int timer = 0;
    vector<int> stk;
    stk.reserve(n + 1);
    stk.push_back(1);
    
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        
        in_arr[u] = ++timer;
        dfn[timer] = u;
        
        int h = heavy[u];
        for (int v = head_child[u]; v; v = next_sibling[v]) {
            if (v != h) {
                stk.push_back(v);
            }
        }
        if (h) stk.push_back(h);
    }
    
    for (int i = 1; i <= n; i++) {
        out_arr[i] = in_arr[i] + sz[i] - 1;
    }

    freq_cnt[0] = n + 1;

    vector<int> heads;
    for (int i = n; i >= 1; i--) {
        int u = dfn[i];
        if (u == 1 || heavy[p_arr[u]] != u) {
            heads.push_back(u);
        }
    }

    for (int head : heads) {
        int curr = head;
        int len = 0;
        while (curr) {
            path_buf[len++] = curr;
            curr = heavy[curr];
        }
        
        for (int i = len - 1; i >= 0; i--) {
            int u = path_buf[i];
            
            for (int v = head_child[u]; v; v = next_sibling[v]) {
                if (v != heavy[u]) {
                    for (int j = in_arr[v]; j <= out_arr[v]; j++) {
                        add_color(c_arr[dfn[j]]);
                    }
                }
            }
            
            add_color(c_arr[u]);
            
            ans_m[u] = max_freq;
            ans_k[u] = freq_cnt[max_freq];
        }
        
        if (head != 1) {
            for (int j = in_arr[head]; j <= out_arr[head]; j++) {
                remove_color(c_arr[dfn[j]]);
            }
            max_freq = 0;
        }
    }

    long long final_ans = 0;
    for (int i = 1; i <= n; i++) {
        long long m_u = ans_m[i];
        long long k_u = ans_k[i];
        long long term = (1LL * (m_u ^ i) * (k_u ^ i)) % 998244353;
        final_ans = (final_ans + term) % 998244353;
    }

    cout << final_ans << "\n";

    return 0;
}