#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, m;
vector<int> e[N];
pair<int, int> edge[N];
int del_u, del_v;
vector<int> ans(N, N);
vector<int> path(N);
bool st[N];
int cnt, state;

bool dfs(int u) {
    if (!state) {
        if (u > ans[cnt]) return true;
        if (u < ans[cnt]) state = -1;
    }

    st[u] = true;
    path[cnt++] = u;

    for (int i = 0; i < e[u].size(); i++) {
        int x = e[u][i];
        if (!(x == del_u && u == del_v) && !(x == del_v && u == del_u) && !st[x])
            if (dfs(x)) return true;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        e[a].push_back(b);
        e[b].push_back(a);
        edge[i] = {a, b};
    }

    for (int i = 1; i <= n; i++) 
        sort(e[i].begin(), e[i].end());
    
    if (n == m) {
        for (int i = 0; i < m; i++) {
            del_u = edge[i].first;
            del_v = edge[i].second;

            memset(st, false, sizeof st);
            cnt = state = 0;
            dfs(1);
            if (cnt == n) 
                ans = path;
        }
    } else {
        dfs(1);
        if (cnt == n) 
            ans = path;
    }
    
    for (int i = 0; i < n; i++) 
        printf("%d ", ans[i]);

    return 0;
}