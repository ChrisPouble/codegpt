#include <iostream>
using namespace std;

long long a, b, c, cnt;
int num[10];
void go(int x) {
    num[x / 100] = 1;
    num[x / 10 % 10] = 1;
    num[x % 10] = 1;
}

bool check(int x, int y, int z) {
    memset(num, 0, sizeof(num));
    if (y > 999 || z > 999) return false;
    go(x), go(y), go(z);
    for (int i = 1; i <= 9; i++)
        if (!num[i]) return false;
    return true;
}

//int main()
//{
//    cin >> a >> b >> c;
//    if (a == 0) {
//        cout << "No!!!" << endl;
//        return 0;
//    }
//    for (int x = 123; x <= 987; x++)
//    {
//        if (x * b % a || x * c % a) continue;
//        int y = x * b / a, z = x * c / a;
//        if (check(x, y, z)) {
//            cout << x << " " << y << " " << z << endl;
//            cnt++;
//        }
//    }
//    if (!cnt) cout << "No!!!" << endl;
//    system("pause");
//    return 0;
//}