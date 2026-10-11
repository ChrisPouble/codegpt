#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

int n, k, l = 1, r = 0, a[maxn], maxv[maxn], minv[maxn], ansmax[maxn], ansmin[maxn];
void push_max(int x) {
    while(l <= r && a[maxv[r]] < a[x]) r--;
    maxv[++r] = x;
}

void push_min(int x) {
    while(l <= r && a[minv[r]] > a[x]) r--;
    minv[++r] = x;
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(maxv, -1, sizeof(maxv));
    memset(minv, -1, sizeof(minv));
    for (int i = 1; i <= n; i++) {
        if (maxv[l] == i - k) l++;
        push_max(i);
        if (i >= k) ansmax[i] = a[maxv[l]];
    }
    l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
        if (minv[l] == i - k) l++;
        push_min(i);
        if (i >= k) ansmin[i] = a[minv[l]];
    }
    for (int i = k; i <= n; i++) cout << ansmin[i] << " ";
    cout << endl;
    for (int i = k; i <= n; i++) cout << ansmax[i] << " ";
    cout << endl;
	return 0;
}
