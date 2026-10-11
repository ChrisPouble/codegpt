#include <bits/stdc++.h>
using namespace std;

int n, k, ans, a[5000010];
bool prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

void dfs(int x, int s, int sum) {
	if(s == k) {
		if(prime(sum)) ans++;
		return;
	}
	if(x > n) return;
	dfs(x + 1, s + 1, a[x] + sum);
	dfs(x + 1, s, sum);
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans << endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int n, a[25];
int cnt(int x) //计算x里含有多少个1
{
    int temp = 0;
    while (x) {
        temp += x % 2;
        x /= 2;
    }
    return temp;
}

bool check(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int i, x, k, ans = 0;
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int s = (1 << n) - 1;
    for (int i = 0; i <= s; i++) {
        if (cnt(i) == k) { //如果个数达到了k个
            int sum = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j)) sum += a[j];//判断a[j]是否在i集合里，如果是，就加上a[j]
            if (check(sum)) ans++; //判断是否为质数
        }
    }
    cout << ans << endl;
    return 0;
}
*/
