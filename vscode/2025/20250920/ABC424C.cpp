#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N], b[N];
int vis[N], ans;

vector<int> linker[N];

void add(int x, int y) {
    linker[x].push_back(y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] && b[i]) {
            add(a[i], i);
            add(b[i], i);
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!a[i] && !b[i]) {
            vis[i] = 1;
            q.push(i);
        }
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int v : linker[x]) {
            if (vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i++)
        ans += vis[i];
    
    cout << ans << endl;

    system("pause");
    return 0;
}