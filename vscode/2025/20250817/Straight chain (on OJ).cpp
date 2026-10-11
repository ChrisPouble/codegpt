#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n;
bool possible;
vector<int> a, b;
vector<int> linker[N];

void add(int x, int y) {
    linker[x].push_back(y);
}

void update_map(map<int, int>& m, int key, int delta) {
    m[key] += delta;
    if (m[key] == 0) {
        m.erase(key);
    }
}

map<int, int> dfs(int u, int p) {
    if (!possible) {
        return {};
    }

    map<int, int> non_empty_child_map;
    bool found_non_empty = false;

    for (int v : linker[u]) {
        if (v == p) continue;

        map<int, int> child_map = dfs(v, u);
        if (!possible) return {};

        if (!child_map.empty()) {
            if (found_non_empty) {
                possible = false;
                return {};
            }
            found_non_empty = true;
            non_empty_child_map = child_map;
        }
    }

    map<int, int> current_chain_map = non_empty_child_map;
    update_map(current_chain_map, a[u - 1], 1);
    update_map(current_chain_map, b[u - 1], -1);
    
    return current_chain_map;
}

void solve() {
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    a.resize(n);
    b.resize(n);
    vector<int> a_sorted(n), b_sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a_sorted[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b_sorted[i] = b[i];
    }

    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    if (a_sorted != b_sorted) {
        cout << "No" << endl;
        return;
    }

    possible = true;
    map<int, int> root_map = dfs(1, 0);

    if (possible && root_map.empty()) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--) solve();

    return 0;
}