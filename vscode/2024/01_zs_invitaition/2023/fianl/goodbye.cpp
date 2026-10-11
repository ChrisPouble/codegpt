//#include <bits/stdc++.h>
//using namespace std;
//
//int ans = 0;
//string st;
//bool huiwen(string s) {
//	for (int i = 0; i < s.size() / 2; i++)
//		if(s[i] != s[s.size() - i - 1]) return false;
//	return true;
//}
//
//void dg(int x, string s) {
//	if(x == st.size()) {
//		int size = s.size();
//		if(huiwen(s)) ans = max(ans, size);
//		return;
//	}
//	string t = s;
//	t += st[x];
//	dg(x + 1, t);
//	dg(x + 1, s);
//}
//
//int main() {
//	int n; cin >> n;
//	cin >> st;
//	dg(0, "");
//	cout << ans << endl;
//	return 0; 
//}
///*
//7
//acbdcaa
//*/
#include <bits/stdc++.h>
using namespace std;

int ans = 0;
string st;
bool huiwen(string s) {
	for (int i = 0; i < s.size() / 2; i++)
		if(s[i] != s[s.size() - i - 1]) return false;
	return true;
}

bool vis = false;
int dg(int l, int r) {
	if(l == r) return 1;
	if(l > r) return 0;
	int ans = 0;
	if(st[l] == st[r]) {
		ans += 2;
		ans += dg(l + 1, r - 1);
	} else {
		ans += max(dg(l + 1, r), dg(l, r - 1));
	}
	return ans;
}

int main() {
	int n; cin >> n;
	cin >> st;
	int ans = dg(0, n - 1);
	cout << ans << endl;
	return 0;
}
/*
7
acbdcaa
*/
