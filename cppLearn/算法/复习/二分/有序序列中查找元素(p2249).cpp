#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int n, m, a[1000010];
int erfen(int x) {
    int l = 1, r = n;
    while (l < r) { //最后l和r会相等
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) r = mid;
        else l = mid + 1;
    }
    if (a[l] == x) return l;
    else return -1;
}

int baoli(int x) {
    for (int i = 1; i <= n; i++)
        if (a[i] == x) return i;
    return -1;
}

void duipai() {
    srand((unsigned int)time(NULL));
    n = rand() % 80000 + 1;
    m = rand() % n + 1;
    for (int i = 1; i <= n; i++)
        a[i] = rand() % 100000000 + 1;
    for (int i = 1; i <= m; i++) {
        int q = rand() % 100000000 + 1;
        int t1 = erfen(q);
        int t2 = baoli(q);
        if (t1 != t2) {
            cout << "输入代码：" << endl;
            cout << n << " " << m << endl;
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << endl;
            cout << q << endl;
            cout << "错误答案：" << t1 << endl;
            cout << "正确答案：" << t2 << endl;
            exit(0);
        }
    }
}

//int main() {
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//    for (int i = 1; i <= m; i++) {
//        int q; cin >> q;
//        cout << erfen(q) << " ";
//    }
//    //while(1) duipai();
//    return 0;
//}