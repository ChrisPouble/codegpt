#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, ans = 0;
int f[1 << N][N];
string s[N];

signed main() {
    memset(f, 0, sizeof(f));

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    f[1][0] = 0;
    for (int i = 0; i < n; i++) {
    	f[1 << i][i] = s[i].size();
    	ans = max(ans, f[i << i][i]);
	}
    
    int mst = 1 << n;
    for (int i = 0; i < mst; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << k))) continue;
                if (s[k][s[k].size() - 1] != s[j][0]) continue;
                
                int nst = i + (1 << j);
                f[nst][j] = max(f[i][k] + (int)s[j].size(), f[nst][j]);
                ans = max(ans, f[nst][j]);
            }
        }
    }
    // for (int i = 0; i < mst; i++)
    //     for (int j = 0; j < n; j++)
    //         cout << i << " " << j << " " << f[i][j] << endl;
    for (int st = 0; st < mst; st++)
        for (int i = 1; i < n; i++)
            ans = max(ans, f[mst - 1][st]);
        
    cout << ans << endl;
    return 0;
}
