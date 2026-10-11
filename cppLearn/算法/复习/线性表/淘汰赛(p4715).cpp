#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct qq {
    int li, id;
};

int n, a[10], id[260];
queue<qq> que;
//int main() {
//    //int i, m = 1; cin >> n;
//    //for (i = 1; i <= n; i++)
//    //    m *= 2;
//
//    //for (i = 1; i <= m; i++) {
//    //    cin >> a[i];
//    //    id[i] = i;
//    //}
//
//    //int temp = m, st = 1, ed = m, tot = m;
//    //while (temp > 2) {
//    //    for (i = st; i <= ed; i += 2)
//    //        if (a[id[i]] > a[id[i + 1]])
//    //            id[++tot] = id[i];
//    //        else id[++tot] = id[i + 1];
//    //    st = ed + 1;
//    //    ed = tot;
//    //    temp /= 2;
//    //}
//    //if (a[id[st]] > a[id[ed]]) cout << id[ed];
//    //else cout << id[st];
// 
//    int m = 1; cin >> n;
//    for (int i = 1; i <= n; i++)
//        m *= 2;
//
//    for (int i = 1; i <= m; i++) {
//        cin >> a[i];
//        que.push({a[i], i});
//    }
//
//    while (que.size() > 2) {
//        qq t1 = que.front(); que.pop();
//        qq t2 = que.front(); que.pop();
//        if (t1.li > t2.li) que.push(t1);
//        else que.push(t2);
//    }
//    qq t1 = que.front(); que.pop();
//    qq t2 = que.front(); que.pop();
//    if (t1.li > t2.li) cout << t2.id;
//    else cout << t1.id;
//    system("pause");
//    return 0;
//} 