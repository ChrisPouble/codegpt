////原版
//#include <iostream>
//using namespace std;
//
//int e, Begin[1005], To[20005], W[20005], Next[20005];
//void add(int u, int v, int w) {
//    e++;
//    To[e] = v;
//    W[e] = w;
//    Next[e] = Begin[u];
//    Begin[u] = e;
//}
//
//int n, m, dis[1005];
//bool vis[1005];
//int main() {
//    int n, m, s, t; cin >> n >> m >> s >> t;
//    for (int i = 1; i <= m; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        add(u, v, w);
//        add(v, u, w);
//    }
//
//    //初始化边界
//    for (int i = 1; i <= n; i++)
//        dis[i] = 2e8;
//    dis[s] = 0;
//
//    //算法过程
//    for (int i = 1; i <= n; i++) {
//        int min_v = 2e8, min_id;
//        for (int j = 1; j <= n; j++)
//            if (!vis[j]) {
//                if (dis[j] < min_v) {
//                    min_v = dis[j];
//                    min_id = j;
//                }
//            }
//        for (int j = Begin[min_id]; j; j = Next[j]) {
//            int y = To[j], z = W[j];
//            if (dis[y] > dis[min_id] + z) dis[y] = dis[min_id] + z;
//        }
//        vis[min_id] = true;
//    }
//    cout << dis[t] << endl;
//    return 0;
//}

//升级版
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1e6 + 10;
long long e, Begin[maxn], To[maxn * 2], W[maxn * 2], Next[maxn * 2];
void add(long long u, long long v, long long w) {
    e++;
    To[e] = v;
    W[e] = w;
    Next[e] = Begin[u];
    Begin[u] = e;
}

long long n, m, dis[maxn];
bool vis[maxn];

struct node{
    long long id, value;
};

bool operator < (node A, node B) {
    if (A.value > B.value) return true;
    return false;
}
priority_queue <node> Q;

int main() {
    long long n, m, s; cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        //add(v, u, w);
    }

    //初始化边界
    for (int i = 1; i <= n; i++)
        dis[i] = 1e10;
    dis[s] = (long long)0;
    node nod; nod.id = s, nod.value = (long long)0;
    Q.push(nod);

    //算法过程
    while(!Q.empty()) {
        node temp = Q.top(); Q.pop();
        long long min_id = temp.id;
        long long val = temp.value;
        if (vis[min_id]) continue;
        vis[min_id] = true;
        dis[min_id] = val;
        for (long long j = Begin[min_id]; j; j = Next[j]) {
            long long y = To[j], z = W[j];
            if (dis[y] > dis[min_id] + z) {
                dis[y] = dis[min_id] + z;
                Q.push({ y, dis[y] });
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (long long)dis[i] << " ";
    return 0;
}
/*
7 9 1 7
1 2 2
1 3 5
2 3 6
2 4 1
2 5 3
4 5 4
3 6 8
5 7 9
6 7 7
*/