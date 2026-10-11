#include <iostream>
#include <vector> 
#include <algorithm>
#include <unordered_map>
using namespace std;

class Person
{
public:
    string swal()
    {
        string s = " abcdef";
        for (int i = 0, j = s.size(); i < s.size() / 2; i++, j--)
        {
            //swap(s[i], s[j]);
            int temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};

void test011()
{
    Person p;
    string ret = p.swal();
    cout << "ret = " << ret << endl;
}

//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}