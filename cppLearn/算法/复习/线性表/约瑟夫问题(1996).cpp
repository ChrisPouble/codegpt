#include <iostream>
#include <queue>
#include <list>
using namespace std;

int Next[105];
queue<int>que;
list<int>lis;
//int main() {
//    //方法一 --- 模拟链表
//    //int n, m, i, p = 1, now; cin >> n >> m;
//    //for (i = 1; i < n; i++)
//    //    Next[i] = i + 1;
//    //Next[n] = 1;
//    //now = n;
//    //p = n;
//    //while (--now) {
//    //    for (i = 1; i < m; i++) p = Next[p];
//    //    cout << Next[p] << " ";
//    //    Next[p] = Next[Next[p]];
//    //}
//    //cout << p << endl;
//
//    //方法二 --- STL队列
//    //int n, p; cin >> n >> p;
//    //for (int i = 1; i <= n; i++)
//    //    que.push(i);
//    //while (que.size() != 1) {
//    //    for (int i = 1; i < p; i++) {
//    //        que.push(que.front()); que.pop();
//    //    }
//    //    cout << que.front() << " ";
//    //    que.pop();
//    //}
//    //cout << que.front();
//
//    //方法三 --- STL链表
//    //int n, p, cnt = 0; cin >> n >> p;
//    //for (int i = 1; i <= n; i++)
//    //    lis.push_back(i);
//    //list<int> ::iterator it, now;
//    //it = lis.begin();
//    //while (!lis.empty()) {
//    //    cnt++;
//    //    now = it;
//    //    if(++it == lis.end()) it = lis.begin();
//    //    if (cnt == p) {
//    //        cout << *now << " ";
//    //        lis.erase(now);
//    //        cnt = 0;
//    //    }
//    //}
//    system("pause");
//    return 0;
//}
