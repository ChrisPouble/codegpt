#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const double Pi = acos(-1.0);
const int M = 1e5 + 10;
const int K = 2.3e3 + 10;
const int LEN = 16384;

// ------ 你的复数和 FFT 模板 ------
struct CP {
    CP(double xx = 0, double yy = 0) { x = xx; y = yy; }
    double x, y;
    CP operator + (const CP &B) const { return CP(x + B.x, y + B.y); }
    CP operator - (const CP &B) const { return CP(x - B.x, y - B.y); }
    CP operator * (const CP &B) const { return CP(x * B.x - y * B.y, x * B.y + y * B.x); }
};

void FFT(CP *f, int len, bool flag) {
    if (len == 1) return;
    FFT(f, len / 2, flag);
    FFT(f + len / 2, len / 2, flag);
    
    // 计算初始值 
    CP tG(cos(2 * Pi / len), sin(2 * Pi / len)), buf(1, 0);
    if (!flag) tG.y *= -1; // 判别正与反 
    for (int k = 0; k < len / 2; k++) {
        CP tt = buf * f[k + len / 2]; // 计算贡献 
        f[k + len / 2] = f[k] - tt; // 带入公式 
        f[k] = f[k] + tt; // 带入公式 
        buf = buf * tG; // 乘方增加 
    }
}

int n, k, m;
int b[M], V[K];
int C[K][K];       // 转移频次矩阵
ll indeg[K];   // 作为后继字符出现的频次
ll term3[K];   // 统计相邻元音对的扣减项

int tr[LEN];
CP V_poly[LEN];
CP P_poly[LEN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    uint64_t seed;
    cin >> n >> k >> seed >> m;

    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 0; i < k; i++) cin >> V[i];

    uint32_t k_uint = k;
    uint64_t state = seed;
    int First = 0;
    
    // 边流式生成 A 边统计，不需要开 7e6 长度的大数组
    for (int i = 1, prev_A = 0; i <= n; i++) {
        int curr_A = 0;
        if (i <= m) {
            curr_A = b[i];
        } else {
            uint64_t x = (((state >> 18) ^ state) >> 27) & 0xFFFFFFFF;
            uint64_t r = state >> 59;
            uint64_t y = ((x >> r) + (x << (32 - r))) & 0xFFFFFFFF;
            curr_A = y % k_uint;
            state = (state * 6364136223846793005ULL + 2026081520260815ULL);
        }
        
        if (i == 1) {
            First = curr_A;
        } else {
            C[prev_A][curr_A]++;
            indeg[curr_A]++;
        }
        prev_A = curr_A;
    }

    // 确定 FFT 长度（向上取 2 的整数次幂）
    int fft_len = 1;
    while (fft_len < 3 * k) fft_len <<= 1;
    for (int i = 0; i < fft_len; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? fft_len >> 1 : 0);

    // 预处理 V 周期延拓数组的 FFT
    for (int i = 0; i < fft_len; i++) V_poly[i] = CP(0, 0);
    for (int i = 0; i < 2 * k - 1; i++) V_poly[i].x = V[i % k];

    for (int i = 0; i < fft_len; i++) {
        if (i < tr[i]) swap(V_poly[i], V_poly[tr[i]]);
    }
    FFT(V_poly, fft_len, 1);

    // 双行合并 FFT：步长为 2 遍历 x，实部放第 x 行，虚部放第 x+1 行
    for (int x = 0; x < k; x += 2) {
        for (int i = 0; i < fft_len; i++) P_poly[i] = CP(0, 0);
        for (int j = 0; j < k; j++) {
            P_poly[j].x = C[x][k - 1 - j]; // 翻转后放入实部
            if (x + 1 < k) {
                P_poly[j].y = C[x + 1][k - 1 - j]; // 翻转后放入虚部
            }
        }
        
        // 位逆序预处理
        for (int i = 0; i < fft_len; i++) {
            if (i < tr[i]) swap(P_poly[i], P_poly[tr[i]]);
        }
        FFT(P_poly, fft_len, 1);
        
        // 频域乘法点乘
        for (int i = 0; i < fft_len; i++) {
            P_poly[i] = P_poly[i] * V_poly[i];
        }
        
        // 逆变换还原
        for (int i = 0; i < fft_len; i++) {
            if (i < tr[i]) swap(P_poly[i], P_poly[tr[i]]);
        }
        FFT(P_poly, fft_len, 0);
        
        // 提取卷积结果并累加
        for (int p = 0; p < k; p++) {
            ll rx = llround(P_poly[k - 1 + p].x / fft_len);
            if (V[(x + p) % k]) term3[p] += rx;
            
            if (x + 1 < k) {
                ll rx1 = llround(P_poly[k - 1 + p].y / fft_len);
                if (V[(x + 1 + p) % k]) term3[p] += rx1;
            }
        }
    }

    // 整合三部分贡献并输出每个 k 的音节数
    for (int p = 0; p < k; p++) {
        ll other = 0;
        for (int q = 0; q < k; q++) {
            if (V[(q + p) % k]) {
                other += indeg[q];
            }
        }
        cout << V[(First + p) % k] + other - term3[p] << "\n";
    }

    return 0;
}