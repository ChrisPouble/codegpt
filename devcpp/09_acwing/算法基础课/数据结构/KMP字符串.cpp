#include <bits/stdc++.h>
#define N 1000010
#define M 1000010
using namespace std;

int n, m, ne[N];
char S[M], P[N];
signed main() {
    cin >> n >> (P + 1) >> m >> (S + 1);
    for (int i = 2, j = 0; i <= n; i++) { //i从2开始 
        while(j && P[i] != P[j + 1]) j = ne[j]; //不停地给机会 
        if(P[i] == P[j + 1]) j++; //如果达到机会了，就+1 
        ne[i] = j; //记录 
    }
    for (int i = 1, j = 0; i <= m; i++) {
        while(j && S[i] != P[j + 1]) j = ne[j]; //不停地给机会 
        if(S[i] == P[j + 1]) j++; //达到机会了，指针挪一步 
        if(j == n) cout << i - n << " "; //输出 
    }
	return 0;
}
