#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, d, v[N], a[N];
long long ans = 0, s = 0; //s表示当前还有多少路没有走
int ceil(int x, int y) {
	if(x % y >= 1) return x / y + 1;
	return x / y;
}

int main() {
    cin >> n >> d;
    for (int i = 1; i < n; i++)
		cin >> v[i];
    int mint = N; //找到前面花费最小的加油站 
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	s += v[i]; //路程增加 
    	mint = min(mint, a[i]); //寻找当前最便宜的加油站 
    	if(s > 0) { //如果大于0，就证明还有路没有走完 
    		ans += ceil(s, d) * mint; //更新ans 
    		s -= ceil(s, d) * d; //更新路程 
		}
	}
	cout << ans << endl;
    return 0;
}
