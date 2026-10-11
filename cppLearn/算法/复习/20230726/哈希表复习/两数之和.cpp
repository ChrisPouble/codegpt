#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twosum1(vector<int>& num, int target)
{
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            if (num[i] + num[j] == target)
            {
                return { i, j };
            }
        }
    }
    return {};
}

vector<int> twosum2(vector<int>& num, int target)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < num.size(); i++)
    {
        auto iter = map.find(target - num[i]);
        if (iter != map.end())
        {
            return { iter->second, i };
        }
        map.insert(pair<int, int>(num[i], i));
    }
    return {};
}

//int main()
//{
//    int target = 9;
//
//    vector<int>num;
//    num.push_back(2);
//    num.push_back(7);
//    num.push_back(11);
//    num.push_back(15);
//
//    vector<int>ret = twosum2(num, target);
//    cout << ret[0] << " " << ret[1] << endl;
//    system("pause");
//    return 0;
//}