#include <bits/stdc++.h>
using namespace std;
#define mod 233333 

int n;
char a[12], b[12];
long long ans;
vector<pair<int, int> >linker[mod + 2];
int gothash(char x[], char y[]) { //获取哈希数 
	return (x[0] - 'A') + (x[1] - 'A') * 26 + (y[0] - 'A') * 26 * 26 + (y[1] - 'A') * 26 * 26 * 26;
}

void insert(int x) { //加入哈希数 
	for (int i = 0; i < linker[x % mod].size(); i++)
		if(linker[x % mod][i].first == x) { //找到了 
			linker[x % mod][i].second++; //x出现的次数++ 
			break;
		}
	linker[x % mod].push_back(pair<int, int>(x, 1)); //把x添加进去 
}

int find(int x) { //查找x 
	for (int i = 0; i < linker[x % mod].size(); i++)
		if(linker[x % mod][i].first == x) return linker[x % mod][i].second; //如果找到了，返回x出现的次数 
	return 0;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		a[2] = 0;
		if(a[0] != b[0] || a[1] != b[1]) ans += find(gothash(a, b)); //如果前面两个字符不相同，就去找它 
		insert(gothash(b, a)); //再顺便加进去 
	}
	cout << ans << endl;
    return 0;
}
