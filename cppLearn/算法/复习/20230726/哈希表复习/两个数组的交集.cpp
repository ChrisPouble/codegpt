#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector<int> intersection(vector<int>& num1, vector<int>& num2)
{
    unordered_set<int> result;
    unordered_set<int> nums_set(num1.begin(), num1.end());

    for (int i = 0; i < num2.size(); i++)
    {
        if (nums_set.find(num2[i]) != nums_set.end())
        {
            result.insert(num2[i]);
        }
    }
    return vector<int>(result.begin(), result.end());
}

//int main()
//{
//    vector<int>num1;
//    num1.push_back(2);
//    num1.push_back(2);
//    num1.push_back(3);
//    num1.push_back(4);
//    num1.push_back(3);
//    num1.push_back(6);
//    num1.push_back(2);
//    num1.push_back(2);
//
//    vector<int>num2;
//    num2.push_back(3);
//    num2.push_back(3);
//    num2.push_back(1);
//
//    vector<int>ret = intersection(num1, num2);
//    sort(ret.begin(), ret.end());
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}
