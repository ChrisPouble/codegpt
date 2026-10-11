#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

int n;
ULL k;

void f(int n, ULL k) {
    if (n == 1) {
        if (k) cout << "1";
        else cout << "0";
        return;
    }
    
    ULL x = (1ull << (n - 1));  // 补充括号使位移优先级更明确
    if (k < x) {
        cout << "0";
        f(n - 1, k);
    } else {
        cout << "1";
        f(n - 1, (x << 1) - k - 1);
    }
}

int main() {
    cin >> n >> k;
    f(n, k);
    return 0;
}