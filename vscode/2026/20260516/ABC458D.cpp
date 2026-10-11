#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int> > small; // 小根堆
priority_queue <int, vector<int>, less<int> > big; // 大根堆

int mid, q;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> mid >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a <= mid) big.push(a);
        else small.push(a);

        if (b <= mid) big.push(b);
        else small.push(b);

        if (small.size() != big.size()) {
            while (small.size() > big.size()) {
                big.push(mid);
                mid = small.top();
                small.pop();
            }

            while (small.size() < big.size()) {
                small.push(mid);
                mid = big.top();
                big.pop();
            }
        }

        cout << mid << "\n";
    }

    system("pause");
    return 0;
}