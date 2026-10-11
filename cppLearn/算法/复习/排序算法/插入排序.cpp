#include <iostream>
#include <vector>
using namespace std;

vector<int> ChaRuSort(vector<int> vec)
{
    int j, k;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0) continue;
        for (j = i - 1; j >= 0; j--)
            if (vec[j] < vec[i]) break;
        if (j != i - 1)
        {
            int temp = vec[i];
            for (k = i - 1; k > j; k--)
                vec[k + 1] = vec[k];
            vec[k + 1] = temp;
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
//    vector<int> ret = ChaRuSort(vec);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}