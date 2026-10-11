#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string name;
    int nian;
    int yue;
    int ri;
    int id;
};

student a[105];
bool p1104(student a, student b)
{
    if (a.nian != b.nian) return a.nian < b.nian;
    if (a.yue != b.yue) return a.yue < b.yue;
    if (a.ri != b.ri) return a.ri < b.ri;
    return a.id > b.id;
}

//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        string t;
//        int nian1, yue1, ri1;
//        cin >> t >> nian1 >> yue1 >> ri1;
//        a[i].name = t;
//        a[i].nian = nian1;
//        a[i].yue = yue1;
//        a[i].ri = ri1;
//        a[i].id = i;
//    }
//
//    sort(a, a + n, p1104);
//    for (int i = 0; i < n; i++)
//        cout << a[i].name << endl;
//    system("pause");
//    return 0;
//}