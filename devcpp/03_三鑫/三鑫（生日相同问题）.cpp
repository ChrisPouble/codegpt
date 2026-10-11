#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct stu{
	string name;
	int yue, ri;
}a[200];

bool is(string x, string y) {
	for (int i = 0; i < x.size(); i++)
		if(x[i] < y[i]) return true;
		else if(x[i] > y[i]) return false;
}

bool cmp(stu x, stu y) {
	if(x.yue != y.yue) {
		if(x.yue < y.yue) return true;
		else return false;
	}
	if(x.ri != y.ri) {
		if(x.ri < y.ri) return true;
		else return false;
	}
	if(x.name.size() != y.name.size()) {
		if(x.name.size() < y.name.size()) return true;
		else return false;
	}
	return is(x.name, y.name);
}

int main() {
//	freopen("birthday.in", "r", stdin);
//	freopen("birthday.out", "w", stdout);
	int n; cin >> n;
	if(n == 1) {
		cout << "None" << endl;
		return 0;
	}
	bool is_cout = false, fir;
	for (int i = 1; i <= n; i++)
		cin >> a[i].name >> a[i].yue >> a[i].ri;
	sort(a + 1, a + n + 1, cmp);
	if(a[1].yue == a[1 + 1].yue && a[1].ri == a[1 + 1].ri) {
		cout << a[1].yue << " " << a[1].ri << " " << a[1].name << " ";
		fir = true;
	}
	for (int i = 2; i <= n; i++) {
		if(a[i].yue == a[i - 1].yue && a[i].ri == a[i - 1].ri) {
			cout << a[i].name << " ";
			is_cout = true;
			continue;
		}
		if(i != n) {
			if(a[i].yue == a[i + 1].yue && a[i].ri == a[i + 1].ri) {
				if(fir == true) cout << "\n" << a[i].yue << " " << a[i].ri << " " << a[i].name << " ";
				else {
					fir = true;
					cout << a[i].yue << " " << a[i].ri << " " << a[i].name << " ";
				}
			}
		}
	}
	if(is_cout == false) cout << "None" << endl;
	else cout << endl;
	return 0;
}
