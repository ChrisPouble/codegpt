#include<bits/stdc++.h>
#define mod 23333
using namespace std;

int T, n;
vector<int> linker[50010];
long long a[50010];
bool check(int x) {
	int pos = (x % mod + mod) % mod;
	for (int i = 0; i < linker[pos].size(); i++)
		if(linker[pos][i] == x) return true;
	linker[pos].push_back(x);
	return false;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		for (int i = 0; i < 50005; i++) linker[i].clear();
		cin >> n;
		for (int i = 0; i < n; i++)
			linker[i].clear();
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			if(!check(a[i])) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
