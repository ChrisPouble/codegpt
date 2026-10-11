#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 15, M = (N << 1) + 7;   //M --- hash

int n, m, ex, ey;
long long ans = 0;
bool mp[25][25];  //地图
int q[2][M], cnt[2]; //有效状态在 hash 表对应的下标、有效状态的数量

int h[2][M];
long long v[2][M];  //状态对应的方案数

int find(int t, int x) {  //Hash 开放寻址法，求 x 的位置
    int pos = x % M;
    while (h[t][pos] != -1 && h[t][pos] != x) {
        pos++;
        if (pos == M) pos = 0;
    }
    return pos;
}

void insert(int t, int x, long long d) {  //插入状态 x，数量位 d
    int pos = find(t, x);
    if (h[t][pos] == -1) {
        h[t][pos] = x, v[t][pos] = d;
        q[t][++cnt[t]] = pos;
    } else v[t][pos] += d;
}

int get(int S, int k) { //求出四进制数 S 的第 k 位
    return (S >> (k << 1)) & 3;
}

int up(int k, int v) {  //生成一个四进制数，第 k 位是 v
    return v * (1 << (k << 1));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char ch[25]; scanf("\n %s", ch + 1);
        for (int j = 1; j <= m; j++) {
            if (ch[j] == '*') continue;
            mp[i][j] = 1;
            ex = i, ey = j;
        }
    }

    memset(h, -1, sizeof h);
    int t = 0;
    insert(t, 0, 1);    //处置状态
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cnt[t]; j++) h[t][q[t][j]] <<= 2;
        for (int j = 1; j <= m; j++) {
            t ^= 1;
            memset(h[t], -1, sizeof h[t]); cnt[t] = 0;
            for (int k = 1; k <= cnt[t ^ 1]; k++) {
                int S = h[t ^ 1][q[t ^ 1][k]];
                long long w = v[t ^ 1][q[t ^ 1][k]];
                int x = get(S, j - 1), y = get(S, j);
                if (!mp[i][j]) {    //情况一，障碍物
                    if (x == 0 && y == 0) insert(t, S, w);
                } else if (x == 0 && y == 0) {  //情况二、x=y=0
                    if (mp[i + 1][j] && mp[i][j + 1]) {
                        int T = S + up(j - 1, 1) + up(j, 2);
                        insert(t, T, w);
                    }
                } else if (x == 0 && y > 0) {   //情况三、x 是 0，y 非 0
                    if (mp[i][j + 1]) { //向右
                        int T = S;  //不用变
                        insert(t, T, w);
                    }
                    if (mp[i + 1][j]) { //向下
                        int T = S + up(j - 1, y) - up(j, y);
                        insert(t, T, w);
                    }
                } else if (x > 0 && y == 0) {   //情况四、x 非 0，y 是 0
                    if (mp[i][j + 1]) { //向右
                        int T = S + up(j, x) - up(j - 1, x);
                        insert(t, T, w);
                    }
                    if (mp[i + 1][j]) { //向下
                        int T = S;
                        insert(t, T, w);
                    }
                } else if (x == 1 && y == 1) {  //情况五、x=y=1
                    for (int l = j + 1, c = 1; ; l++) {
                        int now = get(S, l);
                        if (now == 1) c++;
                        else if (now == 2) {
                            c--;
                            if (c == 0) {
                                int T = S - up(j - 1, 1) - up(j, 1) - up(l, 2) + up(l, 1);
                                insert(t, T, w);
                                break;
                            }
                        }
                    }
                } else if (x == 2 && y == 2) {  //情况六、x=y=2
                    for (int l = j - 2, c = 1; ; l--) {
                        int now = get(S, l);
                        if (now == 2) c++;
                        else if (now == 1) {
                            c--;
                            if (c == 0) {
                                int T = S - up(j - 1, 2) - up(j, 2) - up(l, 1) + up(l, 2);
                                insert(t, T, w);
                                break;
                            }
                        }
                    }
                } else if (x == 2 && y == 1) {  //情况七、x=2, y=1
                    int T = S - up(j - 1, 2) - up(j, 1);
                    insert(t, T, w);
                } else {    //情况八、x=1, y=2，特判最后一个格子
                    if (i == ex && j == ey) ans += w;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}