//#include <iostream>
//using namespace std;
//
//char s[100010];
//int n, ans = 1, y = 0;
//struct bw {
//    int black;
//    int white;
//}t[100010];
//
//bool bili(int a, int b, int c, int d) {
//    if (a * d != b * c) return false;
//    return true;
//}
//
//void dg(int x, int len) {
//    if (x == y) {
//        if (len == 1) {
//             ans = max(len, ans);
//             return;
//        }
//        for (int i = 0; i < len; i++) {
//            int fb = t[i].black, fw = t[i].white;
//            int gb = t[i + 1].black, gw = t[i + 1].white;
//            if (!bili(fw, fb, gw, gb)) return;
//        }
//        ans = max(len, ans);
//    }
//    for (int i = 1; i <= y - x; i++) {
//        for (int j = 1; j <= i; j++)
//            if (s[j + x] == '1') t[len].black++;
//            else t[len].white++;
//        dg(x + i, len + 1);
//        t[len].black = t[len].white = 0;
//    }
//}
//
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        int num; char z; cin >> num >> z;
//        for (int j = 0; j < num; j++) {
//            s[y] = z;
//            y++;
//        }
//    }
//    y--;
//    dg(-1, 0);
//    cout << ans << endl;
//    return 0;
//}
///*
//6
//1 1
//4 0
//1 1
//1 0
//1 1
//1 0
//*/