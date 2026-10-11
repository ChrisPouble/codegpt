#include <bits/stdc++.h>
using namespace std;

int n, sum, now = 1, tot = 1, ans[150], fa[150];
bool is_input[150], is[150], c[150][150], vis[150][150];
int find(int x) {
    if(fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void merger(int x, int y) {
    int xx = find(x), yy = find(y);
    fa[xx] = yy;
}

void dfs(int x) {
    if(now == n + 1) {
        for (int i = 1; i <= tot; i++)
            cout << (char)ans[i];
        exit(0);
    }
    for (int i = 'A'; i <= 'z'; i++)
        if(c[x][i] && !vis[x][i] && !is[i]) {
            is[i] = 1;
            now++, tot++;
            ans[tot] = i;
            vis[x][i] = vis[i][x] = 1;
            dfs(i);
            vis[x][i] = vis[i][x] = 0;
            ans[tot] = 0;
            now--, tot--;
            is[i] = 0;
        }
}

int main() {
    cin >> n;
    string s;
    for (int i = 1; i <= 140; i++)
        fa[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int a = s[0], b = s[1];
        is_input[a] = is_input[b] = true;
        c[a][b] = c[b][a] = true;
        merger(a, b);
    }
    for (int i = 1; i <= 140; i++)
        if(is_input[i] == true && fa[i] == i) sum++;
    if(sum >= 2) {
        cout << "No Solution" << endl;
        return 0;
    }
    for (int i = (int)'A'; i <= (int)'z'; i++)
        if(is_input[i]) {
            ans[1] = i;
            is[1] = 1;
            dfs(i);
            break;
        }
    
    return 0;
}