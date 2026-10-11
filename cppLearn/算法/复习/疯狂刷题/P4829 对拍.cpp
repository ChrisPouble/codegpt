//#include <iostream>
//#include <queue>
//using namespace std;
//
//long long n, m, seed, a[10000010], t[10000010];
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
//class qq {
//public:
//    long long x;
//};
//
//bool operator<(qq A, qq B) {
//    return A.x > B.x;
//}
//
//priority_queue<qq> q;
//int main() {
//    cin >> n >> m >> seed;
//    generate_array(a, n, m, seed);
//    //for (int i = 0; i < n; i++)
//    //    t[a[i]]++;
//    //for (int i = 0; i < n; i++)
//    //    while (t[i]--)
//    //        q.push(i);
//    for (int i = 0; i < n; i++) {
//        qq temp;
//        temp.x = a[i];
//        q.push(temp);
//    }
//    for (int i = 1; i < n; i++) {
//        long long temp1 = q.top().x; q.pop();
//        long long temp2 = q.top().x; q.pop();
//        if (temp2 < temp1) swap(temp1, temp2);
//        if (temp2 > 2 * temp1) {
//            qq temp;
//            temp.x = temp2;
//            q.push(temp);
//        }
//        else {
//            qq temp;
//            temp.x = temp1 * 2;
//            q.push(temp);
//        }
//    }
//    cout << q.top().x << endl;
//    return 0;
//}
///*
//5
//2 3 4 5 6
//8
//*/