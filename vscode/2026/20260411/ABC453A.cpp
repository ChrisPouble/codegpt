#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n;
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    string s;
    cin >> n >> s;

    int now = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'o') {
            now = i;
            break;
        }
    }

    for (int i = now; i < s.size(); i++)
        cout << s[i];

    system("pause");
    return 0;
}