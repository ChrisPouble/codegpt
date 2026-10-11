#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int TRIE = 3.5e6 + 10;
const int SEG = 1.3e7 + 10;

int n, m;
int ans[N];

struct Trie {
    int son[TRIE][2], idx;
    int last[TRIE]; // 记录该规则最近一次 Add 的时刻
    
    // 静态链表存储挂在节点上的规则存活时间区间 [l, r]
    struct Interval { int l, r, nxt; } inv[N];
    int headinv[TRIE], totinv;
    
    // 静态链表存储挂在节点上的询问 (a, b, id)
    struct Query { int a, b, id, nxt; } qry[N];
    int headqry[TRIE], totqry;

    // 沿用你的插入思想：遍历字符串插入
    int insert(const string &str) {
        int p = 0; // 0 作为根节点
        for (char c : str) {
            int u = c - '0';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        return p;
    }

    void AddInterval(int p, int l, int r) {
        inv[++totinv] = { l, r, headinv[p] };
        headinv[p] = totinv;
    }

    void AddQuery(int p, int a, int b, int id) {
        qry[++totqry] = { a, b, id, headqry[p] };
        headqry[p] = totqry;
    }
} trie;

struct PersistentSegmentTree {
    struct TreeNode {
        int l, r;
        int val; // 区间和（变化次数之和）
        int tag; // 覆盖标记：-1 无标记，0 推平为 0，1 赋值为 1
    } tree[SEG];
    
    int tot;

    // 沿用你的克隆函数
    int add(int node) {
        tree[++tot] = tree[node];
        return tot;
    }

    void apply(int &node, int v, int l, int r) {
        node = add(node);
        tree[node].tag = v;
        tree[node].val = v * (r - l + 1);
    }

    void pushdown(int node, int l, int r) {
        if (tree[node].tag != -1) {
            int mid = (l + r) >> 1;
            apply(tree[node].l, tree[node].tag, l, mid);
            apply(tree[node].r, tree[node].tag, mid + 1, r);
            tree[node].tag = -1;
        }
    }

    void pushup(int node) {
        tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;
    }

    // 区间推平修改：在 [ql, qr] 上赋值为 v（v = 0 或 1）
    int update(int ql, int qr, int v, int node, int l = 1, int r = n) {
        node = add(node);
        if (ql <= l && r <= qr) {
            tree[node].tag = v;
            tree[node].val = v * (r - l + 1);
            return node;
        }
        pushdown(node, l, r);
        int mid = (l + r) >> 1;
        if (ql <= mid) tree[node].l = update(ql, qr, v, tree[node].l, l, mid);
        if (qr > mid)  tree[node].r = update(ql, qr, v, tree[node].r, mid + 1, r);
        pushup(node);
        return node;
    }

    // 区间求和查询：求 [ql, qr] 内部的变化次数之和
    int query(int ql, int qr, int node, int l = 1, int r = n) {
        if (!node || tree[node].val == 0) return 0;
        if (ql <= l && r <= qr) return tree[node].val;
        // 如果当前区间被整体覆盖，直接数学计算交集长度，避免 pushdown 产生新节点
        if (tree[node].tag != -1) {
            int inter = min(r, qr) - max(l, ql) + 1;
            return inter * tree[node].tag;
        }
        int mid = (l + r) >> 1, res = 0;
        if (ql <= mid) res += query(ql, qr, tree[node].l, l, mid);
        if (qr > mid)  res += query(ql, qr, tree[node].r, mid + 1, r);
        return res;
    }
} seg;

void dfs(int p, int node) {
    // 在当前主席树版本 node 上，施加该节点的所有存活区间影响
    for (int e = trie.headinv[p]; e; e = trie.inv[e].nxt) {
        int l = trie.inv[e].l, r = trie.inv[e].r;
        node = seg.update(l, l, 1, node);                         // 上升沿：切换为当前更长规则
        if (l + 1 <= r) node = seg.update(l + 1, r, 0, node);     // 内部平坦区：推平为 0，抹杀浅层干扰
        if (r + 1 <= n) node = seg.update(r + 1, r + 1, 1, node); // 下降沿：退回浅层规则
    }

    // 顺路只读回答挂在当前节点 p 上的所有询问
    for (int e = trie.headqry[p]; e; e = trie.qry[e].nxt) {
        int a = trie.qry[e].a, b = trie.qry[e].b, id = trie.qry[e].id;
        if (a + 1 <= b) {
            ans[id] = seg.query(a + 1, b, node);
        } else {
            ans[id] = 0;
        }
    }

    // 递归子树（以当前更新后的 node 作为子节点的起点）
    if (trie.son[p][0]) dfs(trie.son[p][0], node);
    if (trie.son[p][1]) dfs(trie.son[p][1], node);
    
    // 回溯：形参 node 按值传递，无需手动做任何撤销操作！
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    seg.tree[0].tag = -1;

    for (int i = 1; i <= n; i++) {
        string opt, str;
        cin >> opt >> str;
        int p = trie.insert(str);
        if (opt == "Add") {
            trie.last[p] = i;
        } else {
            trie.AddInterval(p, trie.last[p], i - 1);
            trie.last[p] = 0;
        }
    }

    // 处理直到最后时刻 n 仍未删除的规则
    for (int p = 1; p <= trie.idx; p++) {
        if (!trie.last[p]) continue;
        trie.AddInterval(p, trie.last[p], n);
    }

    // 读入 m 个询问，离线挂在 Trie 对应节点上
    for (int pro = 1; pro <= m; pro++) {
        string ip; int a, b; cin >> ip >> a >> b;
        trie.AddQuery(trie.insert(ip), a, b, pro);
    }

    dfs(0, 0);

    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";

    return 0;
}