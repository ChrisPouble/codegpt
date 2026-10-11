#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 使用 128 位整数，彻底杜绝坐标相乘和累加时出现的溢出问题
typedef __int128_t int128;

struct Point {
    long long x, y;
};

int main() {
    // 优化输入输出流
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<Point> p(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    // 预处理前缀和数组 (基于原点 (0,0) 的鞋带公式积分)
    // prefA 存的是 2 倍面积
    // prefCX 存的是 2倍面积 * (x1 + x2)
    // prefCY 存的是 2倍面积 * (y1 + y2)
    vector<int128> prefA(N + 1, 0);
    vector<int128> prefCX(N + 1, 0);
    vector<int128> prefCY(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int next_i = (i == N) ? 1 : i + 1; // 环形相连
        long long x1 = p[i].x, y1 = p[i].y;
        long long x2 = p[next_i].x, y2 = p[next_i].y;

        int128 A = (int128)x1 * y2 - (int128)x2 * y1;
        int128 cx = A * (x1 + x2);
        int128 cy = A * (y1 + y2);

        prefA[i] = prefA[i - 1] + A;
        prefCX[i] = prefCX[i - 1] + cx;
        prefCY[i] = prefCY[i - 1] + cy;
    }

    // 处理 Q 次询问
    for (int q = 0; q < Q; ++q) {
        int u, v;
        cin >> u >> v;

        int128 sumA = 0, sumCX = 0, sumCY = 0;

        // 1. 获取沿着原凸多边形边界从 u 走到 v 这一段的总贡献
        if (u < v) {
            // 没有跨越 N -> 1 这个断点
            // 所包含的边是第 u 条 到 第 v-1 条
            sumA = prefA[v - 1] - prefA[u - 1];
            sumCX = prefCX[v - 1] - prefCX[u - 1];
            sumCY = prefCY[v - 1] - prefCY[u - 1];
        } else {
            // 跨越了 N -> 1 这个断点
            // 所包含的边是 u 到 N，再加上 1 到 v-1
            sumA = (prefA[N] - prefA[u - 1]) + prefA[v - 1];
            sumCX = (prefCX[N] - prefCX[u - 1]) + prefCX[v - 1];
            sumCY = (prefCY[N] - prefCY[u - 1]) + prefCY[v - 1];
        }

        // 2. 补上切出来的这一刀，也就是从 v 连回 u 的一条闭合线段
        long long x1 = p[v].x, y1 = p[v].y;
        long long x2 = p[u].x, y2 = p[u].y;

        int128 closeA = (int128)x1 * y2 - (int128)x2 * y1;
        int128 closeCX = closeA * (x1 + x2);
        int128 closeCY = closeA * (y1 + y2);

        // 3. 将原边界贡献与闭合线段贡献相加，得到切下来多边形的总数据
        int128 totalA = sumA + closeA;
        int128 totalCX = sumCX + closeCX;
        int128 totalCY = sumCY + closeCY;

        // 4. 计算最终的质心坐标
        // 根据公式：最终 X = (totalCX / 6) / (totalA / 2) = totalCX / (3 * totalA)
        // 使用 long double 防止精度丢失
        long double ansX = (long double)totalCX / (3.0L * (long double)totalA);
        long double ansY = (long double)totalCY / (3.0L * (long double)totalA);

        cout << fixed << setprecision(10) << ansX << " " << ansY << "\n";
    }

    return 0;
}