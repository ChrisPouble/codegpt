#include <bits/stdc++.h>
using namespace std;

const int eps = 1e-4;
int n;
double ans = 30010.0;
struct zb
{
    double x, y;
} a[20];

double S(double x1, double y1, double x2, double y2)
{
    return (double)sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

bool vis[20];
void dfs(int zuobiao, double x, double y, double s)
{
    if (zuobiao >= n)
    {
        if (ans - s >= eps)
            ans = s;
        return;
    }
    if (ans - s < eps)
        return;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            s += S(x, y, a[i].x, a[i].y);
            dfs(zuobiao + 1, a[i].x, a[i].y, s);
            s -= S(x, y, a[i].x, a[i].y);
            vis[i] = false;
        }
}

int main()
{
    // 获取当前时间点作为起始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 需要测量的代码
    freopen("brick.in", "r", stdin);
    freopen("brick.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    dfs(0, 0.0, 0.0, 0.0);
    printf("%.2f\n", ans);

    // 获取当前时间点作为结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算持续时间
    std::chrono::duration<double> duration = end - start;

    // 输出运行时间（以秒为单位）
    std::cout << "代码运行时间: " << duration.count() << " 秒" << std::endl;

    return 0;
}