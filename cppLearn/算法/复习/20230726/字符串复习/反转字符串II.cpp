#include <iostream>
#include <vector>
using namespace std;

vector<char> reverseString(vector<char>&s, int k)
{
    for (int i = 0; i < s.size(); i += 2 * k)
    {
        if (i + k <= s.size())
        {
            reverse(s.begin() + i, s.begin() + i + k);
            continue;
        }

        reverse(s.begin() + i, s.begin() + s.size());
    }

    return s;
}

//int main()
//{
//    int k = 3;
//
//    vector<char>s;
//    s.push_back('a');
//    s.push_back('s');
//    s.push_back('d');
//    s.push_back('f');
//    s.push_back('g');
//    s.push_back('h');
//    s.push_back('j');
//    s.push_back('k');
//    s.push_back('l');
//
//    vector<char>ret = reverseString(s, k);
//    cout << "ret = ";
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i];
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}