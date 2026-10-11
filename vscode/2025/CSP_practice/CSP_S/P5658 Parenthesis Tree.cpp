#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;

int n;
char a[N];

int fa[N];
vector<int> linker[N];

int f[N], g[N];
// f[i] 表示从根节点到节点 i 的字符串路径中的合法括号子串的数量
// g[i] 表示从根节点到节点 i 的字符串路径中以节点 i 为右端点的合法括号子串的数量
stack<int> st;

void dfs(int x) {
    int top = -1;
    if (a[x] == '(') {
        st.push(x);
    } else if (!st.empty()) {
        top = st.top();
        st.pop();
        g[x] = g[fa[top]] + 1;
    }
    
    f[x] = f[fa[x]] + g[x];
    for (int son : linker[x])
        dfs(son);
    
    if (a[x] == '(') st.pop();
    else if (top != -1)  st.push(top);
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        linker[fa[i]].push_back(i);
    }

    dfs(1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res ^= i * f[i];

    cout << res << endl;

    system("pause");
    return 0;
}