#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int foursum1(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4)
{
    int count = 0;
    for (int i = 0; i < num1.size(); i++)
    {
        for (int j = 0; j < num2.size(); j++)
        {
            for (int x = 0; x < num3.size(); x++)
            {
                for (int k = 0; k < num4.size(); k++)
                {
                    if (num1[i] + num2[j] + num3[x] + num4[k] == 0)
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int foursum2(vector<int>& num1, vector<int>& num2, vector<int>& num3, vector<int>& num4)
{
    unordered_map<int, int> result;

    for (int a : num1)
    {
        for (int b : num2)
        {
            result[a + b]++;
        }
    }

    int count = 0;
    for (int c : num3)
    {
        for (int d : num4)
        {
            if (result.find(0 - (c + d)) != result.end())
            {
                count += result[0 - (c + d)];
            }
        }
    }

    return count;
}

//int main()
//{
//    vector<int>num1;
//    num1.push_back(3);
//    num1.push_back(1);
//    num1.push_back(4);
//
//    vector<int>num2;
//    num2.push_back(-2);
//    num2.push_back(4);
//    num2.push_back(3);
//
//    vector<int>num3;
//    num3.push_back(-1);
//    num3.push_back(3);
//    num3.push_back(2);
//
//    vector<int>num4;
//    num4.push_back(3);
//    num4.push_back(-2);
//    num4.push_back(0);
//
//    int ret = foursum1(num1, num2, num3, num4);
//    cout << "ret = " << ret << endl;
//    system("pause");
//    return 0;
//}