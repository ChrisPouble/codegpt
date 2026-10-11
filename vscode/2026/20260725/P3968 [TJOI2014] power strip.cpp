// time：21 : 19
#include <bits/stdc++.h>
using namespace std;

const int N = 6e6 + 10; 

int n, q, root;
int tot = 1;
map<int, int> cnt;

struct node {
    int l, r, ls, rs;
    int siz, all, le, re;
} tree[N];

void newnode(int &rt, int l, int r) {
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].all = tree[rt].le = tree[rt].re = tree[rt].siz = r - l + 1;
}

void pushup(int rt) {
    int ls = tree[rt].ls, rs = tree[rt].rs;
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    
    if (!ls) newnode((ls = tree[rt].ls = ++tot), tree[rt].l, mid);
    if (!rs) newnode((rs = tree[rt].rs = ++tot), mid + 1, tree[rt].r);
    
    tree[rt].all = max({ tree[ls].all, tree[rs].all, tree[ls].re + tree[rs].le });
    
    tree[rt].le = tree[ls].le;
    if (tree[ls].le == tree[ls].r - tree[ls].l + 1) tree[rt].le += tree[rs].le;
    
    tree[rt].re = tree[rs].re;
    if (tree[rs].re == tree[rs].r - tree[rs].l + 1) tree[rt].re += tree[ls].re;
    
    tree[rt].siz = tree[ls].siz + tree[rs].siz;
}

void update(int &rt, int l, int r, int x, int v) {
    if (!rt) newnode((rt = ++tot), l, r);
    if (l == r) { tree[rt].all = tree[rt].le = tree[rt].re = tree[rt].siz = v; return ; }
    
    if (x <= (l + r) >> 1) update(tree[rt].ls, l, (l + r) >> 1, x, v);
    else update(tree[rt].rs, ((l + r) >> 1) + 1, r, x, v);
    
    pushup(rt);
}

pair<int, int> get(int rt, int maxlen) {
    if (!tree[rt].ls) { 
        int l = tree[rt].l, r = tree[rt].r, mid = (l + r) >> 1;
        newnode((tree[rt].ls = ++tot), l, mid);
        newnode((tree[rt].rs = ++tot), mid + 1, r);
        return { l, r };
    }
    
    if (tree[tree[rt].rs].all == maxlen) return get(tree[rt].rs, maxlen);
    
    if (tree[tree[rt].ls].re + tree[tree[rt].rs].le == maxlen) {
        int la = tree[tree[rt].ls].r - tree[tree[rt].ls].re + 1;
        int ra = tree[tree[rt].rs].l + tree[tree[rt].rs].le - 1;
        return { la, ra };  
    }
    
    return get(tree[rt].ls, maxlen);
}

int query2(int &rt, int l, int r, int x, int y) {
    if (!rt) newnode((rt = ++tot), l, r);
    if (tree[rt].l > y || tree[rt].r < x) return 0;
    if (x <= tree[rt].l && tree[rt].r <= y) return tree[rt].siz;
    
    int mid = (tree[rt].l + tree[rt].r) >> 1, ans = 0;
    
    if (x <= mid) ans += query2(tree[rt].ls, l, mid, x, y);
    if (y > mid)  ans += query2(tree[rt].rs, mid + 1, r, x, y);
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> q;
    newnode((root = 1), 1, n);
    
    for (int i = 1, id, l, r; i <= q; i++) {
        cin >> id;
        
        if (!id) {
            cin >> l >> r;
            cout << (r - l + 1) - query2(root, 1, n, l, r) << "\n";
        } else {
            if (cnt[id]) {
                update(root, 1, n, cnt[id], 1);
                cnt[id] = 0;
            } else {
                auto p = get(root, tree[root].all);
                cnt[id] = (p.first + p.second + 1) >> 1;
                update(root, 1, n, cnt[id], 0);
            }
        }
    }
    
    return 0;
}