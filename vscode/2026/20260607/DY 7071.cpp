#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int N = 1e3 + 10;

ull n, k, dis[N][N];
ull t1, t2, t3, t4, t5, Limit, ans;
ull rng() {
	t1 = (t2 ^ t3) + t4 * t5;
	t2 = (t3 ^ t4) + t5 * t1;
	t3 = (t4 ^ t5) + t1 * t2;
	t4 = (t5 ^ t1) + t2 * t3;
	t5 = (t1 ^ t2) + t3 * t4;
	return t1 * t2 + (t3 ^ t4) * t5;
}

//void solve() {
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			dis[i][j] = i ^ j;
//	
//	for (int k = 1; k <= n; k++)
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
//	
//	for (int i = 1; i <= n; i++) {
//		ull res = 0;
//		for (int j = 1; j <= n; j++)
//			res ^= dis[i][j], cout << dis[i][j] << " ";
//		cout << "--- res = " << res << "\n";
//	}
//	
//	cout << "-----------------\n";
//	
//	for (int i = 1; i <= n; i++, puts(""))
//		for (int j = 1; j <= n; j++)
//			cout << (i ^ j) << " ";
//}

ull solve() {
	__int128 ppt = 1;
	__int128 ans = 0;
	
	ull p = ((n & 1) * k);
	if (n % 4 == 0) return n ^ p;
	if (n % 4 == 1) return 1 ^ p;
	if (n % 4 == 2) return (n + 1) ^ p;
	if (n % 4 == 3) return 0 ^ p;
} 

int main() {
//	n = 5, k = 2;
//	ull ans = solve();
	
//	for (int i = 1; i <= 200; i++)
//		n = i, k = 0, cout << i << ":" << solve() << "\n";

    int T; cin >> T; 
    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> Limit;
    
    for (int i = 1; i <= T; i++) {
    	n = rng() % Limit + 1, k = rng() % n + 1; 
//    	cout << n << " " << k << " ";
		ull cnt = solve(); 
//		cout << cnt << "\n";
		ans ^= cnt * i; // 注意此处可能会产生自然溢出（自动 mod 2^64）。
    }
    
    printf("%llu",ans);
    return 0;
}