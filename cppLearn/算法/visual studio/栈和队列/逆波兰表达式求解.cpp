#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int evalPPN(vector<char>& s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            int num1 = st.top(); st.pop();
            int num2 = st.top(); st.pop();
            
            if (s[i] == '+') st.push(num1 + num2);
            if (s[i] == '-') st.push(num1 - num2);
            if (s[i] == '*') st.push(num1 * num2);
            if (s[i] == '/') st.push(num1 / num2);
        }
        else 
        {
            int ret = s[i] - 48;
            st.push(ret); 
        }
    }

    int result = st.top();
    st.pop();
    return result;
}

//int main()
//{
//    vector<char> s;
//    s.push_back('1'); 
//    s.push_back('2');
//    s.push_back('+');
//    s.push_back('3');
//    s.push_back('4');
//    s.push_back('+');
//    s.push_back('*');
//    int ret = evalPPN(s);
//
//    cout << "ret = " << ret << endl;
//    system("pause");
//    return 0;
//}