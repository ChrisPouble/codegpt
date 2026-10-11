#include <iostream>
#include <algorithm>
#include <istream>
#include <ostream>
#include <cstdio>
using namespace std;
    
long long a[20010];
int n, c;
int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += upper_bound(a + 1, a + n + 1, a[i] + c) - lower_bound(a + 1, a + n + 1, a[i] + c);
        /*lower_bound(begin(), end(), val)：在值有序的数组连续地址[begin, end)中找到val第一个位置并返回其地址，且数组仍然有序
        例如：数列a = {3, 3, 3, 3, 4, 4, 7, 7}
        lower_bound(a, a + n, 3) - a = 0, lower_bound(a, a + n, 7) - a = 6*/
        /*upper_bound(begin(), end(), val)：在值有序的数组连续地址[begin, end)中找到val最后一个位置并返回其地址，且数组仍然有序
        例如：数列a = {3, 3, 3, 3, 4, 4, 7, 7}
        lower_bound(a, a + n, 3) - a = 4, lower_bound(a, a + n, 7) - a = 8*/
    cout << ans << endl;
    return 0;
}