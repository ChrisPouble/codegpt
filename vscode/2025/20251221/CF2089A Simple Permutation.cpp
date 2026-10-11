#include <bits/stdc++.h>
using namespace std;

// 预处理范围，N 最大为10^5，平均值不会超过 N 太多
const int MAX_VAL = 2e5 + 10;
const int N = 1e5 + 10;

int n, ans[N];

vector<int> primes;
bool is_prime[MAX_VAL];

// 线性筛预处理素数
void sieve() {
    for (int i = 1; i < MAX_VAL; i++)
        is_prime[i] = 1;
    
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_VAL; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_VAL; j += i)
                is_prime[j] = false;
        }
    }
    
    for (int i = 2; i < MAX_VAL; i++)
        if (is_prime[i]) primes.push_back(i);
}

void solve() {
    cin >> n;
    
    set<int> pz;
    for (int i = 1; i <= n; i++) pz.insert(i);
    ; 
    long long sum = 0;
    bool lst = false; 
    
    for (int i = 1; i <= n; i++) {
        int picked = -1;
        
        if (lst) picked = *pz.begin();
        else {
            int start = (sum + 1 + i - 1) / i; 
            auto it = lower_bound(primes.begin(), primes.end(), start);
            
            bool found = false;
            
            // 尝试接下来的几个素数（通常很快就能找到或者确定找不到）
            for (int k = 0; k < 30 && it != primes.end(); ++k, ++it) {
                int P = *it;
                long long min_need = 1LL * (P - 1) * i + 1 - sum;
                long long max_need = 1LL * P * i - sum;
                
                // 在 set 中查找是否有满足 [min_need, max_need] 的元素
                // lower_bound 找第一个 >= min_need 的数
                auto sit = pz.lower_bound((int)max(1LL, min_need));
                
                if (sit != pz.end() && *sit <= max_need) {
                    picked = *sit;
                    found = true;
                    break;
                }
            }
            
            // Fallback：如果找不到合适的数，选择最大的数进行破坏
            if (!found) picked = *pz.rbegin();
        }
        
        // 执行选择
        pz.erase(picked);
        ans[i] = picked;
        sum += picked;
        
        // 更新状态：计算当前的 c_i 是否为素数
        int c_i = (sum + i - 1) / i; // 向上取整
        if (c_i < MAX_VAL) lst = is_prime[c_i];
        else lst = false; // 理论上不会超出范围
    }
    
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    sieve();
    
    int T;
    cin >> T;

    while (T--) solve();
    return 0;
}