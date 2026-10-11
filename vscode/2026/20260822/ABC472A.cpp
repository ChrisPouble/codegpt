#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') cout << 'A';
        else cout << '.';
    }
    return 0;
}