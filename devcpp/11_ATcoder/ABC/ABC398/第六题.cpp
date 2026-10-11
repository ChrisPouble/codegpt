#include <bits/stdc++.h>
#define N 1000010
#define M 1000010
using namespace std;

int n, m, ne[N];
string s, r;
signed main() {
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) r += s[i];
    string T = " " + r + "#" + s;
    for (int i = 2, j = 0; i < T.size(); i++) {
        while(j && T[i] != T[j + 1]) j = ne[j];
        if(T[i] == T[j + 1]) j++;
        ne[i] = j;
    }
    cout << s;
    for (int i = ne[T.size() - 1]; i < r.size(); i++) cout << r[i];
	return 0;
}
