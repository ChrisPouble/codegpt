#include <bits/stdc++.h>
using namespace std;

int n;
struct student{
	string name;
	string xb;
	int nian;
	int yue;
}a[110];

bool cmt(student a, student b) {
	int ta = a.nian * 100 + a.yue;
	int tb = b.nian * 100 + b.yue;
	return ta > tb;
}

int main() {
//	freopen("agesort.in", "r", stdin);
//	freopen("agesort.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	    cin >> a[i].name >> a[i].xb >> a[i].nian >> a[i].yue;
	sort(a + 1, a + n + 1, cmt);
	for (int i = 1; i <= n; i++)
	    cout << a[i].name << " " << a[i].xb << " " << a[i].nian << " " << a[i].yue << endl;
	return 0;
}
