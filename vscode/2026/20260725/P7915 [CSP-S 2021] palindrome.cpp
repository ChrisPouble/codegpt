#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, a[2 * N];

string check(int pos) { // 第一个移动的位置
    int p = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if (i != pos && a[i] == a[pos]) {
            p = i; break;
        }
    }
    
    // 划分左右两个区间
    int l1 = (pos == 1) ? 2 : 1;
    int r1 = p - 1;
    int l2 = p + 1;
    int r2 = (pos == 1) ? 2 * n : 2 * n - 1;
    
    // opL 记录前 n 步操作，opR 记录后 n 步操作
    string opL = (pos == 1) ? "L" : "R";
    string opR = "L"; // 最后一个元素必然是 L (仅剩一个元素时选左边字典序更小)
    // opL.reserve(n), opR.reserve(n);
    
    for (int step = 1; step < n; ++step) {
        if (l1 < r1 && a[l1] == a[r1]) {
            opL += 'L'; opR += 'L';
            l1++; r1--;
        } else if (l1 <= r1 && l2 <= r2 && a[l1] == a[l2]) {
            opL += 'L'; opR += 'R';
            l1++; l2++;
        } else if (l1 <= r1 && l2 <= r2 && a[r2] == a[r1]) {
            opL += 'R'; opR += 'L';
            r2--; r1--;
        } else if (l2 < r2 && a[r2] == a[l2]) {
            opL += 'R'; opR += 'R';
            r2--; l2++;
        } else return "";
    }
    
    reverse(opR.begin(), opR.end());
    return opL + opR;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
        cin >> a[i];
    
    string ans = check(1);
    if (!ans.empty()) { cout << ans << "\n"; return; }
    
    ans = check(2 * n);
    if (!ans.empty()) { cout << ans << "\n"; return; }
    
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}