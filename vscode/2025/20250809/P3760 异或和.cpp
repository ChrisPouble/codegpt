#include <bits/stdc++.h>
using namespace std;

int lowbit(int x) { return x & (-x); }

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int n, sum[N], s[N], f[M][2];
// sum 数组负责记录当前 s[i] 从右开始数的 k 位的大小
int maxx, cnt, tot, ans;

int ask(int x, int y) {
    int res = 0;
    while (x > 0) {
        res += f[x][y];
        x -= lowbit(x);
    }
    return res;
}

void add(int x, int y) {
    while (x <= M) {
        f[x][y]++;
        x += lowbit(x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
        maxx = max(maxx, s[i]);
    }

    for (int i = 0; i <= 20; i++) { // 因为低位会影响高位，所以从低往高枚举
        if ((1 << i) > maxx) break;
        memset(f, 0, sizeof(f)); // 由于每一位都开一个树状数组我们开不起，因此每次操作都清空一遍
        cnt = 0;
        add(1, 0);
        for (int j = 1; j <= n; j++) {
            int tmp = s[j] & (1 << i);
            if (tmp) tot = ask(sum[j] + 1, 0) + ask(1e6, 1) - ask(sum[j] + 1, 1);
            else tot = ask(sum[j] + 1, 1) + ask(1e6, 0) - ask(sum[j] + 1, 0);
            if (tot % 2 == 1) cnt = 1 - cnt;
            add(sum[j] + 1, (tmp > 0 ? 1 : 0)); // 这里不能先执行下面的操作，不然就是 k + 1 位了
            sum[j] += tmp; // 算上大小
        }
        if (cnt == 1) ans += (1 << i);
    }

    cout << ans << endl;
    return 0;
}