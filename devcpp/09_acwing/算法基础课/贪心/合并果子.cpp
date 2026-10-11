#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, ans, a[maxn];
struct node {
    int val;
    bool operator<(const node &t) const { return val < t.val; }
};

//
// bool operator<(int x, int y) {
//	return x < y;
//}

priority_queue<int, vector<int>, greater<int> > q;

void push(int x) {
    a[++n] = x;
    int t = n;
    while (t != 1 && a[t] <= a[t / 2]) {
        swap(a[t], a[t / 2]);
        t /= 2;
    }
}

void pop() {
    swap(a[n--], a[1]);
    int t = 1;
    while (t <= n) {
        if (t * 2 + 1 <= n && a[t * 2] <= a[t * 2 + 1])
            t = t * 2;
        else if (t * 2 + 1 <= n && a[t * 2 + 1] <= a[t * 2])
            t = t * 2 + 1;
        else if (t * 2 <= n && t * 2 + 1 >= n)
            t = t * 2;
        else
            break;
        if (t > n)
            break;
        else
            swap(a[t / 2], a[t]);
    }
}

int main() {
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        q.push(t);
    }
    while (q.size() > 1) {
        int t1 = q.top(); q.pop();
        int t2 = q.top(); q.pop();
        ans += t1 + t2;
        q.push(t1 + t2);
    }
    cout << ans << endl;
    return 0;
}
