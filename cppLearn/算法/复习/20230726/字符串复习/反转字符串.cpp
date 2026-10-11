#include <iostream>
#include <vector>
using namespace std;

vector<char> reverseString(vector<char>& s)
{
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
    {
        swap(s[i], s[j]);
    }
    return s;
}

//int main()
//{
//    vector<char>s;
//    s.push_back('a');
//    s.push_back('s');
//    s.push_back('d');
//    s.push_back('f');
//    s.push_back('g');
//
//    vector<char>ret = reverseString(s);
//    cout << "ret = ";
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i];
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}