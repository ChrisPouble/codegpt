#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

struct node {
    int a, b;
} p[N];

int n, c, F;
int f[N], g[N];
priority_queue<int> q1, q2;

bool cmp(node x, node y) {
    return x.a < y.a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> F;

    for (int i = 1; i <= c; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p + 1, p + c + 1, cmp);

    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        q1.push(p[i].b);
        sum += p[i].b;
    }

    for (int i = n / 2 + 1; i <= c - n / 2; i++) {
        f[i] = sum;
        int b = p[i].b;
        if (b < q1.top()) {
            sum -= q1.top();
            q1.pop();
            q1.push(b);
            sum += b;
        }
    }

    int res = 0;
    for (int i = c; i >= c - n / 2 + 1; i--) {
        q2.push(p[i].b);
        res += p[i].b;
    }

    for (int i = c - n / 2; i >= n / 2 + 1; i--) {
        g[i] = res;
        int b = p[i].b;
        if (b < q2.top()) {
            res -= q2.top();
            q2.pop();
            q2.push(b);
            res += b;
        }
    }

    for (int i = c - n / 2; i >= n / 2 + 1; i--) {
        if (f[i] + p[i].b + g[i] <= F) {
            cout << p[i].a << endl;
            // system("pause");
            return 0;
        }
    }

    cout << -1 << endl;

    // system("pause");
    return 0;
}