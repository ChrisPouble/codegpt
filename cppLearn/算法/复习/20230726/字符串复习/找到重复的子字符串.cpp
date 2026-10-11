#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool issame(string s)
{
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 1; j < s.size() - i + 1; j++)
        {
            string temp = s.substr(i, j);
            if (map.find(temp) != map.end())
            {
                return true;
            }
            map.insert(pair<string, vector<int>>(temp, {i, i + j}));
        }
    }
    return false;
}

//int main()
//{
//    string s = "abcedd";
//    bool ret = issame(s);
//
//    if (ret)
//    {
//        cout << "ret = true"<< endl;
//    }
//    else
//    {
//        cout << "ret = false" << endl;
//    }
//    system("pause");
//    return 0;
//}