#include <iostream>
#include <vector>
using namespace std;

vector<int> MaoPaoSort(vector<int> vec)
{
    bool ok;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        ok = true;
        for (int j = 0; j < vec.size() - 1 - i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                ok = false;
            }
        }

        if (ok == true) return vec;
    }

    return vec;
}

//int main()
//{
//    vector<int> vec;
//    vec.push_back(5);
//    vec.push_back(3);
//    vec.push_back(11);
//    vec.push_back(7);
//    vec.push_back(2);
//    vec.push_back(8);
//    vec.push_back(12);
//    vec.push_back(1);
//    vector<int> ret = MaoPaoSort(vec);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}