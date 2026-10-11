#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, ans, a[100010], has[100010];
void insert(int x) {
	has[++cnt] = x;
    int k = cnt;
    while(k > 1 && has[k] < has[k / 2]) {
    	swap(has[k], has[k / 2]);
    	k /= 2;
	}
}

void pop() {
    has[1] = has[cnt--];
	int k = 1;
	while(k * 2 <= cnt) {
		if(k * 2 + 1 <= cnt && has[k * 2] < has[k * 2 + 1]) k = k * 2;
		else if(k * 2 + 1 <= cnt && has[k * 2] >= has[k * 2 + 1]) k = k * 2 + 1;
		else if(k * 2 <= cnt && k * 2 + 1 > cnt) k = k * 2;
		else return;
		if(has[k / 2] <= has[k]) return ;
		else swap(has[k], has[k / 2]);
	}
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], insert(a[i]);
    for (int i = 1; i <= m; i++) cout << has[1] << " ", pop();
    return 0;
}
