#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 10;
const int M = 2e5 + 10;

struct Trie {
    vector<pair<int, char> > linker[N];
    int node_cnt;
    int in[N], out[N], timer;

    void clear() {
        for (int i = 0; i <= node_cnt; i++)
            linker[i].clear();
        node_cnt = timer = 0;
    }

    int get_child(int u, char c) {
        for (auto edge : linker[u]) {
            if (edge.second == c) {
                return edge.first;
            }
        }
        return -1;
    }

    int insert(const string& s) {
        int u = 0;
        for (char c : s) {
            int v = get_child(u, c);
            if (v == -1) {
                v = ++node_cnt;
                linker[u].push_back({ v, c });
            }
            u = v;
        }
        return u;
    }

    void dfs(int u) {
        in[u] = ++timer;
        for (auto edge : linker[u])
            dfs(edge.first);
        out[u] = timer;
    }

    void began() { timer = 0, dfs(0); }
} trie1, trie2;

struct Fenwick {
    int n; vector<int> tree;
    
    void init(int len) {
        n = len;
        tree.assign(len + 10, 0);
    }
    
    void add(int i, int delta) {
        if (i <= 0) return;
        for (; i <= n; i += i & -i)
            tree[i] += delta;
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
} fenwick;

struct Item {
    int type;  
    int id;    
    string pref, suff;
    int u, v;  
};

struct Event {
    int x, type, y1, y2, id;
    
    bool operator<(const Event& o) const {
        if (x != o.x) return x < o.x;
        return type < o.type; 
    }
};

int n, q;
int ans[M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    if (!(cin >> n >> q)) return 0;

    map<pair<string, string>, vector<Item> > groups;

    // 1. 读取所有的替换规则
    for (int i = 1; i <= n; i++) {
        string s1, s2; cin >> s1 >> s2;
        
        int len1 = s1.length(), len2 = s2.length();
        int L = 0, R = 0;
        
        while (L < len1 && L < len2 && s1[L] == s2[L]) L++;
        if (L == len1 && L == len2) continue; // 完全一致，忽略
        
        // 从右往左找公共后缀时，不能越过左边已经剥除的部分 L
        while (R < len1 - L && R < len2 - L && s1[len1 - 1 - R] == s2[len2 - 1 - R]) R++;
        
        string core1 = s1.substr(L, len1 - R - L);
        string core2 = s2.substr(L, len2 - R - L);
        string pref = s1.substr(0, L);
        string suff = s1.substr(len1 - R, R);
        
        reverse(pref.begin(), pref.end());

        groups[{ core1, core2 }].push_back({ 0, 0, pref, suff, 0, 0 });
    }

    // 2. 读取所有的询问
    for (int j = 1; j <= q; j++) {
        string t1, t2; cin >> t1 >> t2;
        
        int len1 = t1.length(), len2 = t2.length();
        int L = 0, R = 0;
        
        while (L < len1 && L < len2 && t1[L] == t2[L]) L++;
        if (L == len1 && L == len2) { ans[j] = 0; continue; }
        
        while (R < len1 - L && R < len2 - L && t1[len1 - 1 - R] == t2[len2 - 1 - R]) R++;
        
        string core1 = t1.substr(L, len1 - R - L);
        string core2 = t2.substr(L, len2 - R - L);
        string pref = t1.substr(0, L);
        string suff = t1.substr(len1 - R, R);
        
        reverse(pref.begin(), pref.end());

        groups[{ core1, core2 }].push_back({ 1, j, pref, suff, 0, 0 });
    }

    // 3. 对每一组具有相同差异核心的数据跑一维扫描线
    for (auto& [core_pair, items] : groups) {
        
        bool has_query = false;
        for (const auto& item : items) {
            if (item.type == 1) {
                has_query = true; break;
            }
        }
        if (!has_query) continue;

        trie1.clear(), trie2.clear();

        for (auto& item : items) {
            item.u = trie1.insert(item.pref);
            item.v = trie2.insert(item.suff);
        }

        trie1.began(), trie2.began();

        vector<Event> events;
        for (const auto& item : items) {
            if (item.type == 0) {
                int x1 = trie1.in[item.u], x2 = trie1.out[item.u];
                int y1 = trie2.in[item.v], y2 = trie2.out[item.v];
                events.push_back({ x1, 0, y1, y2, 0 });       // 0 代表 ADD
                events.push_back({ x2 + 1, 1, y1, y2, 0 });   // 1 代表 REMOVE
            } else {
                int x = trie1.in[item.u];
                int y = trie2.in[item.v];
                events.push_back({ x, 2, y, y, item.id });    // 2 代表 QUERY
            }
        }

        sort(events.begin(), events.end());
        fenwick.init(trie2.node_cnt + 2); 

        // 执行扫描线
        for (const auto& ev : events) {
            if (ev.type == 0) {
                fenwick.add(ev.y1, 1);
                fenwick.add(ev.y2 + 1, -1);
            } else if (ev.type == 1) {  // 解析被变更为 1 的 REMOVE
                fenwick.add(ev.y1, -1);
                fenwick.add(ev.y2 + 1, 1);
            } else {                    // 解析被变更为 2 的 QUERY
                ans[ev.id] += fenwick.query(ev.y1);
            }
        }
    }

    for (int j = 1; j <= q; j++)
        cout << ans[j] << "\n";

    return 0;
}