#include<bits/stdc++.h>
using namespace std;

int a[200010], ha[200010];
int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int n, m, head = 100000 + 1; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[100000 + i] = i;
        ha[i] = 100000 + i;
    }
    for (int i = 1; i <= m; i++) {
        int temp; cin >> temp;
        swap(a[ha[temp]], a[--head]);
        ha[temp] = head;
    }
    for (int i = 1; i <= 200005; i++)
        if(a[i] != 0) cout << a[i] << " ";
    return 0;
}