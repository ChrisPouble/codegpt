//#include <iostream>
//#include <map>
//using namespace std;
//
//int n, ans = 1;
//string s;
//struct zb {
//    int x, y;
//};
//
//map<zb, bool>m;
//bool operator==(zb x, zb y) {
//    return x.x == y.x && x.y == y.y;
//}
//
//int main() {
//    cin >> n;
//    cin >> s;
//    int nowx = 0, nowy = 0;
//    zb temp; temp.x = 0, temp.y = 0;
//    m.insert(pair<zb, bool>(temp, true));
//    for (int i = 1; i <= n; i++) {
//        if (s[i - 1] == 'U') {
//            nowy++;
//            temp.x = nowx, temp.y = nowy;
//            map<zb, bool>::iterator pos = m.find(temp);
//            if (pos != m.end()) {
//                if ((*pos).second == true) {
//                    ans++;
//                    (*pos).second = false;
//                }
//            }
//            else m.insert(pair<zb, bool>(temp, true));
//        }
//        else if (s[i - 1] == 'D') {
//            nowy--;
//            temp.x = nowx, temp.y = nowy;
//            map<zb, bool>::iterator pos = m.find(temp);
//            if (pos != m.end()) {
//                if ((*pos).second == true) {
//                    ans++;
//                    (*pos).second = false;
//                }
//            }
//            else m.insert(pair<zb, bool>(temp, true));
//        }
//        else if (s[i - 1] == 'L') {
//            nowx--;
//            temp.x = nowx, temp.y = nowy;
//            map<zb, bool>::iterator pos = m.find(temp);
//            if (pos != m.end()) {
//                if ((*pos).second == true) {
//                    ans++;
//                    (*pos).second = false;
//                }
//            }
//            else m.insert(pair<zb, bool>(temp, true));
//        }
//        else {
//            nowx++;
//            temp.x = nowx, temp.y = nowy;
//            map<zb, bool>::iterator pos = m.find(temp);
//            if (pos != m.end()) {
//                if ((*pos).second == true) {
//                    ans++;
//                    (*pos).second = false;
//                }
//            }
//            else m.insert(pair<zb, bool>(temp, true));
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}
///*
//5
//UDUDU
//*/