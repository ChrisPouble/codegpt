#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

// 全局/临时变量（避免DFS参数过多）
vector<int> left_R;            // 左半必选集合列表（0-based）
vector<pair<int, int>> LL;     // 左半内部的约束（a,b都在左半）
vector<ll> x;                  // 所有集合的代价（0-based）
int k;                         // 折半分界点（左半0~k-1，右半k~m-1）
vector<ll> pre_cost_L;         // 左半子集代价（mask→代价）
vector<bool> left_valid_mask;  // 左半子集是否有效（满足必选+LL约束）

// 右半预处理相关临时变量
vector<int> right_R;            // 右半必选集合列表（右半内部索引，0-based）
vector<pair<int, int>> RR;      // 右半内部的约束（a,b都在右半，已转右半内部索引）
int left_size, right_size;      // 右半集合数量
vector<ll> pre_cost_R;          // 右半子集代价（mask→代价）
vector<bool> right_valid_mask;  // 右半子集是否有效（满足必选+RR约束）

// DFS枚举左半子集：当前处理到第pos个左半集合，已选掩码mask，累计代价cost
void dfs_left(int pos, int mask, ll cost) {
    if (pos == k) {  // 左半集合遍历完毕，检查有效性
        // 1. 检查是否包含左半所有必选集合
        bool valid = true;
        for (int p : left_R) {
            if (!(mask & (1 << p))) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            left_valid_mask[mask] = false;
            return;
        }
        // 2. 检查是否满足所有LL约束（两个集合不能同时不选）
        for (auto [a, b] : LL) {
            if (!((mask & (1 << a)) || (mask & (1 << b)))) {
                valid = false;
                break;
            }
        }
        left_valid_mask[mask] = valid;
        pre_cost_L[mask] = cost;  // 记录有效子集的代价
        return;
    }
    // 分支1：不选当前左半集合pos
    dfs_left(pos + 1, mask, cost);
    // 分支2：选当前左半集合pos
    dfs_left(pos + 1, mask | (1 << pos), cost + x[pos]);
}

