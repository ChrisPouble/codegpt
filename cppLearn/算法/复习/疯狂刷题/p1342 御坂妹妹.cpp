//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct shop {
//    int w;
//    string d;
//}W[500001];
//
//bool cmp(shop a, shop b) {
//    return a.w < b.w;
//}
//
//int main() {
//    int a, b, c, m, ans = 0, sum = 0; cin >> a >> b >> c >> m;
//    for (int i = 1; i <= m; i++)
//        cin >> W[i].w >> W[i].d;
//    sort(W + 1, W + m + 1, cmp);
//    for (int i = 1; i <= m; i++) {
//        if (a > 0 && W[i].d == "A") a--, ans++, sum += W[i].w;
//        else if (b > 0 && W[i].d == "B") b--, ans++, sum += W[i].w;
//        else if (c > 0) c--, ans++, sum += W[i].w;
//    }
//    cout << ans << " " << sum << endl;
//    return 0;
//}
///*
//3 4 3
//12
//3 A
//4 B
//3 A
//5 A
//9 B
//2 B
//6 A
//8 B
//4 B
//8 A
//5 B
//7 B
//*/