#include <bits/stdc++.h>
using namespace std;

int T, m, a, b, c, t, delta, k;
int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

void hs() {
    cin >> a >> b >> c;
    if(a < 0) a = -a, b = -b, c = -c; //分母要为正数
    delta = b * b - 4 * a * c, k = 1;
    if(delta < 0) { //无解
        cout << "No" << endl;
        return ;
    }
    for (int i = 2; i * i <= delta; i++)
        while(delta % (i * i) == 0) { //把delta弄成最简单
            k *= i;
            delta = delta / (i * i);
        }
    if(delta == 0 || delta == 1) {
        t = abs(gcd(2 * a, -b + k * delta));
        cout << (-b + k * delta) / t;
        if((2 * a) / t != 1) cout << "/" << 2 * a / t;
        cout << endl;
        return;
    }
    t = abs(gcd(2 * a, -b));
    if(-b / t != 0) {
        cout << -b / t;
        if((2 * a) / t != 1) cout << "/" << 2 * a / t;
        cout << "+";
    }
    t = abs(gcd(2 * a, k));
    if(k != 2 * a) {
        if(k / t != 1) cout << k / t << "*";
        cout << "sqrt(" << delta << ")";
        if((2 * a) / t != 1) cout << "/" << 2 * a / t;
    }
    cout << endl;
    return;
}

int main() {
    cin >> T >> m;
    while(T--) hs();
    return 0;
}