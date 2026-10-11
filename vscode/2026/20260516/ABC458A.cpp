#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int main() {
    cin >> s; 
    cin >> n;

    for (int i = n; i < s.size() - n; i++)
        cout << s[i];

    // cout << ans << endl;

    return 0;
}