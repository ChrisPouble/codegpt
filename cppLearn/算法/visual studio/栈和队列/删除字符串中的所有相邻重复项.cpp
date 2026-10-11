#include <iostream>
#include <stack>
using namespace std;

string isSame(string s)
{
    string str;
    for (int i = 0; i < s.size(); i++)
    {
        if (str.empty() || s[i] != str.back()) str.push_back(s[i]);
        else str.pop_back();
    }

    return str;
}

//int main()
//{
//    string s = "abbaca";
//    string ret = isSame(s);
//
//    cout << "ret = " << ret << endl;
//    system("pause");
//    return 0;
//}