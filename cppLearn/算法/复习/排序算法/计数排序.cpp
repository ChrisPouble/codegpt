#include <iostream>
#include <vector>
using namespace std;

vector<int> JiShuSort(vector<int> vec)
{
    vector<int> v;
    v.resize(100);
    for (int i = 0; i < vec.size(); i++)
    {
        v[vec[i]]++;
    }

    return v;
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
//    vector<int> ret = JiShuSort(vec);
//    for (int i = 0; i < 100; i++)
//    {
//        while (ret[i]--)
//        {
//            cout << i << " ";
//        }
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}