#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define I128 __int128
using namespace std;

const int N = 3146100;
const int A = 3000000, T = 146097, G = A + T;

int D[N], M[N], Y[N];
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isLeap(int y) {
    if (y <= 1582) return y > 0 ? (y % 4 == 0) : (y % 4 == -1);
    else return y % 400 == 0 || (y % 4 == 0 && y % 100); 
}

int getDays(int x, int y) {
    if (y && x == 2) return 29;
    else return days[x]; 
}

void init() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int d = 1, m = 1, y = -4713;
    for (int i = 0; i <= G; i++) {
        D[i] = d, M[i] = m, Y[i] = y;
        if (d == 4 && m == 10 && y == 1582) d = 15;
        else if (d == getDays(m, isLeap(y))) {
            d = 1;
            if (m == 12) {
                m = 1, y ++;
                if (y == 0) y++;
            } else m++;
        } else d++;
    }
}   

void out(int d, int m, int y) {
    if (y < 0) cout << d << " " << m << " " << -y << " BC\n";
    else cout << d << " " << m << " " << y << "\n";
}

int main() {
    init();
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        ll query;
        cin >> query;
        
        if (query <= A) out(D[query], M[query], Y[query]);
        else {
            int a = A + ((query - A) % T);
            out(D[a], M[a], Y[a] + (query - A) / T * 400);
        }
    }
    return 0;
}