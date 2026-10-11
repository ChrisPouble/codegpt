#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
const double M = 2e7;

int n;

struct Point {
    int id;
    ll x, y;
} pts[N];

ll S;
bool cmp(Point x, Point y) {
    if (x.x / S != y.x / S) return x.x / S < y.x / S;
        
    if ((x.x / S) % 2 == 0) return x.y < y.y;
    else return x.y > y.y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].id = i;
    }

    S = max(1LL, (long long)round(M / sqrt(n)));

    sort(pts + 1, pts + n + 1, cmp);

    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (pts[i].id == 1) {
            start = i;
            break;
        }
    }
	
    for (int i = 0; i < n; i++) {
        int idx = (start + i - 1) % n + 1;
        cout << pts[idx].id << " ";
    }
    
    return 0;
}
