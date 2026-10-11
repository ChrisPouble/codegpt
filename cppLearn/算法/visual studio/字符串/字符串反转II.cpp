#include <iostream>
#include <vector> 
#include <algorithm>
#include <unordered_map>
using namespace std;

string rever(string s, int star, int end)
{
    for (int i = star, j = end; i < (end + star) / 2; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

class Person
{
public:
    string swal(int k)
    {
        string s = "asdfghjk";
        int count = 0;
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            if (i + k <= s.size())
            {
                //reverse(s.begin() + i, s.begin() + i + k);
                s = rever(s, i, i + k - 1);
                continue;
            }
            //reverse(s.begin() + i, s.begin() + s.size());
            s = rever(s, i, s.size() - 1);
        }
        return s;
    }
};

void test012()
{
    Person p;
    int k = 3;
    string s = p.swal(k);

    cout << "s = " << s << endl;
}

//int main()
//{
//    test012();
//    system("pause");
//    return 0;
//}