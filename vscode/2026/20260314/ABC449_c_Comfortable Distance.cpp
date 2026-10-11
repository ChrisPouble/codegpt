#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, L, R;
string s;

map<char, vector<int> > mp;

int getl(char x, int now) {
    int l = now, r = mp[x].size() - 1, ans = 1e9;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (mp[x][mid] - mp[x][now] < L) l = mid + 1, ans = mid;
        else r = mid - 1;
    }

    return ans;
}

int getr(char x, int now) {
    int l = now, r = mp[x].size() - 1, ans = 1e9;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (mp[x][mid] - mp[x][now] <= R) l = mid + 1, ans = mid;
        else r = mid - 1;
    }

    return ans;
}

signed main() {
    cin >> n >> L >> R;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        mp[s[i]].push_back(i);

    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < mp[c].size(); i++) {
//        	cout << mp[c][i] << endl;
            int lx = getl(c, i), rx = getr(c, i);
            
//            cout << lx << " " << rx << endl;
            if (lx == 1e9 || rx == 1e9) continue;

            ans += rx - lx;
        }
    }
    
    cout << ans << endl;

    return 0;
}
