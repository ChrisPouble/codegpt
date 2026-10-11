#include <iostream>
#include <algorithm>
using namespace std;

struct Person
{
    int id;
    int chinese;
    int total;
}a[305];

bool p1093(Person a, Person b)
{
    if (a.total != b.total) return a.total > b.total;
    if (a.chinese != b.chinese) return a.chinese > b.chinese;
    return a.id < b.id;
}

//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//    {
//        int ch, ma, en;
//        cin >> ch >> ma >> en;
//        a[i].id = i;
//        a[i].chinese = ch;
//        a[i].total = ch + ma + en;
//    }
//    
//    sort(a + 1, a + n + 1, p1093);
//    for (int i = 1; i <= 5; i++)
//        cout << a[i].id << " " << a[i].total << endl;
//    system("pause");
//    return 0;
//}