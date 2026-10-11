#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 20, P = 1e9 + 7;
int T, L, R;
struct node {
    int s0, s1, s2;
} f[N][10][10][10];

int power7[N], power9[N];
int mod(int v, int u) {
    return (v % u + u) % u;
}

void init() {
    for (int i = 0; i <= 9; i++)
        if (i != 7) {
            auto &v = f[1][i][i % 7][i % 7];
            v.s0++;
            v.s1 += i;
            v.s2 += i * i;
        }
    for (int i = 2, p = 10; i < N; i++, p *= 10)
        for (int j = 0; j <= 9; j++) {
            if(j == 7) continue;
            for (int a = 0; a < 7; a++)
                for (int b = 0; b < 7; b++)
                    for (int k = 0; k <= 9; k++) {
                        if(k == 7) continue;
                        auto &v1 = f[i][j][a][b], v2 = f[i - 1][k][mod(a - j * mod(p, 7), 7)][mod(b - j, 7)];
                        v1.s0 = mod(v1.s0 + v2.s0, P);
                        v1.s1 = mod(v1.s1 + j * (p % P) % P * v2.s0 % P + v2.s1, P);
                        v1.s2 = mod(v1.s2 + v2.s0 * j % P * (p % P) * j % P * (p % P) % P
                                    + 2 * (j * (p % P)) % P * v2.s1 % P 
                                    + v2.s2, P);
                    }
        }
    power7[0] = power9[0] = 1;
    for (int i = 1; i < N; i++) {
        power7[i] = power7[i - 1] * 10 % 7;
        power9[i] = power9[i - 1] * 10 % P;
    }
}

node get(int i, int j, int a, int b) {
    int s0 = 0, s1 = 0, s2 = 0;
    for (int x = 0; x < 7; x++)
        for (int y = 0; y < 7; y++) {
            if (x == a || y == b) continue;
            auto v = f[i][j][x][y];
            s0 = mod(s0 + v.s0, P);
            s1 = mod(s1 + v.s1, P);
            s2 = mod(s2 + v.s2, P);
        }
    return {s0 , s1 , s2};
}

int dp(int n) {
    if(!n) return 0;

    int backup_n = n % P; //备份一个n
    vector<int> num;
    while (n) num.push_back(n % 10), n /= 10;

    int res = 0, last_a = 0, last_b = 0; //last_a表示前缀本身的值，last_b表示前缀各位数之和
    for (int i = num.size() - 1; i >= 0; i--) {
        int x = num[i];
        for (int j = 0; j < x; j++) {
            if(j == 7) continue;
            int a = mod(-last_a * power7[i + 1], 7) , b = mod(-last_b, 7); //防止模7=0
            auto v = get(i + 1, j, a, b); //求得本身模7不等于a，并且各位数之和模7不等b的集合，此时就可以使用预处理出来的结构体
            
            //根据公式求s2，时刻提醒记得及时取模！！！！！！
            //这里的last_a其实也可以作为j，毕竟它也是首位数
            res = mod(res + 
                    (last_a % P) * (last_a % P) % P * (power9[i + 1] % P) % P * (power9[i + 1] % P) % P * v.s0 % P + 
                    2 * (last_a % P) * (power9[i + 1] % P) % P * v.s1 % P + 
                    v.s2,
                P);
        }
        
        if (x == 7) break; //不满足条件
        last_a = last_a * 10 + x;
        last_b += x;
        
        //记得特判n本身
        if (!i && last_a % 7 && last_b % 7) res = mod(res + backup_n * backup_n, P);
    }

    return res;
}

void solve() {
    cin >> L >> R;
    cout << mod(dp(R) - dp(L - 1), P) << endl;
}

signed main() {
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}
