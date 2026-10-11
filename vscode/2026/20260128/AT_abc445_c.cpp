#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int a[N], dp[N];

int main() {
    // 关闭C++ IO同步，大幅提升输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 读取A数组（1-based）
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
        if (dp[i] != 0) continue;
        
        vector<int> path;
        int cur = i, res = 0;
        
        while (true) {
            if (dp[cur] != 0) {
                res = dp[cur];
                break;
            }
            if (a[cur] == cur) {
                res = cur;
                dp[cur] = cur;
                break;
            }
            path.push_back(cur);
            cur = a[cur];
        }
        
        for (int x : path) dp[x] = res;
    }
    
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << " ";
    
    system("pause");
    return 0;
}