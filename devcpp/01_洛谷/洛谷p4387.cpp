#include<bits/stdc++.h>
using namespace std;

int a[100010], b[100010];
int main() {
	int T; cin >> T;
	while(T--) {
		stack<int>st;
		int n, zb = 1; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 1; i <= n; i++) {
			st.push(a[i]);
			while(st.top() == b[zb]) { //注意这里是while，不是if 
				st.pop(), zb++;
				if(st.empty()) break;
			}
		}
		if(st.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
