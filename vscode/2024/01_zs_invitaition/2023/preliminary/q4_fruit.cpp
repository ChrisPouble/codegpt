#include <bits/stdc++.h>
using namespace std;

int a[10010];
bool cmt(int a, int b) {
    return a > b;
}

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int Case, n; cin >> Case;
    while(Case--) {
        cin >> n;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++) {
            int temp; cin >> temp;
            a[temp]++;
        }
        int k = 1;
        for (int i = 2; i <= n; i++)
            if(a[i] > a[k]) k = i;
        int cnt = n - k;
        if(k - cnt <= 1) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}