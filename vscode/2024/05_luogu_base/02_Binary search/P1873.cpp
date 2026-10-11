#include <bits/stdc++.h>
using namespace std;

long long n, m, a[1000010];
bool P(long long h) { //判断砍树高度为h时，砍到的木伐是否能达到m
    long long sum = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] > h) sum += a[i] - h;
    if (sum >= m) return true;
    else return false;
}

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long l = 1, r = 1e8, ans = 0; //其实r也可以定义成最高的树的高度
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(P(mid)) ans = mid, l = mid + 1;//mid有可能成为答案，但还可以接着寻找更优解
        else r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}