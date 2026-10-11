// Problem: ATcoder - Chmax
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_f
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int inf = 1e9;

int tree[N << 2];
int lazy[N << 2];

void push_down(int node) {
    if (lazy[node] != 0) {
        tree[node << 1] += lazy[node];
        lazy[node << 1] += lazy[node];
        
        tree[node << 1 | 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        
        lazy[node] = 0;
    }
}

void build(int node, int L, int R) {
    lazy[node] = 0;
    if (L == R) {
        tree[node] = (L == 0) ? 0 : -inf;
        return;
    }

    int mid = L + (R - L) / 2;
    
    build(node << 1, L, mid);
    build(node << 1 | 1, mid + 1, R);
    
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

void update_add(int node, int L, int R, int ql, int qr, int val) {
    if (ql <= L && R <= qr) {
        tree[node] += val;
        lazy[node] += val;
        return;
    }

    push_down(node);
    
    int mid = L + (R - L) / 2;
    
    if (ql <= mid) update_add(node << 1, L, mid, ql, qr, val);
    if (qr > mid)  update_add(node << 1 | 1, mid + 1, R, ql, qr, val);
    
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

void update_max(int node, int L, int R, int idx, int val) {
    if (L == R) {
        tree[node] = max(tree[node], val);
        return;
    }

    push_down(node);
    
    int mid = L + (R - L) / 2;
    
    if (idx <= mid) update_max(node << 1, L, mid, idx, val);
    else update_max(node << 1 | 1, mid + 1, R, idx, val);
    
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

int query_max(int node, int L, int R, int ql, int qr) {
    if (ql > qr) return -inf;
    if (ql <= L && R <= qr) return tree[node];
    
    push_down(node);
   
    int mid = L + (R - L) / 2;
    int res = -inf;
   
    if (ql <= mid) res = max(res, query_max(node << 1, L, mid, ql, qr));
    if (qr > mid)  res = max(res, query_max(node << 1 | 1, mid + 1, R, ql, qr));
    
    return res;
}

int n, p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i];

    build(1, 0, n - 1);
    
    int Ma = 0;

    for (int i = 0; i < n; i++) {
        int now = p[i];
        
        if (now < Ma) {
            int val = query_max(1, 0, n - 1, 0, now - 1);
            update_max(1, 0, n - 1, now, val + 1);
        } else {
            int val = tree[1]; 
            update_add(1, 0, n - 1, 0, n - 1, 1);
            update_max(1, 0, n - 1, Ma, val + 1);
            Ma = now; 
        }
    }

    cout << tree[1] << "\n";

    return 0;
}