#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
int n, sum[N];
int d1[N], d2[N], ans; //d1表示最大，d2表示次大
vector<int>linker[N];
void add(int a, int b) {
    linker[a].push_back(b);
}

void dfs(int x) {
    if (d1[x]) return;  //记忆化搜索
    for (auto son:linker[x]) {
        dfs(son);
        if (d1[son] + 1 >= d1[x]) d2[x] = d1[x], d1[x] = d1[son] + 1;
        else if (d1[son] + 1 > d2[x]) d2[x] = d1[son] + 1;
    }
    ans = max(ans, d1[x] + d2[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            sum[i * j] += i;
    for (int i = 2; i <= n; i++)
        if (sum[i] < i) add(sum[i], i);
    for (int i = 1; i <= n; i++) dfs(i);
    printf("%d\n", ans);
    return 0;
}
