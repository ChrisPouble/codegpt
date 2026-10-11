#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010;

int work(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c == '.') return 11;
    if (c == ':') return 12;
}

int n;

int idx, trie[N * 30][15];
int id[N * 30];

bool check(string s) {
    int num[10];
    for (int i = 1; i <= 7; i++)
        num[i] = 0;
    
    string str = "";
    for (int i = 0; i < s.size(); i++)
        if (work(s[i]) >= 11) str += s[i];
    
    for (int i = 1; i < s.size(); i++) {
        if (work(s[i]) >= 11 && work(s[i - 1]) >= 11) return 0;
    }
    
    if (s[s.size() - 1] == ':') return 0;
    
    if (str.size() != 4) return 0;
    for (int i = 0; i < str.size() - 1; i++)
        if (str[i] != '.') return 0;
    if (str[str.size() - 1] != ':') return 0;

    for (int i = 1, now = 0; i <= 5; i++, now++) {
        int k = now;
        while (now < s.size() && work(s[now]) < 11) {
            if (now + 1 < s.size() && work(s[now]) == 0 && work(s[now + 1]) < 11 && (now == 0 || work(s[now - 1]) >= 11))
                return 0;
            num[i] = num[i] * 10 + work(s[now]);
            now++;
        }
        if (now - k + 1 >= 8) return 0;
    }
    
    for (int i = 1; i <= 4; i++)
        if (num[i] > 255) return 0;
    
    return num[5] <= 65535;
}

int find(string s) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int v = work(s[i]);
        if (!trie[pos][v]) return -1;
        pos = trie[pos][v];
    }
    return id[pos];
}

void add(string s, int k) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int v = work(s[i]);
        if (!trie[pos][v]) trie[pos][v] = ++idx;
        pos = trie[pos][v];
    }
    id[pos] = k;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    string opt, ad;
    for (int i = 1; i <= n; i++) {
        cin >> opt >> ad;
        
        if (!check(ad)) {
            cout << "ERR\n";
            continue;
        }

        if (opt == "Server") {
            if (find(ad) < 1) {
                add(ad, i);
                cout << "OK\n";
            } else cout << "FAIL\n";
        }

        if (opt == "Client") {
            if (find(ad) >= 1) cout << find(ad) << "\n";
            else cout << "FAIL\n";
        }
    }

    system("pause");
    return 0;
}