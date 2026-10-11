#include <iostream>
#include <vector>
using namespace std;

vector<int> XuanZeSort(vector<int> vec)
{
    int k;
    for (int i = 0; i < vec.size(); i++)
    {
        k = i;
        for (int j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[k]) k = j;
        if (k != i)
        {
            int temp = vec[i];
            vec[i] = vec[k];
            vec[k] = temp;
        }
    }

    return vec;
}

//int main()
//{
//    vector<int> vec;
//    vec.push_back(5);
//    vec.push_back(3);
//    vec.push_back(11);
//    vec.push_back(11);
//    vec.push_back(7);
//    vec.push_back(2);
//    vec.push_back(8);
//    vec.push_back(12);
//    vec.push_back(1);
//    vector<int> ret = XuanZeSort(vec);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}