// Problem: Luogu - 函数 / func 
// URL: https://www.luogu.com.cn/problem/P17723
// Memory Limit: 512 MB 
// Time Limit: 1000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e6 + 10;

int n; ull a[N];
int vis[N], all;

void add(ull x, ull B) {
    if (x > B) return ;
    if (!vis[x]) all++;
    vis[x]++;
}

void del(ull x, ull B) {
    if (x > B) return ;
    vis[x]--;
    if (!vis[x]) all--; 
}

ull get(int k) {
    ull B = (1 << k);
    int l = 1, r = 1;

    ull res = 0;

    if (B > n) { // 说明 Mex 不会对第 k 位贡献，因此只要考虑 Or 的贡献即可
        for (int i = 1, rgt = 0; i <= n; i++) {
            if (a[i] & B) rgt = i;
            res += rgt;
        }
    } else {
        for (int lst = 0; r <= n; r++) {
            if (a[r] & B) lst = r;

            add(a[r], B);

            while (l <= lst || all == B)
                del(a[l++], B);
            
            res += l - 1;
        }

        all = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > B) continue;
            vis[a[i]] = 0;
        }
    }

    return res * B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ull ans = 0;
    for (int k = 0; k < 30; k++)
        ans += get(k);
    cout << ans << endl;

    return 0;
}