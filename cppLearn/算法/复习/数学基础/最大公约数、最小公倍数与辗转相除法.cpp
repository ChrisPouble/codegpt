#include <iostream>
using namespace std;

int m, n;
int gcd1() {
    int r = m;
    while (r != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

int gcd2(int b, int a) {
    return a ? gcd2(a, b % a) : b;
}

int main() {
    cin >> m >> n;
    if (m < n) swap(m, n);
    cout << "最大公约数:" << gcd2(m, n) << " 最小公倍数:" << m * n / gcd2(m, n) << endl;
    return 0;
}