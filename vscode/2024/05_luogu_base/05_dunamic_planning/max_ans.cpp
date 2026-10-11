#include <bits/stdc++.h>
using namespace std;

int n, a[10010], f[10010];

int dp(int num[], int size){
    if(size == 0) return a[0];
    if(size == 1) return max(a[0], a[1]);
    return max(dp(num, size - 1), dp(num, size - 2) + a[size]);
}

int iterate(int f[],int n){
    // 1.initialize(初始化)
    f[1] = a[1];
    f[2] = max(a[1], a[2]);
    for (int i = 3; i <= n; i++) {
        if(a[i] + f[i - 2] > f[i - 1]) 
        f[i] = a[i] + f[i - 2];
        else f[i] = f[i - 1];
    }
    return f[n];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    int result = dp(a, n - 1);

    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];
    // int result = iterate(a, n);
    cout << result << endl;
    
    return 0;
}