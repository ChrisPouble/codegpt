#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main() {
    cin >> a >> b >> c;
    if (a == b) cout << "Yes\n";
    else if (a == c) cout << "Yes\n";
    else if (b == c) cout << "Yes\n";
    else cout << "No\n";
    
    system("pause");
    return 0;
}