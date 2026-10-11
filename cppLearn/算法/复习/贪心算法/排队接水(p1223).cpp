#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct water {
    int time, id;
};

water p[1010];
bool p1223(water a, water b) {
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;
}

//int main() {
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> p[i].time;
//        p[i].id = i + 1;
//    }
//
//    sort(p, p + n, p1223);
//    for (int i = 0; i < n; i++)
//        cout << p[i].id << " ";
//    cout << endl;
//
//    double sum = p[0].time, ans = 0.0;
//    for (int i = 1; i < n; i++) {
//        ans += sum;
//        sum += p[i].time;
//    }
//
//    printf("%.2f", ans);
//    system("pause");
//    return 0;
//}