// DFS枚举右半子集：当前处理到第pos个右半集合（内部索引），已选掩码mask，累计代价cost
void dfs_right(int pos, int mask, ll cost) {
    if (pos == right_size) {  // 右半集合遍历完毕，检查有效性
        // 1. 检查是否包含右半所有必选集合
        bool valid = true;
        for (int p : right_R) {
            if (!(mask & (1 << p))) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            right_valid_mask[mask] = false;
            return;
        }
        // 2. 检查是否满足所有RR约束（两个集合不能同时不选）
        for (auto [a_idx, b_idx] : RR) {
            if (!((mask & (1 << a_idx)) || (mask & (1 << b_idx)))) {
                valid = false;
                break;
            }
        }
        right_valid_mask[mask] = valid;
        pre_cost_R[mask] = cost;  // 记录有效子集的代价
        return;
    }
    // 分支1：不选当前右半集合pos（对应原集合编号k+pos）
    dfs_right(pos + 1, mask, cost);
    // 分支2：选当前右半集合pos（对应原集合编号k+pos）
    dfs_right(pos + 1, mask | (1 << pos), cost + x[k + pos]);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Times;
    cin >> Times;
    while (Times--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n);  // c[i]：元素i+1（1-based）所属集合（0-based）
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
            c[i]--;
        }
        x.resize(m);  // x[j]：集合j（0-based）的代价
        for (int i = 0; i < m; ++i) {
            cin >> x[i];
        }

        // -------------------------- 1. 标记必选集合 --------------------------
        int r;
        cin >> r;
        vector<bool> in_R(m, false);  // in_R[j]：集合j是否必选
        // 必选：元素1（c[0]）、元素n（c[n-1]）所属集合
        in_R[c[0]] = true;
        in_R[c[n - 1]] = true;
        // 必选：集合T中的元素所属集合
        for (int i = 0; i < r; ++i) {
            int t;
            cin >> t;
            t--;  // 元素t从1-based→0-based
            in_R[c[t]] = true;
        }

        // -------------------------- 2. 约束预处理与分类 --------------------------
        // 去重连续性约束（元素i和i+1所属集合不能同时不选）
        set<pair<int, int>> constraint_set;
        for (int i = 0; i < n - 1; ++i) {
            int a = c[i], b = c[i + 1];
            if (a > b)
                swap(a, b);  // 去重（a,b与b,a视为同一约束）
            constraint_set.emplace(a, b);
        }
        vector<pair<int, int>> constraints(constraint_set.begin(), constraint_set.end());

        // 折半分界点（左半0~k-1，右半k~m-1）
        k = m / 2;
        vector<pair<int, int>> LR, RL;  // 跨左右的约束
        // 约束分类：LL（左左）、LR（左右）、RL（右左）、RR（右右）
        for (auto [a, b] : constraints) {
            bool a_left = (a < k), b_left = (b < k);
            if (a_left && b_left) {
                LL.emplace_back(a, b);
            } else if (a_left && !b_left) {
                LR.emplace_back(a, b);  // a左，b右（原编号）
            } else if (!a_left && b_left) {
                RL.emplace_back(a, b);  // a右，b左（原编号）
            } else {
                // RR约束：转换为右半内部索引（原编号k→0，k+1→1...）
                int a_idx = a - k;
                int b_idx = b - k;
                if (a_idx > b_idx)
                    swap(a_idx, b_idx);
                RR.emplace_back(a_idx, b_idx);
            }
        }

        // -------------------------- 3. DFS预处理左半部分 --------------------------
        left_size = k;
        int left_total = 1 << left_size;  // 左半子集总数
        pre_cost_L.assign(left_total, 0);
        left_valid_mask.assign(left_total, false);
        // 收集左半必选集合（原编号）
        left_R.clear();
        for (int p = 0; p < k; ++p) {
            if (in_R[p])
                left_R.push_back(p);
        }
        // DFS枚举左半所有子集
        dfs_left(0, 0, 0);

        // -------------------------- 4. DFS预处理右半部分 --------------------------
        right_size = m - k;
        int right_total = 1 << right_size;  // 右半子集总数
        pre_cost_R.assign(right_total, 0);
        right_valid_mask.assign(right_total, false);
        // 收集右半必选集合（转换为右半内部索引）
        right_R.clear();
        for (int p = k; p < m; ++p) {
            if (in_R[p]) {
                right_R.push_back(p - k);
            }
        }
        // DFS枚举右半所有子集
        dfs_right(0, 0, 0);

        // -------------------------- 5. SOS DP优化右半查询 --------------------------
        // dp_sos[mask]：包含mask的右半子集的最小代价
        vector<ll> dp_sos(right_total, INF);
        for (int mask = 0; mask < right_total; ++mask) {
            if (right_valid_mask[mask]) {
                dp_sos[mask] = pre_cost_R[mask];
            }
        }
        // SOS DP：递推计算超集最小代价
        for (int i = 0; i < right_size; ++i) {
            for (int mask = 0; mask < right_total; ++mask) {
                if (!(mask & (1 << i))) {  // mask的第i位未置位，超集mask|(1<<i)可能更优
                    dp_sos[mask] = min(dp_sos[mask], dp_sos[mask | (1 << i)]);
                }
            }
        }

        // -------------------------- 6. 枚举左半有效子集，计算最小总代价 --------------------------
        ll ans = INF;
        for (int mask_L = 0; mask_L < left_total; ++mask_L) {
            if (!left_valid_mask[mask_L])
                continue;  // 跳过左半无效子集

            // 计算右半需要的“必需掩码”req_mask（右半内部索引）
            int req_mask = 0;
            // 处理LR约束：左半a不选 → 右半b必选（b转右半索引）
            for (auto [a, b] : LR) {
                if (!(mask_L & (1 << a))) {
                    int b_idx = b - k;
                    req_mask |= (1 << b_idx);
                }
            }
            // 处理RL约束：左半b不选 → 右半a必选（a转右半索引）
            for (auto [a, b] : RL) {
                if (!(mask_L & (1 << b))) {
                    int a_idx = a - k;
                    req_mask |= (1 << a_idx);
                }
            }

            // 计算总代价（左半代价 + 右半满足req_mask的最小代价）
            ll cost_L = pre_cost_L[mask_L];
            ll cost_R = dp_sos[req_mask];
            if (cost_R < INF) {
                ans = min(ans, cost_L + cost_R);
            }
        }

        cout << ans << '\n';

        // 重置全局/临时变量，避免多组测试数据干扰
        LL.clear();
        LR.clear();
        RL.clear();
        RR.clear();
        left_R.clear();
        right_R.clear();
    }
}

int main() {
    solve();
    return 0;
}