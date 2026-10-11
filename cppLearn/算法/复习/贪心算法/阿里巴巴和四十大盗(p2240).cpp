#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct three {
    double w;
    double v;
    double p;
};

three s[1000005];
bool cmp(three a, three b) {
    return a.p > b.p;
}

//int main() {
//    int n = 4, m = 50;
//    cin >> n >> m;
//
//    for (int i = 0; i < n; i++) {
//        cin >> s[i].w;
//        cin >> s[i].v;
//        s[i].p = s[i].v / s[i].w;
//    }
//
//    double sum = 0.0;
//    sort(s, s + n, cmp);
//    for (int i = 0; i < n; i++) {
//        if (m > s[i].w) {
//            m -= s[i].w;
//            sum += s[i].v;
//        } else {
//            sum += m* s[i].p;
//            break;
//        }
//    }
//
//    printf("%.2f", sum);
//    cout << endl;
//    system("pause");
//    return 0;
//}