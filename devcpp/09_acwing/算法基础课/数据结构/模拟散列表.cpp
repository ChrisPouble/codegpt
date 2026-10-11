#include <bits/stdc++.h>
#define maxn 100010
#define mod 200003
using namespace std;

int n;
vector<int>h[mod];
int find(int k) {
    int x = (k % mod + mod) % mod;
    for (auto i:h[x]) if(i == k) return 1;
    return 0;
}

void insert(int k) {
    int x = (k % mod + mod) % mod;
    for (auto i:h[x]) if(i == k) return ;
    h[x].push_back(k);
}

int main() {
    cin >> n;
    while(n--) {
        string opt;
        int x;
        cin >> opt >> x;
        if(opt == "I") insert(x);
        else cout << (find(x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
