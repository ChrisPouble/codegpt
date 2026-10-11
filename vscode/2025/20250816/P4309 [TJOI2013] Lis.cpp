#include <bits/stdc++.h>
#include <ext/rope>
#define endl "\n"
using namespace std;
using namespace __gnu_cxx;

const int N = 1e5 + 10;

int lowbit(int x) {
    return x & (-x);
}

int n;
int ans[N], tree[N]; // tree[i] 用来求前缀 max
rope<int> a;
void update(int x, int val) {
    while (x <= n) {
        tree[x] = max(tree[x], val);
        x += lowbit(x);
    }
}

int query(int x) {
    int t = 0;
    while (x) {
        t = max(t, tree[x]);
        x -= lowbit(x);
    }
    return t;
}

int main() {
    cin >> n;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        a.insert(t, i);
    }
    for (int i = 0; i < n; i++) {
        int x = a[i];
        // 计算最长上升子序列，并将其获得的值塞入树状数组
        update(x, ans[x] = query(x) + 1);
        // 加上 x 这个维度，相当于在插入时间上的限制
    }
    for (int i = 1; i <= n; i++) {
        // 答案或许用不到插入的第 i 个数，所以要 max(ans[i], ans[i - 1])
        ans[i] = max(ans[i], ans[i - 1]);
        cout << ans[i] << endl;
    }
    return 0;
}