// Problem: P7913 [CSP-S 2021] 廊桥分配
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P7913
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

#define For(i, st, en) for (int i = (st); i <= (en); i++)

using PII = pair<int, int>;

const int N = 1e5 + 10;

struct Flight {
    int st, en; /* Start, End */ 

    bool operator<(const Flight& other) const {
        return st < other.st;
    }
} side[N], fore[N]; // Countryside, Foreign

int n, m[2];
int cnt[2][N];

void Solve(Flight p[], int flag) {
    priority_queue<PII, vector<PII>, greater<PII> > leave;
    priority_queue<int, vector<int>, greater<int> > free;
    sort(p + 1, p + m[flag] + 1);

    for (int i = 1; i <= m[flag]; i++)
        free.push(i);
    
    for (int i = 1; i <= m[flag]; i++) {
        int st = p[i].st, en = p[i].en;
        while (!leave.empty() && leave.top().first < st)
            free.push(leave.top().second), leave.pop();
        
        int Ff = free.top(); free.pop(); // First free
        cnt[flag][Ff]++, leave.push(make_pair(en, Ff));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m[0] >> m[1];

    for (int i = 1; i <= m[0]; i++) { cin >> side[i].st >> side[i].en; }
    for (int i = 1; i <= m[1]; i++) { cin >> fore[i].st >> fore[i].en; }

    Solve(side, 0), Solve(fore, 1);

    For(flag, 0, 1) For(i, 1, n)
        cnt[flag][i] += cnt[flag][i - 1];

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, cnt[0][i] + cnt[1][n - i]);
    }

    cout << ans << endl;

    return 0;
}