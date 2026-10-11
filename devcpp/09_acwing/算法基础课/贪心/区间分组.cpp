#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, ans = 1;
struct node {
    int l, r;
    bool operator<(const node &w) {
        return l < w.l;
    }
} a[maxn];

priority_queue<int, vector<int>, greater<int> > heap;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        node x = a[i];
        if (heap.empty() || heap.top() >= x.l) heap.push(x.r);
        else heap.pop(), heap.push(x.r);
    }
    cout << heap.size() << endl;
    return 0;
}
