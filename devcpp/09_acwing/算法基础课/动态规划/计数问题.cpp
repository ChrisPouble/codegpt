#include <bits/stdc++.h>
#define maxn 18
#define int long long
using namespace std;

int a, b, cnt[maxn];
int get(int r, int l) { //获取从r到l这一串的数字
    int sum = 0;
    for (int i = r; i >= l; i--) sum = sum * 10 + cnt[i];
    return sum;
}

int ksm(int x, int s) { //快速冥
    if(s == 0) return 1;
    int t = ksm(x, s / 2);
    if(s & 1) return t * t * x;
    else return t * t;
}

int work(int n, int x) {
    if(n == 0) return 0;
    int len = 0, ans = 0;
    while(n) cnt[++len] = n % 10, n /= 10; //把每一位数都记录下来，低位的下标较低
    if(x) { //x是不是0
        for (int i = len; i >= 1; i--) { //从高位枚举低位
            if(i < len) ans += get(len, i + 1) * ksm(10, i - 1); //如果不是首位，则考虑第一种情况
            if(cnt[i] == x) ans += get(i - 1, 1) + 1; //接下俩考虑第二种情况
            else if(cnt[i] > x) ans += ksm(10, i - 1);
            else ans += 0;
        }
    } else {
        for (int i = len - 1; i >= 1; i--) { //从高位枚举低位
            ans += (get(len, i + 1) - 1) * ksm(10, i - 1); //由于不枚举首位，因此不需要特判
            if(cnt[i] == x) ans += get(i - 1, 1) + 1;
            else if(cnt[i] > x) ans += ksm(10, i - 1);
            else ans += 0;
        }
    }
    return ans;
}

void solve() {
    if(a > b) swap(a, b);
    for (int i = 0; i <= 9; i++) cout << work(b, i) - work(a - 1, i) << " "; //前缀和
    cout << endl;
}

signed main() {
    while(cin >> a >> b && (a || b)) solve();
    return 0;
}
