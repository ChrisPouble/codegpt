#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, m, root, ans, v[maxn], w[maxn], f[maxn][maxn]; //f[i][j]表示以i为根的子树限重为j的最大权值（选i）
vector<int> linker[maxn];
void dfs(int x) {
    for (int j = m; j >= v[x]; j--) f[x][j] = w[x];
    for (auto son:linker[x]) {
        dfs(son);
        for (int j = m; j >= v[x]; j--)
            for (int k = 0; k <= j - v[x]; k++)
                f[x][j] = max(f[x][j], f[x][j - k] + f[son][k]);
    }
    // for (int j = 0; j < v[x]; j++) f[x][j] = 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1, p; i <= n; i++) {
        cin >> v[i] >> w[i] >> p;
        if(p != -1) linker[p].push_back(i);
        else root = i;
    }
    dfs(root);
    cout << f[root][m] << endl;
	return 0;
}
