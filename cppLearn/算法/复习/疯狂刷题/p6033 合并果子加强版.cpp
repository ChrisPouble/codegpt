//#include <iostream>
//#include <queue>
//using namespace std;
//
//class LongLong {
//public:
//    long long x;
//};
//
//bool operator<(LongLong a, LongLong b) {
//    return a.x > b.x;
//}
//
//int main() {
//    priority_queue<LongLong> q;
//    int n; long long sum = 0; cin >> n;
//    for (int i = 1; i <= n; i++) {
//        long long temp; cin >> temp;
//        LongLong x; x.x = temp;
//        q.push(x);
//    }
//    while (q.size() > 1) {
//        LongLong temp1 = q.top(); q.pop();
//        LongLong temp2 = q.top(); q.pop();
//        sum += temp1.x + temp2.x; LongLong x; x.x = temp1.x + temp2.x;
//        q.push(x);
//    }
//    cout << sum << endl;
//    return 0;
//}