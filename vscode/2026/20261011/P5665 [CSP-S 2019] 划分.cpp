#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using int128 = __int128_t;

const int N = 4e7 + 10;
const int mod = (1 << 30);

int n, type;
ll sum[N];
int f[N], q[N];

void get_data() {
    cin >> n >> type;

    if (type == 0) {
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            sum[i] = sum[i - 1] + x;
        }
    } else {
        ll x, y, z, m;
        cin >> x >> y >> z >> sum[1] >> sum[2] >> m;

        for (int i = 3; i <= n; i++) {
            sum[i] = (x * sum[i - 1] + y * sum[i - 2] + z) % mod;
        }

        int lst = 0;

        for (int j = 1; j <= m; j++) {
            int p, l, r; cin >> p >> l >> r;
            
            for (int i = lst + 1; i <= p; i++) {
                sum[i] = (sum[i] % (r - l + 1)) + l;
            }

            lst = p;
        }

        for (int i = 1; i <= n; i++)
            sum[i] += sum[i - 1];
    }
}

// 计算 work(j) = 2 * sum[j] - sum[f[j]]
ll work(int j) { return 2 * sum[j] - sum[f[j]]; }

// 输出 __int128
void print(int128 x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    get_data();

    int head = 1, tail = 0;
    q[++tail] = 0; // 更加规范化

    for (int i = 1; i <= n; i++) {
        // 在队列中寻找最大的 j 使得 sum[i] >= work(j)
        while (head + 1 <= tail && work(q[head + 1]) <= sum[i])
            head++;
        
        f[i] = q[head];

        // 维护队列的单调性：work(j) 递增
        while (head <= tail && work(q[tail]) >= work(i))
            tail--;
        
        q[++tail] = i;
    }

    // 3. 利用 f 数组回溯计算答案
    int128 ans = 0;
    int cur = n;

    while (cur > 0) {
        int128 seg = sum[cur] - sum[f[cur]];
        ans += seg * seg, cur = f[cur];
    }

    print(ans), putchar('\n');

    return 0;
}