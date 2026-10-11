#include<bits/stdc++.h>
using namespace std;

int N, B, D, a[20]; //神牛总数、神牛的角数、比较数
bool bijiao(int x, int y) {
    int cnt = 0;
    for (int i = 0; i <= 7; i++)
        if (((x ^ y) >> i) & 1) cnt++;
    if (cnt < D) return false;
    else return true;
}

void dfs(int x) {
    if (x > N) {
        for (int i = 1; i <= N; i++)
            cout << a[i] << " ";
        exit(0);
    }
    for (int i = a[x - 1] + 1; i <= (1 << B); i++) {
        bool is = true;
        for (int j = 1; j <= x - 1; j++)
            if(!bijiao(a[j], i)) {
                is = false;
                break;
            }
        if(is) {
            a[x] = i;
            dfs(x + 1);
        }
    }
}

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> N >> B >> D;
    a[1] = 0;
    dfs(2);
    return 0;
}