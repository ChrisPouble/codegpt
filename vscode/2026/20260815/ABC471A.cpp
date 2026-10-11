#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;

    if (A + B == 9) cout << "Nine\n";
    else if (A - B == 9) cout << "Nine\n";
    else if (A * B == 9) cout << "Nine\n";
    else if (A == 9 * B) cout << "Nine\n";
    else cout << "Nein\n";

    return 0;
}