//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n, k[210];
//int ans[210];
//struct node {
//    int id, num, bushu;
//};
//
//queue<node>q;
//int main()
//{
//    int A, B; cin >> n >> A >> B;
//    memset(ans, -1, sizeof(ans));
//    for (int i = 1; i <= n; i++)
//        cin >> k[i];
//    q.push({ A, k[A], 0 });
//    ans[A] = 0;
//    while (!q.empty()) {
//        node t = q.front();
//        q.pop();
//        if (t.id + t.num <= n && ans[t.id + t.num] == -1) {
//            ans[t.id + t.num] = t.bushu + 1;
//            q.push({ t.id + t.num, k[t.id + t.num], t.bushu + 1 });
//        }
//        if (t.id - t.num >= 1 && ans[t.id - t.num] == -1) {
//            ans[t.id - t.num] = t.bushu + 1;
//            q.push({ t.id - t.num, k[t.id - t.num], t.bushu + 1 });
//        }
//    }
//    cout << ans[B] << endl;
//    system("pause");
//    return 0;
//}