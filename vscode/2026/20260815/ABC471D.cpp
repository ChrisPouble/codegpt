#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q; ll v;
priority_queue<ll> que;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> q >> v;
    
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            ll t, w; cin >> t >> w;
            que.push(w - t);
        } else {
            ll t; cin >> t;
            if (que.empty()) {
                cout << -1 << "\n";
            } else {
                ll maxk = que.top(); que.pop();
                cout << min(v, maxk + t) << "\n";
            }
        }
    }

    return 0;
}