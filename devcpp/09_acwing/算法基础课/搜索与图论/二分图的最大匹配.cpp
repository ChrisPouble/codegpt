#include <bits/stdc++.h>
#define maxn 510
using namespace std;

bool vis[maxn]; //vis标记是否在递归过程中出现过，相当于临时预定 
int match[maxn];
int ans, n1, n2, m;
vector<int>linker[maxn];
void add(int a, int b) {
    linker[a].push_back(b); //还是我们最熟悉的邻接表加边
}

bool dfs(int x) {
    for (auto v:linker[x]) { //遍历每个想跟自己坐同桌的女生 
        if (!vis[v]) { //如果还没有被预定 
            vis[v] = 1; //定下这个同桌（不管能不能拿下，反正只要标记找过了就行） 
            if (!match[v] || dfs(match[v])) { //如果还没有同桌，或者说可以让对应的男生让出来 
                match[v] = x; //定下这个同桌 
                return 1; //表示自己能找到同桌 
            }
        }
    }
    return 0; //OK，可以跟垃圾桶做同桌了。 
}

int main(){
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 1, a, b; i <= m; i++) scanf("%d%d", &a, &b), add(a, b); //加入一条关系边 
    for (int i = 1; i <= n1; i++) {
        memset(vis, 0, sizeof(vis));
        /*
		每次清空vis的原因很简单，感受一下这个样例：
		2 2 3
		1 1
		1 2
		2 1
		其中，男1与女1在第一轮匹配中很成功地成为了同桌。而男2想与女1做同桌。
		如果不清空，那么本来可以成功的男2（让男1找女2，自己找女1）就只能没有同桌了
		还有就是因为每次匹配的过程不一样 
		*/
        if(dfs(i)) ans++; //能够匹配上，ans+1 
    }
    printf("%d", ans);
    return 0;
}
