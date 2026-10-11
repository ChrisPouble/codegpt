#include <bits/stdc++.h>
using namespace std;

int n, ans;
string a[25];
bool flag[25];
string add(string x, string y) {
    if(x[x.size() - 1] != y[0]) return "I_AK_IOI";
    else return x + y;
}

void dfs(string s) {
    bool isLast = 0;
    
    for (int i = 1; i <= n; i++)
        if (!flag[i]) {
            string x = add(s, a[i]);
            if(x != "I_AK_IOI") {
                isLast = 1;
                flag[i] = 1;
                dfs(x);
                flag[i] = 0;
            }
		}
    if (!isLast) ans = max(ans, (int)s.size());
}

int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        memset(flag, 0, sizeof(flag));
        flag[i] = 1;
        dfs(a[i]);
        flag[i] = 0;
	}
    cout << ans << endl;
    return 0;
}
