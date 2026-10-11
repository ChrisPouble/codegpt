#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    ll x, pts;
};

ll n, s, t;
bool vis[5000010];
void bfs() {
    cin >> s >> t;
    memset(vis, 0, sizeof(vis));
    queue<node> q;
    vis[s] = 1;
    q.push({ s, 0 });
    while (!q.empty()) {
        int x = q.front().x;
        int pts = q.front().pts;
        q.pop();
        if (x == t) {
            cout << pts * 2 << endl;
            return;
        }
        for (int i = 1; i <= 4; i++) {
            if (i == 1) {
                int t = x - 1;
                if (t >= 0 && !vis[t] && t <= 2000000) {
                    q.push({t, pts + 1});
                    vis[t] = 1;
                }
            }
            if (i == 2) {
                int t = x + 1;
                if (t >= 0 && !vis[t] && t <= 2000000) {
                    q.push({t, pts + 1});
                    vis[t] = 1;
                }
            }
            if (i == 3) {
                int t = x * 2;
                if (t >= 0 && !vis[t] && t <= 2000000) {
                    q.push({t, pts + 1});
                    vis[t] = 1;
                }
            } else {
                int t = x / 2;
                if(x % 2 != 0) continue;
                if (t >= 0 && !vis[t] && t <= 2000000) {
                    q.push({t, pts + 1});
                    vis[t] = 1;
                }
            }
        }
    }
}

int main() {
    cin >> n;
    while (n--) bfs();
    return 0;
}