#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, q;
string t, a;
map<char, bool> s1, s2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
    cin >> n >> m;
    cin >> t >> a;

    for (int i = 0; i < t.size(); i++)
        s1[t[i]] = 1;
    
    for (int i = 0; i < a.size(); i++)
        s2[a[i]] = 1;
    
    cin >> q;

    while (q--) {
        string s;
        cin >> s;

        bool is1 = 1;
        for (int i = 0; i < s.size(); i++)
            if (!s1[s[i]]) is1 = 0;

        bool is2 = 1;
        for (int i = 0; i < s.size(); i++)
            if (!s2[s[i]]) is2 = 0;
        
        if (is1 && !is2) cout << "Takahashi\n";
        if (!is1 && is2) cout << "Aoki\n";
        if (!(is1 ^ is2)) cout << "Unknown\n";
    }

	return 0;
}