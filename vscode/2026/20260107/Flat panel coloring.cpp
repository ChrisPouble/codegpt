#include <bits/stdc++.h>
using namespace std;

const int N = 18;
const int M = 22;

struct Square {
    int x1, y1, x2, y2, color;
} sq[N];

int n, m, f[1 << N][M];
vector<int> linker[N];

void add(int x, int y) {
    if (sq[x].x2 != sq[y].x1) return ;
    if (sq[x].y1 > sq[y].y2 || sq[x].y2 < sq[y].y1) return ;
    linker[y].push_back(x);
}

bool check(int state, int p) {
    for (int v : linker[p])
        if (!((state >> v) & 1))
            return 0;
    return 1;
}

bool chcol(int state, int col) {
    for (int i = 0; i < n; i++) {
        int x = (state >> i) & 1;
        if (x && sq[i].color == col) return 1;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sq[i].x1 >> sq[i].y1;
        cin >> sq[i].x2 >> sq[i].y2;
        cin >> sq[i].color, m = max(m, sq[i].color);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j) add(i, j);
    
    int mst = (1 << n);

    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= m; i++)
        f[0][i] = 1;

    for (int st = 0; st < mst; st++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if ((st >> j) & 1) continue;
                if (!check(st, j)) continue;
                if (i == sq[j].color) {
                    f[st + (1 << j)][sq[j].color] = min(f[st + (1 << j)][sq[j].color], f[st][i]);
                } else f[st + (1 << j)][sq[j].color] = min(f[st + (1 << j)][sq[j].color], f[st][i] + 1);
            }
        }
    }

    int ans = 1e9;
    for (int i = 1; i <= m; i++)
        ans = min(ans, f[mst - 1][i]);

    cout << ans << endl;
    return 0;
}
