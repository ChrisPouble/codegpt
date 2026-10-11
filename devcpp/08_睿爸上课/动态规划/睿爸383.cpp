#include <bits/stdc++.h>
using namespace std;

char s[2000];
int n, ans, f[1 << 20][30]; //第i种情况以j这个字母结尾的最大长度 
int st[20], ed[20], len[20];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
    	scanf("%s", &s);
    	st[i] = s[0] - 'A';
    	ed[i] = s[strlen(s) - 1] - 'A';
    	len[i] = strlen(s);
	}
    for (int now = 0; now < (1 << n); now++)
    	for (int i = 0; i < n; i++) {
    		if(now & (1 << i)) continue; //如果已经在集合里面了，那就没有枚举的必要了 
    		int go  = now | (1 << i); //把这个字符串加入集合里
    		f[go][ed[i]] = max(f[go][ed[i]], f[now][st[i]] + len[i]); //进行连接 
    		ans = max(ans, f[go][ed[i]]); //找答案 
		}
	cout << ans << endl;
    return 0;
}
