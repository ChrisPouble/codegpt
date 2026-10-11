//#include <iostream>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//long long n, m, seed, cnt, temp, a[10000010], t[10000010];
//void generate_array(long long a[], long long n, long long m, long long seed) {
//    unsigned x = seed;
//    for (int i = 0; i < n; ++i) {
//        x ^= x << 13;
//        x ^= x >> 17;
//        x ^= x << 5;
//        a[i] = x % m + 1;
//    }
//}
//
//queue<long long> q;
//int get() {
//    if (q.empty()) return a[cnt++]; //空了就选a[cnt]
//    long long f = q.front();
//    if (cnt == n || a[cnt] > f) {//f小就选f
//        q.pop();
//        return f;
//    }
//    return a[cnt++];//a[cnt]小就选a[cnt]
//}
//
//int main() {
//    cin >> n >> m >> seed;
//    generate_array(a, n, m, seed);
//    for (int i = 0; i < n; i++)
//        t[a[i]]++;
//    for (int i = 0; i < n; i++)
//        a[i] = 0;
//    for (int i = 0; i <= m; i++)
//        while (t[i]--)
//            a[temp++] = i;
//    for (int i = 1; i <= n - 1; i++) {
//        int t1 = get(), t2 = get();
//        q.push(max(t1 * 2, t2));
//    }
//    cout << q.front() << endl;
//    return 0;
//}
///*
//5
//2 3 4 5 6
//8
//*/