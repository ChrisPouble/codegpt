#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    for (; x <= 1000; x++, y++)
        if (x == y * z) {
            cout << "Yes\n";
            return 0;
        }
    
    cout << "No\n";

    return 0;
}