#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

const double Pi = acos(-1);
int n, m;

struct CP {
    CP(double xx = 0, double yy = 0) { x = xx; y = yy; }
    double x, y;
    CP operator + (const CP &B) const
    { return CP(x + B.x, y + B.y); }
    
    CP operator - (const CP &B) const
    { return CP(x - B.x, y - B.y); }
    
    CP operator * (const CP &B) const
    { return CP(x * B.x - y * B.y, x * B.y + y * B.x); }
} f[N << 1], p[N << 1];

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

int tr[N << 1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> f[i].x;
    for (int i = 0; i <= m; i++) cin >> p[i].x;
    
    for (m += n, n = 1; n <= m; n <<= 1); // 只有二的幂才能蝴蝶 
    for (int i = 0; i < n; i++)
        tr[i] = (tr[i >> 1] >> 1) | ((i & 1) ? n >> 1 : 0);
    
    // 提前进行划分奇偶的操作 
    for (int i = 0; i < n; i++) {
    	if (i < tr[i]) swap(f[i], f[tr[i]]);
    	if (i < tr[i]) swap(p[i], p[tr[i]]);
	}
        
    FFT(f, n, 1), FFT(p, n, 1);
    for (int i = 0; i < n; i++) f[i] = f[i] * p[i];
    
    // 回收答案 
    for (int i = 0; i < n; i++)
        if (i < tr[i]) swap(f[i], f[tr[i]]);
    
    FFT(f, n, 0);
    for (int i = 0; i <= m; i++)
		cout << (int)(f[i].x / n + 0.49) << " ";
    return 0;
}