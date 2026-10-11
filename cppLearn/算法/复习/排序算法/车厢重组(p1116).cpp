#include <iostream>
#include <vector>
using namespace std;

vector<int> vec4;
int p1116() 
{
    int count = 0;
    for (int i = 0; i < vec4.size() - 1; i++)
    {
        for (int j = 0; j < vec4.size() - i - 1; j++)
        {
            if (vec4[j] > vec4[j + 1])
            {
                swap(vec4[j], vec4[j + 1]);
                count++;
            }
        }
    }

    return count;
}

//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int t;
//        cin >> t;
//        vec4.push_back(t);
//    }
//
//    cout << p1116() << endl;
//    system("pause");
//    return 0;
//}