#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    int dis, x, y;
    bool operator<(const node t) const {
        if (dis != t.dis) return dis > t.dis;
        if (x != t.x) return x > t.x;
        if (y != t.y) return y > t.y;
    }
};

ll T, n;

int main() {
    cin >> T;
    while (T--) {
        priority_queue<node> pq;
        ll x = 1, y = 1, now = 2;
        cin >> n;
        
        vector<pair<ll, ll>> ans(n + 1);
        
        for (ll i = 1, xx; i <= n; i++) {
            cin >> xx;
            
            if (xx && !pq.empty() && pq.top().dis < now) {
                auto p = pq.top();
                pq.pop();
                ans[i] = { p.x, p.y };
            } else {
                ans[i] = { x, y };
                
                pq.push({x + y + 1, x + 1, y});
                pq.push({x + y + 1, x, y + 1});
                pq.push({x + y + 4, x + 1, y + 1});
                
                if (y - 1) x += 3, y -= 3;
                else swap(x, y), y += 3;
                
                now = x + y;
            }
        }
        
        for (ll i = 1; i <= n; i++)
            cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}