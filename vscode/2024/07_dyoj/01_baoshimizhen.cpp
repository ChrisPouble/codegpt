#include <bits/stdc++.h>
using namespace std;

struct node{
	int x, y, id,tmp;
}a[100010];

int h, w, xx = 1, yy = 1, n;
bool cmp1(node x, node y) {
	return x.x < y.x;
}

bool cmp2(node x, node y) {
	return x.y < y.y;
}

bool cmp3(node x, node y) {
	return x.id < y.id;
}

int main() {
	cin >> h >> w >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1, cnt = 1; i <= n; i++){
		a[i].x = cnt;
		if(a[i].x != a[i + 1].x)cnt++;
	}
	sort(a + 1, a + n + 1, cmp2);
	for (int i = 1, cnt = 1; i <= n; i++) {
		a[i].y = cnt;
		if(a[i].y != a[i + 1].y) cnt++;
	}
	sort(a + 1, a + n + 1, cmp3);
	for (int i = 1; i <= n; i++)
		cout << a[i].x << " " << a[i].y << endl;
	return 0;
}