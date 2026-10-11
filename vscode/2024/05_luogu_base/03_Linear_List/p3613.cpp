#include <bits/stdc++.h>
using namespace std;

int n, q;
int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n >> q;
    vector<vector<int> >locker(n + 1); //注意尖括号里的空格，否则会被认为成移位运算符而编译错误
    while(q--) {
        int opt; cin >> opt;
        if(opt == 1) {
            int i, j, k; cin >> i >> j >> k;
            if (locker[i].size() < j + 1)
                locker[i].resize(j + 1);
            locker[i][j] = k;
        }
        else  {
            int i, j; cin >> i >> j;
            cout << locker[i][j] << endl;
        }
    }
    return 0;
}