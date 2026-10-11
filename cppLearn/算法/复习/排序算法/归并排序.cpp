#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> t;
int ans = 0; //求逆序对的数量
vector<int> GuiBingSort(int left, int right)
{
    t.resize(v.size(), 0);
    if (left == right) return {};
    int mid = (left + right) / 2;
    GuiBingSort(left, mid);
    GuiBingSort(mid + 1, right);
    int i = left, j = mid + 1, k = left; //k要从left开始计数

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j]) t[k++] = v[i++];
        else
        {
            t[k++] = v[j++];
            ans += mid - i + 1;
        }
    }

    while (i <= mid) t[k++] = v[i++];
    while (j <= right) t[k++] = v[j++];

    for (int x = left; x <= right; x++) v[x] = t[x];
    return v;
}

//int main()
//{
//    v.push_back(5);
//    v.push_back(3);
//    v.push_back(11);
//    v.push_back(7);
//    v.push_back(2);
//    v.push_back(8);
//    v.push_back(12);
//    v.push_back(1);
//    vector<int> ret = GuiBingSort(0, v.size() - 1);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}