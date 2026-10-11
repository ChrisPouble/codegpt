#include <bits/stdc++.h>
using namespace std;

struct lis{
	int pre, nex, key;
	void csh(int _pre, int _nex, int _key) {
		pre = _pre;
		nex = _nex;
		key = _key;
	}
};

struct day{
	int val, id;
}a[32770]; 

bool cmp(day x, day y) {
	if(x.val != y.val) return x.val < y.val;
	return x.id < y.id;
}

lis s[32770];
int n, ans, tot, Hsah[32770], r[32770];
void right(int x, int y) { //将x插入到y右边 
	int k = Hsah[y];
	s[++tot].csh(k, s[k].nex, x);
	s[s[k].nex].pre = tot;
	s[k].nex = tot;
	Hsah[x] = tot;
}

void del(int x) {
	int k = Hsah[x];
	if(k == 0) return; //已经被删除了就return 
	s[s[k].pre].nex = s[k].nex;
	s[s[k].nex].pre = s[k].pre;
	Hsah[x] = 0; //归零 
}

int main() {
	cin >> n;
	s[0].csh(0, 0, 0);
	right(1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		r[i] = a[i].val; 
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i < n; i++)
		right(a[i].id, a[i + 1].id);
	for (int i = 1; i <= n; i++)
		cout << a[i].val << " ";
		cout << endl;
	for (int i = n; i >= 1; i--) {
		if(i == 1) ans += r[i];
		else {
			int x = Hsah[i];
			ans += r[s[x].pre];
			del(i);
		}
	}
	cout << ans << endl;
	return 0;
} 
