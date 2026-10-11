#include <bits/stdc++.h>
using namespace std;

int n, k, sum, ans = 1, a[510], mod[510];
bool check(int x) {
	for (int i = 1; i <= n; i++)
		mod[i] = a[i] % x; //把余数都记下来 
	sort(mod + 1, mod + n + 1);
	int l = 1, r = n;
	long long pts = 0;
	while(l <= r) {
		while(mod[l] % x == 0 && l <= r) l++; //%x的原因是怕mod[i]超过x 
		while(mod[r] % x == 0 && l <= r) r--; //同上 
		long long t = min(mod[l] % x, x - (mod[r] % x)); //找出哪个才能加上去 
		mod[l] -= t, mod[r] += t, pts += t; //进行记录 
	}
	return pts <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
		sum += a[i]; //算出总和 
    }
    for (int i = sqrt(sum); i; i--) {
    	if(sum % i) continue; //如果i不能整除sum，则下一个 
    	if(check(i)) ans = max(ans, i); //找出最大值 
    	if(check(sum / i)) ans = max(ans, sum / i); //同理 
    }
    cout << ans << endl;
    return 0;
}
