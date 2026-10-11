#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, lena, lenb;
int a1[N], b1[N];
string a, b;

void solve() {
    for (int i = 1; i <= lena; i++) a1[i] = 0;
    for (int i = 1; i <= lenb; i++) b1[i] = 0;

    cin >> a >> b;

    lena = a.size(), lenb = b.size();
    a = " " + a, b = " " + b;

    for (int i = 1; i < lena; i++) {
        if (!(a[i] == 'x' && a[i + 1] == 'x')) continue;

        int l = i - 1, r = i + 2;
        while (l >= 1 && r <= lena) {
            if (a[l] == '(' && a[r] == ')') a1[l] = a1[r] = 1; // 不用输出
            else break;

            l--, r++;
        }

        i = r - 1;
    }

    for (int i = 1; i < lenb; i++) {
        if (!(b[i] == 'x' && b[i + 1] == 'x')) continue;

        int l = i - 1, r = i + 2;
        while (l >= 1 && r <= lenb) {
            if (b[l] == '(' && b[r] == ')') b1[l] = b1[r] = 1; // 不用输出
            else break;

            l--, r++;
        }

        i = r - 1;
    }

    string na = "", nb = "";
    for (int i = 1; i <= lena; i++)
        if (a1[i] == 0) na += a[i];

    for (int i = 1; i <= lenb; i++)
        if (b1[i] == 0) nb += b[i];
    
    if (na.size() != nb.size()) {
        cout << "No\n";
        return ;
    }

    for (int i = 0; i < na.size(); i++) {
        if (na[i] != nb[i]) {
            cout << "No\n";
            return ;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--) solve();
    
    // system("pause");
    return 0;
}