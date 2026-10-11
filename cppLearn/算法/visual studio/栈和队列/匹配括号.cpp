#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    if (s.size() % 2 == 1)
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') st.push(')');
        else if (s[i] == '[') st.push(']');
        else if (s[i] == '{') st.push('}');
        else if (st.empty() || s[i] != st.top()) return false;
        else st.pop();
    }

    if (!st.empty()) return false;
    return true;
}

//int main()
//{
//    string s = "{[()]}";
//    bool ret = isValid(s);
//
//    if (ret)
//    {
//        cout << "ret = true" << endl;
//    }
//    else
//    {
//        cout << "ret = false" << endl;
//    }
//    system("pause");
//    return 0;
//}