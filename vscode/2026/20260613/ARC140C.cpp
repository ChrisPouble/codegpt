#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read() {
    ll res = 0, f = 1;
    char c;
    for (; (c = getchar()) < '0' || c > '9'; c == '-' ? f = -f : 0);
    while (c >= '0' && c <= '9') {
        res = (res << 1) + (res << 3) + (c - '0');
        c = getchar();
    }
    return res * f;
}

const int N = 2e5 + 10;
int n, x, a[N];

int main() {
    n = read();
    x = read();
    a[1] = x;

    if (n & 1) {
        int mid = (n + 1) / 2;
        
        if (mid == x) {
            for (int i = x - 1, j = 2; i > 0; i--, j += 2) a[j] = i;
            for (int i = x + 1, j = 3; i <= n; i++, j += 2) a[j] = i;
        } else if (x < mid) {
            a[2] = mid;
            for (int i = a[2] + 1, j = 3; i <= n; i++, j += 2) a[j] = i;
            for (int i = a[2] - 1, j = 4; i > 0; i--, j += 2) {
                if (i == x) i--;
                if (i > 0) a[j] = i;
                else break;
            }
        } else if (x > mid) {
            a[2] = mid;
            for (int i = a[2] - 1, j = 3; i > 0; i--, j += 2) a[j] = i;
            for (int i = a[2] + 1, j = 4; i <= n; i++, j += 2) {
                if (i == x) i++;
                if (i <= n) a[j] = i;
            }
        }
    } else {
        int mid_left = n / 2;
        int mid_right = n / 2 + 1;

        if (mid_left == x) {
            for (int i = x + 1, j = 2; i <= n; i++, j += 2) a[j] = i;
            for (int i = x - 1, j = 3; i > 0; i--, j += 2) a[j] = i;
        } 
        else if (mid_right == x) {
            for (int i = x - 1, j = 2; i > 0; i--, j += 2) a[j] = i;
            for (int i = x + 1, j = 3; i <= n; i++, j += 2) a[j] = i;
        } 
        else if (x < mid_left) {
            a[2] = mid_right;
            for (int i = a[2] - 1, j = 3; i > 0; i--, j += 2) {
                if (i == x) i--;
                if (i > 0) a[j] = i;
                else break;
            }
            for (int i = a[2] + 1, j = 4; i <= n; i++, j += 2) a[j] = i;
        } 
        else {
            a[2] = mid_left;
            for (int i = a[2] + 1, j = 3; i <= n; i++, j += 2) {
                if (i == x) i++;
                if (i <= n) a[j] = i;
            }
            for (int i = a[2] - 1, j = 4; i > 0; i--, j += 2) a[j] = i;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}