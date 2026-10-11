#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N_log_N = 1e7 + 10;
const int N = 2e5 + 10;

int n, m, q;
struct node {
    struct tree {
        int l, r, val;
    } sumv[N_log_N];
    
    int top, tr[N];
    
    int add(int &node) {
        top++;
        sumv[top] = sumv[node];
        return top;
    }
    
    int update(int w, int val, int node, int l = 1, int r = m) {
        node = add(node);
        if (l == r) {
            sumv[node].val = val;
            return node;
        }

        int mid = (l + r) >> 1;
        if (w <= mid) sumv[node].l = update(w, val, sumv[node].l, l, mid);
    	else sumv[node].r = update(w, val, sumv[node].r, mid + 1, r);

        sumv[node].val = sumv[sumv[node].l].val + sumv[sumv[node].r].val;
		return node;
    }
    
    int query(int x, int y, int node, int l = 1, int r = m) {
        if (x <= l && r <= y) return sumv[node].val;
        else {
        	int mid = (l + r) >> 1, res = 0;
        	if (x <= mid) res += query(x, y, sumv[node].l, l, mid);
        	if (y > mid) res += query(x, y, sumv[node].r, mid + 1, r);
            return res;
		}
    }
} tree;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    
    for (int i = 1; i <= q; i++) {
        int op, x, y, z, l, r;
		cin >> op; 
        
        if (op == 1) {
            cin >> x >> y;
            tree.tr[x] = tree.tr[y];
        } else if (op == 2) {
            cin >> x >> y >> z;
            tree.tr[x] = tree.update(y, z, tree.tr[x]);
        } else if (op == 3) {
            cin >> x >> l >> r;
            cout << tree.query(l, r, tree.tr[x]) << "\n";
        }
    }

    // system("pause");
    return 0;
}