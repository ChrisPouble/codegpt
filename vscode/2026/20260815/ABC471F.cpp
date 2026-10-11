#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k; string s[N];
bool sen[15][15];
vector <int> pos[15], all;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> s[i];

    // 1. 根据最优拼接规则倒序排列所有的字符串
    sort(s + 1, s + n + 1, [](string a, string b){
        return a + b > b + a;
    }); // 自定义排序函数：确保 A 排在 B 前面的条件是拼接 AB > BA

    // 预处理所有不同长度的字符串在排序后数组中的下标
    for (int i = 1; i <= n; i++) {
        pos[s[i].length()].push_back(i);
    }

    // 2. 启发式筛选候选首节点：最多只有 10 x 10 = 100 个有效候选

    for (int i = 1; i <= n; i++) {
        int len = s[i].length(), zero = 0;
        while (zero < len && s[i][zero] == '0')
            zero++;
        
        if (!sen[len][zero]) {
            sen[len][zero] = true;
            all.push_back(i);
        }
    }

    string ans = "";

    // 3. 对每一个候选首节点贪心分配其后辈节点
    for (int i : all) {
        // 如果备用池剩余的字符串不足 K-1 个，该首选项无效
        if (n - i < k - 1) continue;
        
        // 统计后缀池中每种长度各自有多少可用个数
        int avail[11] = { 0 };
        for (int len = 1; len <= 10; len++) {
            auto it = upper_bound(pos[len].begin(), pos[len].end(), i);
            avail[len] = pos[len].end() - it;
        }

        int rem = k - 1;
        int pick[11] = {0};
        
        // 贪心：为了剥离前导 0 后越长越好，优先选择越长的字符串
        for (int len = 10; len >= 1; len--) {
            pick[len] = min(avail[len], rem);
            rem -= pick[len];
        }

        // 提取所选取字符串在原排序数组下的下标以保障拼凑顺序
        vector <int> chosen;
        chosen.push_back(i);

        for (int len = 10; len >= 1; len--) {
            if (pick[len] > 0) {
                auto it = upper_bound(pos[len].begin(), pos[len].end(), i);
                for (int c = 0; c < pick[len]; c++) {
                    chosen.push_back(*(it + c));
                }
            }
        }

        // 恢复他们严格的最优前后顺序
        sort(chosen.begin(), chosen.end());

        // 4. 执行拼接
        string res;
        for (int idx : chosen)
            res += s[idx];

        // 去除多余的前导 0
        int zero = 0;
        while (zero < (int)res.length() && res[zero] == '0')
            zero++;
        
        if (zero == (int)res.length()) {
            res = "0"; // 全是 0 则按题意计为 "0"
        } else {
            res = res.substr(zero);
        }

        // 比较打擂，找出全局最大整数
        if (res.length() > ans.length()) {
            ans = res;
        } else if (res.length() == ans.length()) {
            if (res > ans) {
                ans = res;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}