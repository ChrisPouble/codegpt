#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[110], n5;
int* p1059()
{
    bool ok;
    for (int i = 0; i < n5 - 1; i++) {
        ok = true;
        for (int j = 0; j < n5 - i - 1; j++)
            if (a[j + 1] < a[j]) {
                swap(a[j + 1], a[j]);
                ok = false;
            }
        if (ok) return a;
    }
    return a;
}

//int main()
//{
//    cin >> n5;
//    for (int i = 0; i < n5; i++)
//        cin >> a[i];
//    p1059();
//    int cnt = unique(a, a + n5) - a;
//    cout << cnt << endl;
//    for (int i = 0; i < cnt; i++)
//        cout << a[i] << " ";
//    cout << endl;
//    return 0;
//}